#!/usr/bin/env python
# coding: utf-8

#  # Array creation using array functions : array(data type, value list
#  

# In[1]:


import array

arr= array.array('i' ,[1,2,3])

# printing original array
print ("The new created array is : ",end="")
for i in range (0,3):
    print (arr[i], end=" ")
 
print ("\r")


#  # Array creation using numpy methods :
#     
# ### numpy.empty(shape, dtype = float, order = ‘C’) :
# ### Return a new array of given shape and type, with random values.

# In[ ]:


import numpy as geek
 
b = geek.empty(2, dtype = int)
print("Matrix b : \n", b)
 
a = geek.empty([2, 2], dtype = int)
print("\nMatrix a : \n", a)
 
c = geek.empty([3, 3])
print("\nMatrix c : \n", c)


# ### numpy.zeros(shape, dtype = None, order = ‘C’) : 
# ###      Return a new array of given shape and type,with zeros.

# In[33]:


import numpy as geek
 
b = geek.zeros(2, dtype = int)
print("Matrix b : \n", b)
 
a = geek.zeros([2, 2], dtype = int)
print("\nMatrix a : \n", a)
 
c = geek.zeros([3, 3])
print("\nMatrix c : \n", c)


# 
# ### numpy.reshape(array, shape, order = ‘C’) :
# ### Shapes an array without changing data of array.

# In[ ]:




import numpy as geek
 
array = geek.arange(8)
print("Original array : \n", array)
 
# shape array with 2 rows and 4 columns
array = geek.arange(8).reshape(2, 4)
print("\narray reshaped with 2 rows and 4 columns : \n", array)

# shape array with 4 rows and 2 columns
array = geek.arange(8).reshape(4 ,2)
print("\narray reshaped with 2 rows and 4 columns : \n", array)

# Constructs 3D array
array = geek.arange(8).reshape(2, 2, 2)
print("\nOriginal array reshaped to 3D : \n", array)


# ### arange([start,] stop[, step,][, dtype]) : 
# ### Returns an array with evenly spaced elements 
# ### as per the interval. The interval mentioned is 
# ### half opened i.e. [Start, Stop)

# In[ ]:




import numpy as geek
 
print("A\n", geek.arange(4).reshape(2, 2), "\n")
 
print("A\n", geek.arange(4, 10).reshape(2,3), "\n")
 
print("A\n", geek.arange(4, 20, 3).reshape(3,2), "\n")


# ### numpy.linspace(start, stop, num = 50, endpoint = True, retstep = False, dtype = None) 
# ### Returns number spaces evenly w.r.t interval. 
# ### Similiar to arange but instead of step it uses sample number

# In[ ]:




import numpy as geek
 
# restep set to True
print("B\n", geek.linspace(2.0, 3.0, num= 5,retstep=True), "\n")
 
# To evaluate sin() in long range 
x = geek.linspace(0, 2, 10)
print("using sin A\n", geek.sin(x))
print("without sin A\n",x)


# ### numpy.ndarray.flatten(order = ‘C’) : Return a copy of the array collapsed into one dimension.
# 
# ### order = 'C' for row major order
# ### order= 'F' for column major order

# In[32]:


import numpy as geek
 
array = geek.array([[1, 2], [3, 4]])
 
# using flatten method
array.flatten('C')
print(array)
 
#using fatten method 
array.flatten('F')
print(array)


# # Methods for array creation in Numpy
# 
# ### empty() 	Return a new array of given shape and type, without initializing entries
# ### empty_like() 	Return a new array with the same shape and type as a given array
# ### eye() 	Return a 2-D array with ones on the diagonal and zeros elsewhere.
# ### identity() 	Return the identity array
# ### ones() 	Return a new array of given shape and type, filled with ones
# ### ones_like() 	Return an array of ones with the same shape and type as a given array
# ### zeros() 	Return a new array of given shape and type, filled with zeros
# ### zeros_like() 	Return an array of zeros with the same shape and type as a given array
# ### full_like() 	Return a full array with the same shape and type as a given array.
# ### array() 	Create an array
# ### asarray() 	Convert the input to an array
# ### asanyarray() 	Convert the input to an ndarray, but pass ndarray subclasses through
# ### ascontiguousarray() 	Return a contiguous array in memory (C order)
# ### asmatrix() 	Interpret the input as a matrix
# ### copy() 	Return an array copy of the given object
# ### frombuffer() 	Interpret a buffer as a 1-dimensional array
# ### fromfile() 	Construct an array from data in a text or binary file
# ### fromfunction() 	Construct an array by executing a function over each coordinate
# ### fromiter() 	Create a new 1-dimensional array from an iterable object
# ### fromstring() 	A new 1-D array initialized from text data in a string
# ### loadtxt() 	Load data from a text file
# ### arange() 	Return evenly spaced values within a given interval
# ### linspace() 	Return evenly spaced numbers over a specified interval
# ### logspace() 	Return numbers spaced evenly on a log scale
# ### geomspace() 	Return numbers spaced evenly on a log scale (a geometric progression)
# ### meshgrid() 	Return coordinate matrices from coordinate vectors
# ### mgrid() 	nd_grid instance which returns a dense multi-dimensional “meshgrid
# ### ogrid() 	nd_grid instance which returns an open multi-dimensional “meshgrid
# ### diag() 	Extract a diagonal or construct a diagonal array
# ### diagflat() 	Create a two-dimensional array with the flattened input as a diagonal
# ### tri() 	An array with ones at and below the given diagonal and zeros elsewhere
# ### tril() 	Lower triangle of an array
# ### triu() 	Upper triangle of an array
# ### vander() 	Generate a Vandermonde matrix
# ### mat() 	Interpret the input as a matrix
# ### bmat() 	Build a matrix object from a string, nested sequence, or array

# In[ ]:




