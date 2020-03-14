import unittest


class StackImplementation:

    data = []

    def __init__(self):
        self.__top = 0

    def size(self):
        return len(self.data)

    def push(self, value):
        return self.data.insert(self.__top, value)
        
    def pop(self): 
        return self.data.pop()

class TestStackImplementation(unittest.TestCase):
    def setUp(self):
        self.Stack = StackImplementation()
        self.Stack.push(1)

    def test_default_stackImplementation(self):
        self.assertEqual(self.Stack.data[0], (1), 'incorrect default stack')

    def test_push(self):
        self.Stack.push(3)
        self.assertEqual(self.Stack.data[0], (3), 'incorrect element on push')
        self.Stack.push(4)
        self.assertEqual(self.Stack.data[0], (4), 'incorrect element on push')

    def test_pop(self):
        self.assertEqual(self.Stack.data[0], self.Stack.pop(), 'incorrect popped element')

if __name__ == '__main__':
    unittest.main()
