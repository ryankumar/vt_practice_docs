#!/usr/bin/env python
# coding: utf-8

# In[1]:


Tuple1 = ('Geeks') 
n = 5
print("\nTuple with a loop") 
for i in range(int(n)): 
    Tuple1 = (Tuple1,) 
    print(Tuple1) 


# In[2]:


# Creating a Tuple with the 
# use of built-in function 
Tuple1 = tuple('Geeks') 
print("\nTuple with the use of function: ") 
print(Tuple1) 


# # Concatenation of Tuples

# In[4]:


# Concatenaton of tuples 
Tuple1 = (0, 1, 2, 3) 
Tuple2 = ('Geeks', 'For', 'Geeks') 
  
Tuple3 = Tuple1 + Tuple2 
# Printing first Tuple 
print("Tuple 1: ") 
print(Tuple1) 
  
# Printing Second Tuple 
print("\nTuple2: ") 
print(Tuple2) 
  
# Printing Final Tuple 
print("\nTuples after Concatenaton: ") 
print(Tuple3) 


# # Slicing of Tuple 

# In[5]:


Tuple1 = tuple('GEEKSFORGEEKS') 
  
# Removing First element 
print("Removal of First Element: ") 
print(Tuple1[1:]) 
  
# Reversing the Tuple  
print("\nTuple after sequence of Element is reversed: ") 
print(Tuple1[::-1]) 
  
# Printing elements of a Range 
print("\nPrinting elements between Range 4-9: ") 
print(Tuple1[4:9]) 


# # Deleting a Tuple

# In[6]:


Tuple1 = (0, 1, 2, 3, 4) 
del Tuple1 
  
print(Tuple1) 


# # Built-In Methods
# ## all() 	Returns true if all element are true or if tuple is empty
# ## any() 	return true if any element of the tuple is true. if tuple is empty, return false
# ## len() 	Returns length of the tuple or size of the tuple
# ## enumerate() 	Returns enumerate object of tuple
# ## max() 	return maximum element of given tuple
# ## min() 	return minimum element of given tuple
# ## sum() 	Sums up the numbers in the tuple
# ## sorted() 	input elements in the tuple and return a new sorted list
# ## tuple() 	Convert an iterable to a tuple.
# 

# In[ ]:




