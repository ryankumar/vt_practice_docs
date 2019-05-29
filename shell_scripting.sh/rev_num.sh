#reverse a num and return same
# echo $rev returns the value to calling function 
echo " enter a num : "
read num
rev=0
revers()
{
	temp=$1
	while [ $temp -ne 0 ] 
	do
		rem=`expr $temp % 10`
		rev=$((rev * 10 + rem ))
		temp=$((temp / 10))
	done
	echo $rev
#	return $rev
}

var=$(revers $num)
#var=`expr $var + 1`
echo "revers num is $var"
if [ $var -eq $num ]
then
	echo "Number $num is pallindrom "
else
	echo "$num is not pallindrom"
fi
