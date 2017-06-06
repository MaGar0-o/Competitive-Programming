#standard modules
import unittest

#problem's objects
from course import Course
from student import Student


class CourseTest(unittest.TestCase):
	
	def test1(self):
		c = Course()
		c.setName("scape")
		self.assertEqual(c.getName(), "scape")

	
	def test2(self):
		c = Course()
		for i in range(5):
			s = Student(str(i), i)
			self.assertTrue(c.register(s))
		self.assertEqual(c.getNumOfStudents(), 5)
		self.assertEqual(len(c.getStudents()), 5)

	
	def test3(self):
		c = Course()
		self.assertEqual(c.getNumOfStudents(), 0)
		for i in range(10):
			s = Student(str(i), i)
			self.assertTrue(c.register(s))
		s = Student("Ali", 21)
		self.assertFalse(c.register(s))
		self.assertEqual(c.getNumOfStudents(), 10)
		self.assertEqual(len(c.getStudents()), 10)


if __name__ == "__main__":
	unittest.main()

