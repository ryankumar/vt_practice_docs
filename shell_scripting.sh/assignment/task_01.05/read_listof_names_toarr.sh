# You are given a list of names.Your task is to read them into an array and then filter out (remove) all the names containing the user given letter

#! /bin/bash
arr=()
read -p "enter names except -E(end of loop) :" var
until [ "$var" = "-E" ];do
arr+=("$var")
read -p "enter names except -E(end of loop) :" var
done 

echo -n "names in arr :" ${arr[@]}
echo -e
read -p "enter a letter to search related names :" alpha

echo -n "names :"
for i in ${arr[@]}
do
echo $i | grep "$alpha" >> /dev/null 2>&1 
if [ $? -eq "0" ]; then
echo -n "$i "
fi
done
echo -e
