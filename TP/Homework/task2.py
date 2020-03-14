list1 = [1, 5, 200, 3, 100, 10000, 5, 3]
dict1 = {}
for i in list1:
	if dict1.get(i):
		dict1[i] += 1
	else:
		dict1[i] = 1

for key, value in dict1.items():
	print(key, ":", value)