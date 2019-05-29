#!/usr/bin/env python
# coding: utf-8

# # Adding Elements to a Set

# In[1]:


set1 = set() 
# Adding element to the Set
set1.add(8) 
set1.add(9) 
set1.add(12) 
print("\nSet after Addition of Three elements: ") 
print(set1) 


# # Adding elements to the Set using Iterator 

# In[2]:


for i in range(1, 6): 
    set1.add(i) 
print("\nSet after Addition of elements from 1-5: ") 
set1.add(6)
print(set1) 


# # Adding Tuples to the Set

# In[3]:


set1.add((6,7)) 
print("\nSet after Addition of a Tuple: ") 
print(set1) 


# # Addition of elements to the Set using Update function 

# In[4]:


set1.update([10, 11]) 
print("\nSet after Addition of elements using Update: ") 
print(set1) 


# In[5]:


set1.update([0,7])
print("\nSet after Addition of elements using Update: ") 
print(set1) 


# # Removing elements from the Set
# '''
# Elements can be removed from the Set by using built-in remove() function but a KeyError arises if element doesn’t exist in the set. To remove elements from a set without KeyError, use discard(), if the element doesn’t exist in the set, it remains unchanged
# '''
# 

# In[6]:


set1 = set([1,4,3,6,5,7,2,8,9,12,10,11]) 
print("Intial Set: ") 
print(set1) 


# In[7]:


# Removing elements from Set 
# using Remove() method 
set1.remove(5) 
set1.remove(6) 
print("\nSet after Removal of two elements: ") 
print(set1) 


# In[8]:


# Removing elements from Set 
# using Discard() method 
set1.discard(8) 
set1.discard(9) 
print("\nSet after Discarding two elements: ") 
print(set1) 


# In[9]:


# Removing elements from Set 
# using iterator method 
for i in range(1, 5): 
    set1.remove(i) 
print("\nSet after Removing a range of elements: ") 
print(set1) 


# In[10]:


# Removing element from the  
# Set using the pop() method 
set1.pop() 
print("\nSet after popping an element: ") 
print(set1) 


# In[11]:


# Removing all the elements from  
# Set using clear() method 
set1.clear() 
print("\nSet after clearing all the elements: ") 
print(set1) 


# In[13]:


String = ('G', 'e', 'e', 'k', 's', 'F', 'o', 'r') 
print(String)
Fset1 = frozenset(String) 
print("The FrozenSet is: ") 
print(Fset1) 
  
# To print Empty Frozen Set 
# No parameter is passed 
print("\nEmpty FrozenSet: ") 
print(frozenset()) 


# # Inbuilt functions in set
# ### add() 	Adds an element to a set
# ### remove() 	Removes an element from a set. If the element is not present in the set, raise a KeyError
# ### clear() 	Removes all elements form a set
# ### copy() 	Returns a shallow copy of a set
# ### pop() 	Removes and returns an arbitary set element. Raise KeyError if the set is empty
# ### update() 	Updates a set with the union of itself and others
# ### union() 	Returns the union of sets in a new set
# ### difference() 	Returns the difference of two or more sets as a new set
# ### difference_update() 	Removes all elements of another set from this set
# ### discard() 	Removes an element from set if it is a member. (Do nothing if the element is not in set)
# ### intersection() 	Returns the intersection of two sets as a new set
# ### intersection_update() 	Updates the set with the intersection of itself and another
# ### isdisjoint() 	Returns True if two sets have a null intersection
# ### issubset() 	Returns True if another set contains this set
# ### issuperset() 	Returns True if this set contains another set
# ### symmetric_difference() 	Returns the symmetric difference of two sets as a new set
# ### symmetric_difference_update() 	Updates a set with the symmetric difference of itself and another
# 
# 
