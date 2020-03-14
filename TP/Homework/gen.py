def reverse(data):
    for index in range(len(data) - 1, - 1, -1):
        yield data[index]

data = [12312, 21321, 213, 21, 32, 23]

rev = reverse(data)
print(next(rev))
print(next(rev))
print(next(rev))