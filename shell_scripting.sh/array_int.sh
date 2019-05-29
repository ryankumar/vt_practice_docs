arr=(11 12 13 14 15)
i=0
# using while
echo -n "using while loop    "
while [ $i -lt ${#arr[@]} ]
do
echo -n "${arr[$i]}  "
i=`expr $i + 1`
done

echo -e

#using forloop
echo -n "using for loop   "
for i in ${arr[*]}
do
echo -n "$i  "
done

echo -e

#replace value
echo "replace value 1 with 2  : ${arr[@]/1/2}"
echo "replace all 1 with 2  : ${arr[@]//1/2}"
echo "replace value 1 with 10  : ${arr[@]/1/10}"
echo "replace all 1 with 10  : ${arr[@]//1/10}"
