#! /bin/bash

file="./shell_class/a.sh"
echo "0" > $file

((count++))
echo $count > $file

echo "madhab" >> $file
((count++))
echo $count >> $file

count=`cat $file`
echo $count



