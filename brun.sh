#!/bin/bash

# this script is for quickly building and running this project

# if no arguments are given, then only run
BUILD=false
CLEAN_BUILD=false
RUN_TESTS=false
RUN_APP=false

# handle arguments
while getopts "bctr" opt; do
	case $opt in
		b)
			BUILD=true
			;;
		c)
			CLEAN_BUILD=true
			;;
		t)
			RUN_TESTS=true
			;;
		r)
			RUN_APP=true
			;;
		*)
			echo "Usage: $0 [-b] [-c] [t]"
			exit 1
			;;
	esac
done

# no options given
if [ $OPTIND -eq 1 ]; then
	# move to build folder
	cd build/src || { echo "unable to move to build folder, exiting"; exit 1; }

	# run executable
	./neuralanimals || { echo "unable to run program, exiting"; exit 1; }
fi

if $BUILD || $CLEAN_BUILD; then

	if $BUILD; then
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

	if $RUN_APP; then
		./neuralanimals || { echo "unable to run program, exiting"; exit 1; }
	fi

	if $RUN_TESTS; then
	# move to build folder
	cd ../tests || { echo "unable to move to build folder, exiting"; exit 1; }

	# give priviledges and run executable
	chmod +x neuralanimals_tests || { echo "unable to give priviledges, exiting"; exit 1; }
	./neuralanimals_tests || { echo "unable to run tests, exiting"; exit 1; }
	fi
fi





