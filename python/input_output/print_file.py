#!/usr/bin/env python
# coding: utf-8

# In[25]:


import sys
print("geeksforgeeks ", file =sys.stderr)

sample =open("samplefile.txt",'w')
print("geeksforgeeks", file =sample)
sample.close()


# In[26]:


# print integer and float value 
print ("Geeks :%d , portal : %f" %(1,05.333))
# print integer value 
print("Total students :%d, Boys :%d" %(240,120))
# print octal value 
print("%o" %(31))
# print exponential value 
print("%10.3E" %(356.089777))


# In[29]:



# Python program showing  
# use of format() method 
  
# using format() method 
print('I love {}  "{}!"'.format('Geeks', 'Geeks')) 
  
# using format() method and refering  
# a position of the object 
print('{0} and {1}'.format('Geeks', 'Portal')) 
  
print('{1} and {0}'.format('Geeks', 'Portal')) 


# In[30]:


# Python program showing  
# a use of format() method 

# combining positional and keyword arguments 
print("Number one portal is {0}, {1}, and {other}".format("Geeks", "for", other="geeks"))

# using format() method with number  
print("Geeks :{0:2d}, portal :{1:8.2f}".format(12, 00.546, ))

# Changing positional argument 
print("second argument: {1:3d}, first one: {0:7.2f}".format(47.42, 11))

print("Geeks: {a:5d}, portal: {b:8.2f}".format(a =453 ,b=59.058))


# In[31]:



# Python program to  
# show format () is  
# used in dictionary 
  
tab = {'geeks': 4127, 'for': 4098, 'geek': 8637678} 
  
# using format() in dictionary 
print('Geeks: {0[geeks]:d}; For: {0[for]:d}; '
    'Geeks: {0[geek]:d}'.format(tab)) 
  
data = dict(fun ="GeeksForGeeks", adj ="Portal") 
  
# using format() in dictionary 
print("I love {fun} computer {adj}".format(**data)) 


# In[33]:



# Python program to 
# format a output using 
# string() method 
  
cstr = "I love geeksforgeeks"
    
# Printing the center aligned   
# string with fillchr  
print ("Center aligned string with fillchr: ")  
print (cstr.center(40, '#'))  
  
# Printing the left aligned   
# string with "-" padding   
print ("The left aligned string is : ")  
print (cstr.ljust(40, '-')) 
  
# Printing the right aligned string  
# with "-" padding   
print ("The right aligned string is : ")  
print (cstr.rjust(40, '-')) 


# In[ ]:




