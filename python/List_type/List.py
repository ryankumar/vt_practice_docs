#!/usr/bin/env python
# coding: utf-8

# 
# # Creating a List 

# In[ ]:


List = [] 
print("Intial blank List: ") 
print(List) 


#  ### Creating a List with  the use of a String 

# In[ ]:


List = ['GeeksForGeeks'] 
print("\nList with the use of String: ") 
print(List) 


# ### Creating a List with the use of multiple values 

# In[ ]:


List = ["Geeks", "For", "Geeks", 'always'] 
print("\nList containing multiple values: ") 
print(List[0])  
print(List[2]) 
print(List[-1]) 


# ### Creating a Multi-Dimensional List (By Nesting a list inside a List) 

# In[ ]:


List = [['Geeks', 'For'] , ['Geeks']] 
print("\nMulti-Dimensional List: ") 
print("List :",List)
print("List[0] :",List[0])
print("List[0][0] :",List[0][0])
print("List[1] :",List[1])


#  ## append() and extend() methods can only add elements at the end.

# In[ ]:


List = [] 
print("Intial blank List: ") 
print(List) 
  
# Addition of Elements  
# in the List 
List.append(1) 
List.append(2) 
List.append(4) 
print("\nList after Addition of Three elements: ") 
print(List) 

List.append((5, 6))
print("\nList after Addition of a Tuple: ") 
print(List) 


# # Addition of List to a List 
# 

# In[ ]:


List2 = ['For', 'Geeks'] 
List.append(List2) 
print("\nList after Addition of a List: ") 
print(List) 


# ### Addition of Element at specific Position (using Insert Method) 

# In[ ]:


List.insert(3, 12) 
List2.insert(0, 'Geeks') 
print("\nList after performing Insert Operation: ") 
print(List) 


# ### Addition of multiple elements to the List at the end (using Extend Method) 

# In[ ]:


List.extend([8, 'Geeks', 'Always']) 
print("\nList after performing Extend Operation: ") 
print(List) 


# ## Python program to demonstrate Removal of elements in a List 

# In[ ]:


List.remove(8) 
List.remove('Geeks')
print("\nList after Removal of two elements: ") 
print(List) 


# ### Removing element from the list using the pop() method 

# In[ ]:


List.pop() 
print("\nList after popping an from last element: ") 
print(List) 

List.pop(2)
print("\nList after popping a specific element from specific position: ") 
print(List) 


# In[ ]:


Sliced_List = List[::-2] 
print("\nPrinting List in reverse: ") 
print(Sliced_List) 


# ## Some Library for List
# 
# ### Append() 	Add an element to the end of the list
# ### Extend() 	Add all elements of a list to the another list
# ### Insert() 	Insert an item at the defined index
# ### Remove() 	Removes an item from the list
# ### Pop() 	    Removes and returns an element at the given index
# ### Clear() 	Removes all items from the list
# ### Index() 	Returns the index of the first matched item
# ### Count() 	Returns the count of number of items passed as an argument
# ### Sort() 	    Sort items in a list in ascending order
# ### Reverse() 	Reverse the order of items in the list
# ### copy() 	    Returns a copy of the list
# 
# ## Built-in functions with List

# ### round() 	Rounds off to the given number of digits and returns the floating point number
# ### reduce() 	apply a particular function passed in its argument to all of the list elements stores the intermediate result and only returns the final summation value
# ### sum() 	Sums up the numbers in the list
# ### ord() 	Returns an integer representing the Unicode code point of the given Unicode character
# ### cmp() 	This function returns 1, if first list is “greater” than second list
# ### max() 	return maximum element of given list
# ### min() 	return minimum element of given list
# ### all() 	Returns true if all element are true or if list is empty
# ### any() 	return true if any element of the list is true. if list is empty, return false
# ### len() 	Returns length of the list or size of the list
# ### enumerate() 	Returns enumerate object of list
# ### accumulate() 	apply a particular function passed in its argument to all of the list elements returns a list containing the intermediate results
# ### filter() 	tests if each element of a list true or not
# ### map() 	returns a list of the results after applying the given function to each item of a given iterable
# ### lambda() 	This function can have any number of arguments but only one expression, which is evaluated and returned.
# 
# 
# 
# 

# In[ ]:


print(round(15)) 
print(round(51.6))  
print(round(51.5))  
print(round(51.4))  

# returns integer value of character , ord never accept string like ord("AB")
value = ord("A") 
value1 = ord('A') 
print( value, value1 )

#enumerate 
l1 = ["eat","sleep","repeat"] 
s1 = "geek"
  
# creating enumerate objects 
obj1 = enumerate(l1) 
obj2 = enumerate(s1) 
  
print ("Return type:",type(obj1) )
print (list(enumerate(l1))) 
  
# changing start index to 2 from 0 
print (list(enumerate(s1,2))) 
  
  


# In[ ]:




