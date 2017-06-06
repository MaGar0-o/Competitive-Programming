class Student(object):

	def __init__(self, firstName, age):
		self.firstName = firstName
		self.age = age

	def getFirstName(self):
		return self.firstName

	def setFirstName(self, firstName):
		self.firstName = firstName

	def getAge(self):
		return self.age

	def setAge(self, age):
		self.age = age

