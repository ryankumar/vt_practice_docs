# The file will have the data like below. Your task is to identify the performance grade for each student. If the average of the three scores is 80 or more, the grade is 'A'. If the average is 60 or above, but less than 80, the grade is 'B'. If the average is 50 or above, but less than 60, the grade is 'C'. Otherwise the grade is 'FAIL'. 

#! /bin/bash
i=0
file="student_datasheet.txt"
while read line
do
	if [ $i -gt "0" ]
	then
		arr=(${line// / })
		sum=`expr ${arr[1]} + ${arr[2]} + ${arr[3]}`
		avg=`expr $sum / 3`
		if [ $avg -ge "80" ]
		then
			echo " ${arr[0]} secured grade 'A'"
		elif [ $avg -ge "60" ] && [ $avg -lt "80" ]
		then
			echo " ${arr[0]} secured grade 'B'"
		elif [ $avg -ge "50" ] && [ $avg -lt "60" ]
		then
			echo " ${arr[0]} secured grade 'C'"
		else
			echo " ${arr[0]} got failed "
		fi
	fi
	i=$((i + 1 ))

done< $file

