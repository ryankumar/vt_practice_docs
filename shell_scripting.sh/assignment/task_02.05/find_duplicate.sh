a=(aa ac aa ad ab ad)
b=()
for i in ${a[@]}
do
	count=$(grep -o $i <<< ${a[*]} | wc -l)
	if [ $count -ge 2 ] && [[ "${b[*]}" != *"$i"* ]]
	then
		b+=("$i")
	fi
done
echo " duplicate elements are :${b[@]} "
