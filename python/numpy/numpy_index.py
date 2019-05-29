#!/usr/bin/env python
# coding: utf-8

# # Why do we need NumPy ?

# In[ ]:


# example 1
# Python program to demonstrate a need of NumPy
# we can't multiply each element by using list,error .
list1 = [1, 2, 3, 4 ,5, 6]
list2 = [10, 9, 8, 7, 6, 5]
 
# Multiplying both lists directly would give an error.
print(list1*list2)


# In[3]:


# Hence we are using numpy
# Python program to demonstrate the use of NumPy arrays

import numpy as np
 
list1 = [1, 2, 3, 4, 5, 6]
list2 = [10, 9, 8, 7, 6, 5]
 
# Convert list1 into a NumPy array
a1 = np.array(list1)
 
# Convert list2 into a NumPy array
a2 = np.array(list2)
 
print(a1*a2)


# # Indexing using index arrays

# In[9]:


import numpy as np

a = np.arange(10, 1, -2) 
print("\n A sequential array with a negative step: \n",a)

newarr = a[np.array([3, 1, 2 ])]
print("\n Elements at these indices are:\n",newarr)


# # Basic Slicing and indexing

# In[10]:


import numpy as np

# Arrange elements from 0 to 19
a = np.arange(20)
print("\n Array is:\n ",a)

# a[start:stop:step]
print("\n a[-8:17:1]  = ",a[-8:17:1]) 
 
# The : operator means all elements till the end.
print("\n a[10:]  = ",a[10:])


# # Python program for basic slicing and indexing

# In[14]:


import numpy as np
 
# A 2-Dimensional array
a = np.array([[0, 1, 2, 3, 4, 5] ,
              [6, 7, 8, 9, 10, 11] ,
              [12, 13, 14, 15, 16, 17] ,
              [18, 19, 20, 21, 22, 23] ,
              [24, 25, 26, 27, 28, 29] ,
              [30, 31, 32, 33, 34, 35]])
print("\n Array is:\n ",a)
 
# slicing and indexing
print("\n a[0, 3:5]  = ",a[0, 3:5]) 
 
print("\n a[4:, 4:]  = ",a[4:, 4:]) 
 
print("\n a[:, 2]  = ",a[:, 2]) 
 
print("\n a[2::2, ::2]  = ",a[2::2, ::2]) 
             


# ### Python program for indexing using  basic slicing with ellipsis

# In[15]:


import numpy as np
 
# A 3 dimensional array.
b = np.array([[[1, 2, 3],[4, 5, 6]],
              [[7, 8, 9],[10, 11, 12]]])
 
print(b[...,1]) #Equivalent to b[: ,: ,1 ]


# ### Combining advanced and basic indexing

# In[16]:


import numpy as np
 
a = np.array([[0 ,1 ,2],[3 ,4 ,5 ],
              [6 ,7 ,8],[9 ,10 ,11]])
 
print(a[1:2 ,1:3 ])
print(a[1:2 ,[1,2]])


# ### You may wish to select numbers greater than 50

# In[18]:


import numpy as np
 
a = np.array([10, 40, 80, 50, 100])
print(a[a>50])


# ### You may wish to square the multiples of 40 

# In[19]:


import numpy as np
 
a = np.array([10, 40, 80, 50, 100])
print(a[a%40==0]**2)


# ### You may wish to select those elements whose sum of row is a multiple of 10.
# ### sum(0) : sum of column elements , sum(1) or sum(-1) : sum of rows
# 

# In[24]:


import numpy as np
 
b = np.array([[5, 5],[16,4],[5, 4]])
sumrow = b.sum(-1)
print("sumrow:",sumrow)
print(b[sumrow%10==0])


# In[ ]:




