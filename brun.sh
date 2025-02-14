#!/bin/bash

# this script is for quickly building and running this project

# if no arguments are given, then only run
BUILD_AND_RUN=false
CLEAN_BUILD=false
RUN_TESTS=false
JUST_RUN=true

# handle arguments
while getopts "bct" opt; do
	case $opt in
		b)
			BUILD_AND_RUN=true
			JUST_RUN=false
			;;
		c)
			CLEAN_BUILD=true
			JUST_RUN=false
			;;
		t)
			RUN_TESTS=true
			JUST_RUN=false
			;;
		*)
			echo "Usage: $0 [-b] [-c] [t]"
			exit 1
			;;
	esac
done

if $BUILD_AND_RUN || $CLEAN_BUILD; then

	if $BUILD_AND_RUN; then
		# check if build folder exists, create it if necessary
		if [ ! -d "build" ]; then
			echo "creating build folder.."
			mkdir build || { echo "unable to create build folder, exiting"; exit 1; }
		else
			echo "build folder already exists"
		fi
	fi

	if $CLEAN_BUILD; then

		# remove build folder
		rm -rf build

		# check if build folder exists, remove it if it does
		if [ ! -d "build" ]; then
			echo "creating build folder.."
			mkdir build || { echo "unable to create build folder, exiting"; exit 1; }
		else
			echo "build folder already exists"
		fi
	fi

	# move to build folder
	cd build || { echo "unable to move to build folder, exiting"; exit 1; }

	# remove old executable if it exists
	rm -f src/neuralanimals

	# run cmake and make
	cmake .. || { echo "cmake failed, exiting"; exit 1; }
	make || { echo "make failed, exiting"; exit 1; }

	# cmake creates the executable here
	cd src

	# give priviledges and run executable
	chmod +x neuralanimals || { echo "unable to give priviledges, exiting"; exit 1; }
	./neuralanimals || { echo "unable to run program, exiting"; exit 1; }
fi

if $RUN_TESTS; then
	# move to build folder
	cd build/tests || { echo "unable to move to build folder, exiting"; exit 1; }

	# give priviledges and run executable
	chmod +x neuralanimals_tests || { echo "unable to give priviledges, exiting"; exit 1; }
	./neuralanimals_tests || { echo "unable to run tests, exiting"; exit 1; }
fi

if $JUST_RUN; then
	# move to build folder
	cd build/src || { echo "unable to move to build folder, exiting"; exit 1; }

	# run executable
	./neuralanimals || { echo "unable to run program, exiting"; exit 1; }
fi





