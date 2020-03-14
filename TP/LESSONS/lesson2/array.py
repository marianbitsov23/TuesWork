import array as ar

# Create an array of 10 integers using range()
array_var = ar.array('i', range(10))

# Print array values using indices
print("1st array element is {} at index 0.".format(array_var[0]))
print("2nd array element is {} at index 1.".format(array_var[1]))
print("Last array element is {} at index 9.".format(array_var[9]))
print("Second array element from the tail end is {}.".format(array_var[-1]))
