#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <word> <file1> [file2 ...]"
	exit 1
fi

# Extract the word to be deleted
word="$1"
shift

# Process each file
for file in "$@"; do
	# Check if the file exists
if [ ! -e "$file" ]; then
 echo "File not found: $file"
	continue
fi

	# Use sed to delete lines containing the specified word
	sed -i "/$word/d" "$file"
	echo "Lines containing '$word' deleted from $file"
	done

iecho "Deletion complete."
