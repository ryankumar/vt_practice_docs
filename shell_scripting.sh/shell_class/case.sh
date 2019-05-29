echo "hello"
echo `expr 1 + 2 `

case $1 in
   car) echo "For $1 Rs.20 per k/m";;
   van) echo "For $1 Rs.10 per k/m";;
   jeep) echo "For $1 Rs.5 per k/m";;
   bicycle) echo "For $1 20 paisa per k/m";;
   *) echo "Sorry, I can not gat a $1 for you";;
esac

demo()
{
echo `expr $1 $2 $3` 
echo $4
}
demo 1 + 3
demo 3 - 1 12

echo "*********"

. ./big.sh
echo "adsd  $v"
demo 1	2
