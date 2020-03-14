dict = {1:"Aleks Videnov", 2:"Aleks Stefanov", 3:"Anton Yantchev", 4:"Boyan Kovachev", 5:"Valentin Spasov", 6:"Velislav Boyanov", 7:"Viktor Velev", 8:"Viktor Gorchilov", 9:"Gabriela Yontcheva", 10:"Georgi Lozanov", 11:"Kiril Chingarov", 12:"Kristian Gizod", 13:"Kristiyan Kirilov", 14:"Lara Angelova", 15:"Mariya-Yoana Aleksandrova", 16:"Mariyan Bitsov", 17:"Martiin Simov", 18:"Nikita Prodanov", 19:"Ognqn Baruh", 20:"Samuil Georgiev", 21:"Simeon Novkov" , 22:"Simeon Tsekov"}
print("Enter student's number:")
no = int(input())
if no >= 1 and no <= 26:
	print(dict.get(int(no)))
else:
	print("Student with number", no, " not found!")