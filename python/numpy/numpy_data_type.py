#!/usr/bin/env python
# coding: utf-8

# In[1]:


# Python Program to create a data type object
import numpy as np
 
# np.int16 is converted into a data type object.
print(np.dtype(np.int16))


# ### Python Program to create a data type object 
# ### containing a 32 bit big-endian integer

# In[2]:


import numpy as np
# i4 represents integer of size 4 byte
# > represents big-endian byte ordering and
# < represents little-endian encoding.
# dt is a dtype object

dt = np.dtype('>i4')
 
print("Byte order is:",dt.byteorder)
 
print("Size is:", dt.itemsize)
 
print("Data type is:", dt.name)


# ### Python program to differentiate between type and dtype.

# In[4]:


import numpy as np
 
a = np.array([1])
 
print("type is: ",type(a))
print("dtype is: ",a.dtype)


# ### Python program to demonstrate the use of data type object with structured array.

# In[10]:


import numpy as np

dt = np.dtype([('name', np.unicode_, 16),
               ('grades', np.float64, (2,))])

# x is a structured array with names
# and marks of students.
# Data type of name of the student is 
# np.unicode_ and data type of marks is 
# np.float(64)

x = np.array([('Sarah', (8.0, 7.0)),
              ('John', (6.0, 7.0))], dtype=dt)

print(x[1])
 
print("Grades of John are: ",x[1]['name'],":" ,x[1]['grades'])
print("Names are: ", x['name'])


# In[ ]:




