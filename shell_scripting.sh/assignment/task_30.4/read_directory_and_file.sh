#! /bin/bash
# Read a directory and read all files in that directory and total count of the keyword ( user given ) occurrences in all files.

count=0
total=0
DIR=$1
cd $DIR
files=$(ls)
echo "files in $DIR are $files"
echo -n "enter the keyword want to search :"
read str
for file in $files
do
   if [[ -f $file ]];then
	count=$(grep -c $str $file)
        echo "$file count :$count "
   fi
total=`expr $total + $count`
count=0
done 
echo "Total count= $total"

