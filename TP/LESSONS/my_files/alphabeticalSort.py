l = ['b', 'c', 'f', 's', 'y', 'i', 'a', 'z', 'o']
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
