#!/usr/bin/env python
# coding: utf-8

# # Adding elements to a Dictionary

# In[1]:


Dict = {} 
# Adding elements one at a time 
Dict[0] = 'Geeks'
Dict[2] = 'For'
Dict[3] = 1
print("\nDictionary after adding 3 elements: ") 
print(Dict) 


# # Adding set of values to a single Key 

# In[2]:


Dict['Value_set'] = 2, 3, 4
print("\nDictionary after adding 3 elements: ") 
print(Dict) 


# # Updating existing Key's Value 

# In[3]:


Dict[2] = 'Welcome'
print("\nUpdated key value: ") 
print(Dict) 


# # Adding Nested Key value to Dictionary 

# In[4]:


Dict[5] = {'Nested' :{'1' : 'Life', '2' : 'Geeks'}} 
print("\nAdding a Nested Key: ") 
print(Dict) 


# # Accessing elements from a Dictionary

# In[5]:


Dict = {1: 'Geeks', 'name': 'For', 3: 'Geeks'} 
print("Acessing a element using key:") 
print(Dict['name']) 


# # accessing a element using get() method 

# In[6]:


print("Acessing a element using get:") 
print(Dict.get(3)) 


# # Removing Elements from Dictionary

# In[7]:


Dict = { 5 : 'Welcome', 6 : 'To', 7 : 'Geeks', 
        'A' : {1 : 'Geeks', 2 : 'For', 3 : 'Geeks'}, 
        'B' : {1 : 'Geeks', 2 : 'Life'}} 
print("Initial Dictionary: ") 
print(Dict) 

# Deleting a Key value 
del Dict[6] 
print("\nDeleting a specific key: ") 
print(Dict) 
  


# # Deleting a Key from Nested Dictionary 

# In[8]:


del Dict['A'][2] 
print("\nDeleting a key from Nested Dictionary: ") 
print(Dict) 


# # Deleting a Key using pop() 

# In[9]:


Dict.pop(5) 
print("\nPopping specific element: ") 
print(Dict) 


# # Deleting a Key using popitem() 

# In[10]:


Dict.popitem() 
print("\nPops first element: ") 
print(Dict) 


# # Deleting entire Dictionary 

# In[11]:


Dict.clear() 
print("\nDeleting Entire Dictionary: ") 
print(Dict) 


# # Dictionary Methods
# 
# ### copy() 	They copy() method returns a shallow copy of the dictionary.
# ### clear() 	The clear() method removes all items from the dictionary.
# ### pop() 	Removes and returns an element from a dictionary having the given key.
# ### popitem() 	Removes the arbitrary key-value pair from the dictionary and returns it as tuple.
# ### get() 	It is a conventional method to access a value for a key.
# ### dictionary_name.values() 	returns a list of all the values available in a given dictionary.
# ### str() 	Produces a printable string representation of a dictionary.
# ### update() 	Adds dictionary dict2’s key-values pairs to dict
# ### setdefault() 	Set dict[key]=default if key is not already in dict
# ### keys() 	Returns list of dictionary dict’s keys
# ### items() 	Returns a list of dict’s (key, value) tuple pairs
# ### has_key() 	Returns true if key in dictionary dict, false otherwise
# ### fromkeys() 	Create a new dictionary with keys from seq and values set to value.
# ### type() 	Returns the type of the passed variable.
# ### cmp() 	Compares elements of both dict.

# # Convert a list of Tuples into Dictionar

# In[14]:


list=[("madhab",2) , ("gopal",5) ,("mahesh",8)]
print(list)
print(dict(list))


# # By using setdefault

# In[15]:


def Convert(tup, di): 
    for a, b in tup: 
        di.setdefault(a, []).append(b) 
    return di 
      
# Driver Code     
tups = [("akash", 10), ("gaurav", 12), ("anand", 14),  
     ("suraj", 20), ("akhil", 25), ("ashish", 30)] 
dictionary = {} 
print (Convert(tups, dictionary)) 


# In[ ]:




