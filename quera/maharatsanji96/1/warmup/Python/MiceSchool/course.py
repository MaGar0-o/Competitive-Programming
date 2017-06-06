class Course(object):

	def __init__(self):
		self.peo = []
		self.name = ""


	def register(self, s):
		if (len(self.peo) == 10):
			return False
		self.peo.append(s)
		return True


	def getNumOfStudents(self):
		return len(self.peo)

	
	def getStudents(self):
		return self.peo[:]

	
	def getName(self):
		return self.name


	def setName(self, name):
		self.name = name
		return

