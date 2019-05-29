#!/usr/bin/env python
# coding: utf-8

# In[7]:


import numpy as geek

a = geek.arange(12)
a = a.reshape(3,4)

print('Original array is:')
print(a)
print()

# Transpose of original array
b = a.T 

print("transpose of array",b)
print('Modified array is:')
 
# iterating  an array
for x in geek.nditer(a):
    print(x,end=" ")
    
print()
# iterarting a transpose array
print("modified transpose array is:")
for x in geek.nditer(b):
    print(x,end=" ")
print()
    


# # Controlling Iteration Order: 

# In[9]:


import numpy as geek 

a = geek.arange(12) 
a = a.reshape(3,4) 
print('Original array is:') 
print(a)
print()
print('Modified array in C-style order:')

# iterating an array in a given
# order ; C for row order
for x in geek.nditer(a, order = 'C'): 
    print(x,end=" ")
print()

print('Modified array in F-style order:')
# iterating an array in a given
# order ; F for column order
for x in geek.nditer(a, order = 'F'): 
    print(x,end=" ")
print()


# ### Modifying Array Values: 
# ### op_flags = read-only ,write-only ,read-write

# In[17]:


import numpy as geek
a = geek.arange(12)
a = a.reshape(3,4)
print('Original array is:')
print(a)
print()

# modifying array values
for x in geek.nditer(a, op_flags = ['readwrite']):
    x[...] = 5*x
print('Modified array is:')
print(a)


# ### External Loop: Causes values given to be one-dimensional arrays with multiple values instead of zero-dimensional array

# In[23]:


import numpy as geek
a = geek.arange(12)
a = a.reshape(3,4) 
print('Original array is:') 
print(a) 
print()  
 
print('Modified array is:') 
for x in geek.nditer(a, flags = ['external_loop'], order = 'C'):
    print(x)

print('Modified array is enabling c_index:')
it = geek.nditer(a, flags=['c_index'])
while not it.finished:
      print("%d <%d>" % (it[0], it.index), end=" ")
      it.iternext()
print()
print('Modified array is enabling f_index:')
it = geek.nditer(a, flags=['f_index'])
while not it.finished:
      print("%d <%d>" % (it[0], it.index), end=" ")
      it.iternext()


# # Broadcasting Iteration:

# In[26]:


import numpy as geek
a = geek.arange(12)
a = a.reshape(3,4) 
print('First array is:') 
print(a)
print()  

print('Second array is:') 
b = geek.array([5, 6, 7,8], dtype = int) 
print(b)  
print() 

print('Modified array is:')
for x,y in geek.nditer([a,b]): 
    print("%d:%d" % (x,y))


# In[ ]:




