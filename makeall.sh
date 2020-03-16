#!/bin/bash
for i in `find $PWD -type d`
do
	cd $i
	if [ -f makefile ]
	then
		echo "RUNNING makefile in $i"
		if [ $# -eq 1 ]
		then
			make $1
		else
			make
		fi
	fi
done
