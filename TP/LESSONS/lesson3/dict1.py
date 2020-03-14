# Define a blank dictionary with no elements
blank_dict = {}

# Define a dictionary with numeric keys
num_dict = {1: 'soccer', 2: 'baseball'}
print("Sport with  key 1:", num_dict.get(1))

# Define a dictionary with keys having different types
misc_dict = {'class': 'senior secondary', 1: [1, 2, 3,4,5]}
print("Random 'class' dictioanry:", misc_dict.get('class'))
misc_dict['class'] =  1234
print("Edited random 'class' dictioanry:", misc_dict.get('class'))


# Create a dictionary with dict() method
get_dict_from_func = dict({1:'veg', 2:'non-veg'})

# Create a dictionary from a sequence of tuples
make_dict_from_seq = dict([(1,'jake'), (2,'john')])
