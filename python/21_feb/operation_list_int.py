list=[1,2,3]

list.append(4)
print(list)

list.extend([7,6])
print(list)

#POP THE GIVEN POSITION's ELEMENT
print(list.pop(3))
print(list)

#INSERT ELEMENT AT GIVEN POSITION I.E; INSERT(POSITION,ELEMENT)
list.insert(2,2)
print(list)

# sorting in ascending order
list.sort()
print(list)

#sorting in descending order
list.sort(reverse=True)
print(list)

#RETURN THE POSITION OF GIVEN ELEMENT
pos=list.index(7)
print("position of given element is ",pos)

#COUNT HOW MANY TIMES ITEM APPEARS IN LIST
ret=list.count(2)
print("no of occurance of 2 is", ret, "times")

#REMOVE THE 1ST OCCURENCE OF ITEM IN LIST
list.remove(2)
print(list)




