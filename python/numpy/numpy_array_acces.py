#!/usr/bin/env python
# coding: utf-8

# # Basic Array Operations

# In[7]:


import numpy as np

# Defining Array 1
a = np.array([[1, 2],
              [3, 4]])
 
# Defining Array 2
b = np.array([[4, 3],
              [2, 1]])

# Adding 1 to every element
print ("Adding 1 to every element:", a + 1)

 
# Subtracting 2 from each element
print ("\nSubtracting 2 from each element:", b - 2)

# sum of array elements
# Performing Unary operations
print ("\nSum of all array "
       "elements: ", a.sum())

# Adding two arrays
# Performing Binary operations
print ("\nArray sum:\n", a + b)

# multiplying two arrays
# Performing Binary operations
print ("\nArray sum:\n", a * b)


# # Data Types in Numpy

# In[14]:


import numpy as np
x = np.array([1, 2])  
print("Integer Datatype: ")
print(x.dtype)         

x = np.array([1.0, 2.0]) 
print("\nFloat Datatype: ")
print(x.dtype)

x = np.array([1, 2] ,dtype = np.int64 )  
print("\nForcing a Datatype: ")
print(x.dtype)


#  # Math Operations on DataType array

# In[18]:


import numpy as np

arr1=np.array([[4,7] ,[2,6]] , dtype=np.float64)
arr2=np.array([[3,6],[2,8]] ,dtype=np.float64)

# Addition of two Arrays
Sum=np.add(arr1,arr2)
print("sum of two arrays ")
print(Sum)

# Addition of all Array elements
# using predefined sum method
Sum1= np.sum(arr1)
print("sum of array elements: ")
print(Sum1)

Sqrt =np.sqrt(arr1)
print("Square root of array elements")
print(Sqrt)

# Transpose of Array
# using In-built function 'T'
Trans_arr = arr1.T
print("\nTranspose of Array: ")
print(Trans_arr)

