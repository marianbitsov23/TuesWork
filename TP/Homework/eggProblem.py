def egg_throw(braking_floor):
    start = 14
    starting_floor = start
    current_floor = 1
    iterations = 0
    while start != 0:
        if starting_floor >= braking_floor:
            iterations += 1
            while True:
                if current_floor == braking_floor:
                    print("Last floor, where the egg will survive:")
                    print(current_floor - 1)
                    print('Iterations performed:', iterations)
                    return 1
                current_floor += 1 
                iterations += 1
            print("Last floor, where the egg will survive:")
            print(current_floor - 1)
            print('Iterations performed:', iterations)
            return 1

        iterations += 1
        start -= 1
        starting_floor += start
        current_floor += start + 1
    return -1

floor = int(input("Enter braking floor:"))

if egg_throw(floor) == -1:
    print('You enterd invalid braking floor')

