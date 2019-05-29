#! /bin/bash

def main() :
    count=0
    fd=open("../1.c",'r')
    string=input("enter string : ")
    for line in fd:
        if string in line :
            count = count + 1
    print(count)

main()

