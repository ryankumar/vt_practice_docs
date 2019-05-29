#! /bin/bash
#to declare static array
arr=(madhaba pranali udaya akbara)

#to print all elements of array
echo "using \${arr[@]}     :${arr[@]}"
echo "using \${arr[*]}     :${arr[*]}"
echo "using \${arr[@]:0}   :${arr[@]:0}"
echo "using \${arr[*]:0}   :${arr[*]:0}"
echo "using \${arr[@]:1}   :${arr[@]:1}"
echo "using \${arr[@]:2}   :${arr[@]:2}"
echo "using \${arr[@]:3}   :${arr[@]:3}"
echo -e  
#To print 1st element or any single element
echo "using \${arr[0]}     :${arr[0]}"
echo "using \${arr[1]}     :${arr[1]}"
echo "using \${arr}        :${arr}"
echo "using \${arr[@]:0:1} :${arr[@]:0:1}"
echo "using \${arr[@]:0:2} :${arr[@]:0:2}"
echo "using \${arr[@]:1:1} :${arr[@]:1:1}"
echo -e

#to print length of a perticular array
echo "length of perticular array"
echo "length of array \${#arr[@]}                    :${#arr[@]}"
echo "length of any element of array \${#arr[0]}     :${#arr[0]}"

#to search and replace
echo "replace only a with u once from whole array : ${arr[@]/a/u}"
echo "replace all a with u from whole array       : ${arr[@]//a/u}"
echo "replace multiple char with u from array     : ${arr[@]//[mpuad]/u}"
echo "replace multiple char with un from array     : ${arr[@]//[mpuad]/un}"

