class InvalidNumberException: 
    pass


class Student:
    def __init__(self):
        self.__students = {}

    def addStudent(self, name, number):
        if name not in self.__students:
            self.__students[number] = list([])
        self.__students[number].append(name)

    def getName(self, number):
        try:
            if number in self.__students:
                return self.__students[number]
            else:
                raise InvalidNumberException
        except InvalidNumberException:
            print("You entered invalid number")
student = Student()
student.addStudent("Mariyan Bitsov", 17)
student.addStudent("Martin Simov", 18)
student.addStudent("Kiril Chingarov", 12)
num = input('Enter a number: ')
print(student.getName(int(num))) 

