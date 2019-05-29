list=[["a","b","c"],["d","e","f"],["g","h","i"],["j","k","l"]]

arr=[1,2,3,4]

print(list[2][0] )

print(list[0])

print(list[0][1:])

print(list[2][:2])

# append the element at the end of 2nd row in 2d_arr
list[1].append("g")
print(list[1])

# append an element at the end of arr
arr.append(5)
print(arr[1])
print(arr)

# extend 2d_arr
list[2].extend(['j','k'])
print(list)

#extend 1d_arr
arr.extend([6,7])
print(arr)

# we can't extend the limit by following
list[4].extend(['x','y','z'])
print(list)
