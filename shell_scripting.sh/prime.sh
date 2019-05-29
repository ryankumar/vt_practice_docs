# find out the prime num with in range : 1 to 20

echo "enter two nums"
read num1
read num2
var=1
isprime()
{
	for((i=2 ; i<= ($1/2) ;i++))
	do
		rem=$(( $1 % $i))
		if [ $rem -eq 0 ]
		then
			return 0
		fi
	done
	return 1

}

while [ $num1 -ne $num2 ]
do
	isprime $num1
	var=$?
	if [ $var -eq 0 ]
	then
		echo "$num1 is not a prime number"
	else
		echo "$num1 is a prime number "

	fi
	((num1++))
done


