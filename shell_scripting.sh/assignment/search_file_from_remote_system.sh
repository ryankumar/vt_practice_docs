#SSH into a remote desktop and look for a specific file which we don't where that file is exist on the remote desktop. If file is there then  we need to check the file is editable or not. If it is editable then we need to be copied  into your local machine. After that look for particular keyword in that file and replace with another keyword and matched lines should be write into a new file.


host=lajulson@192.168.4.241
file_name=$1
file="/home/lajulson/ -name '\\$file_name'"

if ssh $host find  $file > a.txt
then
	echo "File exists"
	var=$(cat a.txt)
	arr=(${var// / })
	echo "file paths are ${arr[@]}"
	file_path=${arr[0]}
	if ssh $host [ -w $file_path ]
	then
		echo "writable"
		rcp mahannee@192.168.4.132:$file_path .
		grep -wn 'count' file_op.sh > "new_file.txt"
		sed -i 's/count/num/g' "new_file.txt"
	else
		echo "not writable"
	fi
else
	echo "File does not exist"
fi

