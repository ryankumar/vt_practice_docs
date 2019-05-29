echo -n "Enter file name : "
read file
 
# find out if file has write permission or not
if [ -w $file ]
then
echo "writable "
else
echo "No"
fi
