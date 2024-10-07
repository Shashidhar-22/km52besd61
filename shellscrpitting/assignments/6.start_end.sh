#!/bin/sh
echo "Enter the filename"
read filename
echo "Enter the starting line number"
read start
echo "Enter the endingnline number"
read ending
sed -n $start,$ending\p $filename | cat > newline
cat newline
