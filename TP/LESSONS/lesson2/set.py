# set can't store duplicate elements
py_set_num = {3, 7, 11, 15, 3, 7}
# it'll automatically filter the duplicates
print(py_set_num)

# create a set using the set() method
# creating set with a fixed set of elements
py_set_mix = set([11, 1.1, "11", (1, 2)])
print(py_set_mix)

# creating set with dynamic elements
py_list = [11, 1.1, "11", (1, 2)]
py_list.append(12)
print(py_list)
py_set_mix = set(py_list)
print(py_set_mix)

# pop an element from the set
py_set_num.pop()
print("py_set_num.pop():", py_set_num)

# pop one more element from the set
py_set_num.pop()
print("py_set_num.pop():", py_set_num)

# clear all elements from the set
py_set_num.clear()
print("py_set_num.clear():", py_set_num)