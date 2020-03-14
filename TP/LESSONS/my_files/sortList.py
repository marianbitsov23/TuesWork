l = [3,56,21,4,5,6,223,5436,32,124,567]
print('Unsorted : ', l)
#l.sort()
size =  len(l)
temp = 0
for i in range(size):
	for j  in range(size - i - 1):
		if l[j] > l[j+1]:
			temp = l[j]
			l[j] = l[j+1]
			l[j+1] = temp

print('Sorted : ', l)
