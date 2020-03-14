class Address:

	def __init__(self, city, street, streetNumber):
		self.__city = city
		self.__street = street
		self.__streetNumber = streetNumber

	def getAddressInfo(self):
		print("Address of Student")
		print("------------------")
		print("City :", self.__city)
		print("Street :", self.__street)
		print("Street number :", self.__streetNumber)
		print()

class Person:

	def __init__(self, name, address):
		self.__name = name 
		self.__address = address

	def getName(self):
		return self.__name

	def getPersonInfo(self):
		address.getAddressInfo()

class MarkBook:

	__grades = {}	

	def addMark(self, subject, mark):
		if subject not in self.__grades:
			self.__grades[subject] = list([])
		self.__grades[subject].append(mark)

	def getMarks(self, subject):
		return self.__grades[subject]

	def getAverage(self, subject):
		return sum(self.__grades[subject]) / len(self.__grades[subject])

class Student(Person, MarkBook):

	def __init__(self, name, address, number, computer):
		self.__name = name
		self.__address = address
		self.__number = number
		self.__computer = computer

	def getAddressInfo(self):
		self.__address.getAddressInfo()

	def getComputerInfo(self):
		self.__computer.getComputerInfo()

	def getStudentInfo(self):
		print("Name of Student:", self.__name)
		print("Number in class:", self.__number)
		print()
		Person(self.__name, self.__address).getPersonInfo()

	def addStudentMark(self, subject, mark): 
 		MarkBook.addMark(self, subject, mark)

	def getStudentMarks(self, subject):
		print("Student's marks: ", MarkBook.getMarks(self, subject))

	def getStudentAverage(self, subject):
		print("Student's average: ", MarkBook.getAverage(self, subject))

class Computer:

	def __init__(self, mark, year, cpu, os, ram, disk):
		self.__mark = mark
		self.__year = year
		self.__cpu = cpu
		self.__os = os
		self.__ram = ram
		self.__disk = disk

	def getComputerInfo(self):
		print("Student's computer specifications")
		print("----------------------------------")
		print("Mark:", self.__mark)
		print("Year:", self.__year)
		print("CPU:", self.__cpu)
		print("Operation system:", self.__os)
		print("Ram:", self.__ram)
		print("Disk:", self.__disk)
		print()


address = Address("Malo Buchino", "Bor", "1")
person = Person("Biko", address)
computer = Computer("A", "2015", "i5-4440", "Linux 18.04", "8GB DDR3", "1TB HDD")
student = Student(person.getName() , address, "17", computer)

student.getStudentInfo()
student.getComputerInfo()
student.addStudentMark("TP", 2)
student.addStudentMark("TP", 3)
student.getStudentAverage("TP")
student.getStudentMarks("TP")
