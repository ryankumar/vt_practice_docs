#Read the all files in a user given directory recursively.
print_files()
{
	
	for file in *
	do
	 if [ -d $file ]
	  then
		echo -e
		echo -n "files in $file :" 
		( cd $file && print_files )
	  fi
	  echo -n "$file "
	done

}

cd $1
print_files
echo -e
