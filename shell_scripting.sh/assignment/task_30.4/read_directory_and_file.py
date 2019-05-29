# Read a directory and read all files in that directory and total count of the keyword ( user given ) occurrences in all files.
# A: Assume directory contains only regular files and there is no any other subdirectories . 

import os
def find_occurence():
    total=0
    path=input("enter the path for a directory :")
    team=input("Enter key name: ")
    filelist=os.listdir(path)
    for i in filelist :
        file_path=os.path.join(path+ i)
        file  = open(file_path, 'r').read()
        count = file.count(team)
        print("for file", i ," count: ",count)
        total=total+count
        count=0
    print("total count :", total)

find_occurence()
