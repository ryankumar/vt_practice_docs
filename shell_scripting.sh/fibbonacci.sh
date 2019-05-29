var=10
res=0
first=1
Second=0
fibb=1
while [ $var -gt 0 ]
do
	echo $fibb 
	((fibb= first + second))
	second=$first
	first=$fibb
	((var= var - 1)) 
done


