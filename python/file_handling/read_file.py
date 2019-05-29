file = open("../1.c", "r")  
print( file.read() )

# Python code to illustrate read() mode character wise 
print("reading only 5 lines\n")
print( file.read(5) )


# Python code to create a file 
file = open('geek.txt','w') 
file.write("This is the write command") 
file.write("It allows us to write in a particular file") 
file.close() 


# Python code to illustrate append() mode 
file = open('geek.txt','a') 
file.write("This will add this line") 
file.close() 


# Python code to illustrate with() 
with open("geek.txt") as file:   
        data = file.read()  
        # do something with data  


# Python code to illustrate with() alongwith write() 
with open("geek.txt", "w") as f:  
        f.write("Hello World!!!")  

