class Student():

	def __init__(self, name, number):
		self.__name = name
		self.__number = number
		self.__marks = []

	def addMark(self, value):
		self.__marks.append(value)

	def avarageMark(self):
		return  sum(self.__marks) / len(self.__marks)


student = Student("Mariyan Bitsov", 18)
student.addMark(5)
student.addMark(6)
print("Average Mark:", student.avarageMark(), "\n")