list=["m","a","d","a","m"]

list.append("s")
print(list)

list.extend(["o","n"])
print(list)

#POP THE GIVEN POSITION's ELEMENT
print("pop the 3rd element is",list.pop(3))
print(list)

#INSERT ELEMENT AT GIVEN POSITION I.E; INSERT(POSITION,ELEMENT)
list.insert(3,"a")
print("insert a in 3rd location", list)

# sorting in ascending order
list.sort()
print("after sorting in ascending order", list)

#sorting in descending order
list.sort(reverse=True)
print("after sorting again in descending order", list)

#RETURN THE POSITION OF GIVEN ELEMENT
pos=list.index("s")
print("position of s  is ",pos)

#COUNT HOW MANY TIMES ITEM APPEARS IN LIST
ret=list.count("m")
print("no of occurance of m is", ret, "times")

#REMOVE THE 1ST OCCURENCE OF ITEM IN LIST
list.remove("m")
print("after remove m from list is", list)




