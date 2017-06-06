#!/bin/bash

if [ -e "$1" ]
then
	fgrep -io "$2" "$1" | wc -l
else
	echo "File not found" 1>&2
fi
