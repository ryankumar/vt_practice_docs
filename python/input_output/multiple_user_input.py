#1. Two input at a time,input may be different datatype
'''
x , y =input("enter two values: ").split()
print("number of boys",x)
print("number of girls",y)
print()
'''
#2. Three input at a time
'''
x , y, z=input("enter three values: ").split()
print("age of boy",x)
print("weight of boy",y)
print("name of boy",z)
print()
'''

#3. taking two input at a time in differnt way
'''
x , y =input("enter two values: ").split()
print("number of boys are {} and number of girls are {}".format(x,y))
print()
'''

#4. taking two inputs at a time and type casting
'''
x,y=map(int, input("Enter a multiple value: ").split())
print("inputs are :",x,y)
'''


#5. taking multiple inputs at a time and type casting using list
'''
x=list(map(int, input("Enter a multiple value: ").split()))
print("inputs are :",x)
'''

"""
we can also write the above 5 format using list comprehension 
follow the below list comprehension

"""

# Python program showing 
# how to take multiple input 
# using List comprehension 
  
# taking two input at a time 
x, y = [int(x) for x in input("Enter two value: ").split()] 
print("First Number is: ", x) 
print("Second Number is: ", y) 
print() 
    
# taking three input at a time 
x, y, z = [int(x) for x in input("Enter three value: ").split()] 
print("First Number is: ", x) 
print("Second Number is: ", y) 
print("Third Number is: ", z) 
print() 
      
# taking two inputs at a time 
x, y = [int(x) for x in input("Enter two value: ").split()] 
print("First number is {} and second number is {}".format(x, y)) 
print() 
        
# taking multiple inputs at a time  
x = [int(x) for x in input("Enter multiple value: ").split()] 
print("Number of list is: ", x)  







