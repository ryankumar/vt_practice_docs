#!/usr/bin/env python
# coding: utf-8

# # Creating an empty Dictionary 

# In[1]:


Dict = {} 
print("Empty Dictionary: ") 
print(Dict) 


# # Creating a Dictionary with Integer Keys 

# In[2]:


Dict = {1: 'Geeks', 2: 'For', 3: 'Geeks'} 
print("\nDictionary with the use of Integer Keys: ") 
print(Dict) 


# # Creating a Dictionary with Mixed keys 

# In[9]:


Dict = {'Name': 'Geeks', 1: [1, 2, 3, 4]} 
print("\nDictionary with the use of Mixed Keys: ") 
print(Dict) 
print(Dict['Name'][3])
print(Dict[1][0])


# # Creating a Dictionary with dict() method  

# In[10]:


Dict = dict({1: 'Geeks', 2: 'For', 3:'Geeks'}) 
print("\nDictionary with the use of dict(): ") 
print(Dict) 


# # Creating a Dictionary with each item as a Pair 

# In[11]:


Dict = dict([(1, 'Geeks'), (2, 'For')]) 
print("\nDictionary with each item as a pair: ") 
print(Dict) 


# # Creating a Nested Dictionary as shown in the below image 

# In[16]:


Dict = {1: 'Geeks', 2: 'For',  
        3:{'A' : 'Welcome', 'B' : 'To', 'C' : 'Geeks'}} 
  
print(Dict)
print("With key :",Dict[3])
print("with nested key: ",Dict[3]['B'])


# In[ ]:




