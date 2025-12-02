#!/bin/bash

## Assignment 1 finder script

 #   Accepts the following runtime arguments: the first argument is a path to a directory on the filesystem, referred to below as filesdir; the second argument is a text string which will be searched within these files, referred to below as searchstr

#    Exits with return value 1 error and print statements if any of the parameters above were not specified

#    Exits with return value 1 error and print statements if filesdir does not represent a directory on the filesystem

#    Prints a message "The number of files are X and the number of matching lines are Y" where X is the number of files in the directory and all subdirectories and Y is the number of matching lines found in respective files, where a matching line refers to a line which contains searchstr (and may also contain additional content).

if [ $# -ne 2 ]
then
	echo "Please invoke correctly"
	exit 1
fi


# directory to search 
filesdir=$1

# string I am searching for
searchstr=$2

if [ ! -d ${filesdir} ]
then
	echo "Directory not found"
	exit 1
fi

pushd ${filesdir}

files_with_matches=$(grep -l -r ${searchstr} | wc -l)
total_matches=$(grep -r ${searchstr} | wc -l)

popd

echo "The number of files are ${files_with_matches} and the number of matching lines are ${total_matches}"

exit 0