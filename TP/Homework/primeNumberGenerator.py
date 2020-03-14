def prime_numbers():
    num = 2
    while True:
        for i in range(2, num + 1):
            if num % i == 0:
                break
        if num == i:
            yield num
        num += 1

count = int(input("Enter a number:"))
prime = prime_numbers()
for i in range(count):
    print(next(prime))
