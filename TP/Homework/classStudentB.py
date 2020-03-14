class Studet():

	def __init__(self, name, number):
		self.__name = name
		self.__number = number
		self.__grades = {}

	def addMark(self, subject, mark):
		marks = []
		marks.append(mark)
		if self.__grades.get(subject):
			self.__grades[subject].append(mark)
		else:
			self.__grades[subject] = marks

	def printDict(self):
		print(self.__grades)

	def averageMark(self, subject):
		return  sum(self.__grades[subject]) / len(self.__grades[subject])


student = Studet("Mariyan Bitsov", 18)
student.addMark("TP", 5)
student.addMark("TP", 6)
student.addMark("AE", 6)
student.addMark("AE", 4)
print("Average mark:", student.averageMark("AE"), "\n")
student.printDict()
