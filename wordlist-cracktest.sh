#!/bin/bash
set ${1:-3} ${2:-pwd} ${3:-templist.txt}
echo Generating wordlist...
wordlist $1 > $3
echo Finding password...
cat $3 | grep $2
if test `echo $?` -eq 0
then
	echo FOUND PASSWORD!
	exit
else
	echo DIDN\'T FIND PASSWORD!
	exit
fi
