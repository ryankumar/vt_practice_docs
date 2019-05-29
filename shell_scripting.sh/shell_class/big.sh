v=100
read a 
read b
read c
if [ a > b ]
then 
big=$a
if [ big > c ]
then
echo " $a is the bigger "
else
echo " $c is the bigger "
fi
else
big=$b
if [ big > c ]
then
echo " $b is the bigger "
else
echo " $c is the bigger "
fi
fi

demo()
{
echo "sdsdsdsds"
}


