#!/bin/bash

# this script is for quickly building and running this project


# check if build folder exists, create it if necessary
if [ ! -d "build" ]; then
	echo "creating build folder.."
	mkdir build || { echo "unable to create build folder, exiting"; exit 1; }
else
	echo "build folder already exists"
fi

# move to build folder
cd build/src || { echo "unable to move to build folder, exiting"; exit 1; }

# remove old executable if it exists
rm -f neuralanimals

# run cmake and make
cmake .. || { echo "cmake failed, exiting"; exit 1; }
make || { echo "make failed, exiting"; exit 1; }

# give priviledges and run executable
chmod +x neuralanimals || { echo "unable to give priviledges, exiting"; exit 1; }
./neuralanimals || { echo "unable to run program, exiting"; exit 1; }



