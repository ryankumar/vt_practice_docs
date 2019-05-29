print(["a","b","c"].index("c")) # o/p:2

#ret=(3,2,1).pop(2) #tuple object has no attribute " pop "
#print(ret)

ret={1,3,5} & {2,4,6} # find the common element in both set
print(ret)


ret={1,2,3} & {1} # common element is 1 in both set
print(ret)

print(3 in {1,2,3} ^ {3,4,5}) # if 3 exist in set(which is ^ operation of two set i.e; {1,2,4,5}) then true otherwise it is false


#print("abcde".remove("c")) # string has no atrribute "remove"

print(3 not in (1,2,3)) # condition false.

