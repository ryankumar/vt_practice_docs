#!/usr/bin/env python
# coding: utf-8

# # Basic numpy array craetion

# In[1]:


import numpy as np
arr=np.array([1,2,3])
print(arr)


# In[2]:


# Creating a rank 2 Array
arr = np.array([[1, 2, 3],
                [4, 5, 6]])
print("Array with Rank 2: \n", arr)


# In[5]:


# Creating an array from tuple
arr = np.array((1, 3, 2))
print("\nArray created using "
      "passed tuple:\n", arr)
arr[2]=3
print(arr)


#  # Accessing the array Index

# In[8]:


# Initial Array
arr = np.array([[-1, 2, 0, 4],
                [4, -0.5, 6, 0],
                [2.6, 0, 7, 8],
                [3, -7, 4, 2.0]])
print("Initial Array: ")
print(arr)


# # Printing a range of Array with the use of slicing method
# 
# # Note:
# ### (:) means conteneous and (::) means alternate of that number

# In[18]:


sliced_arr = arr[:2, :2]
print ("Array with first 2 rows and"
    " 1st two columns:\n", sliced_arr)

sliced_arr = arr[:2, :4]
print ("Array with first 2 rows and"
    " 4 columns:\n", sliced_arr)

sliced_arr = arr[:2, ::2]
print ("Array with first 2 rows and"
    " alternate two columns:\n", sliced_arr)

sliced_arr = arr[:2, ::3]
print ("Array with first 2 rows and"
    "columns of difference 3:\n", sliced_arr)


# # Printing elements at specific Indices

# In[24]:


Index_arr = arr[[1, 1, 0, 3], 
                [3, 2, 1, 0]]
print ("\nElements at indices (1, 3), "
    "(1, 2), (0, 1), (3, 0):\n", Index_arr)

Index_arr = arr[[1, 1],[3,2]]
print ("\nElements at indices (1, 3), "
    "(1, 2):\n", Index_arr)

Index_arr = arr[1, 1]
print ("\nElements at indices (1, 1):\n", Index_arr)


# In[ ]:




