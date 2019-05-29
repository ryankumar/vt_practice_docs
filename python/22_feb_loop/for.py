for i in range(1,13):
    print(i," times 12 is ",i*12)

print("all odd numbers: ")
for i in range(1,13,2):
    print(i,"times 12 is",i*12)

print("all even numbers: ")
for i in range(2,13,2):
    print(i,"times 12 is",i*12)


print("we can write in this way also : ")
for i in [1,2,3,4,5,6,7,8,9,10,11,12] :
    print(i,"times 12 is ",i*12)

print("another way of for loop is: ")
for i in (1,2,3,4,5,6,7,8,9,10,11,12) :
    print(i,"times 12 is ",i*12)

print("by using {1,2,3,4} in for loop ")
for i in {1,2,3,4}:
    print(i,"times 12 is",i*12)

#{ } is called set , when we enter some unsorted data then it produces output in ascending sorted order
#above output and below output is same
print("by using {4,2,3,1} in for loop ")
for i in {4,2,3,1}:                 
    print(i,"times 12 is",i*12)

print("by using \" \" in for loop ")
for i in "123456789":
    print(i,"times 12 is",int(i)*12)

print("by using \" \" in for loop ")
for i in "abcdefghij":
    print(i)

real_name={"Benny": "Benjamin Everard", "Alex":"Alexander Bradbury" }
for key,value in real_name.items() :
    print("The real name of "+ key + " is " + value)
