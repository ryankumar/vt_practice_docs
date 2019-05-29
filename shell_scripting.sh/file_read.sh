#! /bin/bash
<<comment
while read line
do
echo "$line"
done < $1
comment
#replace 0 with 1

while read line
do
echo "sed -i 's/0/1/g' $line"
done < $1
