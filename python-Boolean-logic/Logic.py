class Logic(object):
	def __init__(self, state):
		self.state = state
	def printState(self):
		print self.state

class Not(Logic):
	def __init__(self, state=True):
		Logic.__init__(self, state)
	def nott(self, a):
		self.state = bool(not a)
		return self.state
		
class And(Logic):
	def __init__(self, state=False):
		Logic.__init__(self, state)
	def andd(self, a, b):
		self.state = bool(a and b)
		return self.state

class Nand(Not, And):
	def __init__(self, state=True):
		And.__init__(self, state)
	def nand(self, a, b):
		self.state = self.andd(a, b)
		self.state = self.nott(self.state)
		return self.state

class Or(Logic):
	def __init__(self, state=False):
		Logic.__init__(self, state)
	def orr(self, a, b):
		self.state = (a or b)
		return bool(self.state)

class Nor(Or):
	def __init__(self, state=True):
		Or.__init__(self, state)
	def nor(self, a, b):
		self.state = bool( not (self.orr(a, b)))
		return self.state

class Xor(And, Or, Not):
	def xor(self,a, b):
		aNot = self.nott(a)
		bNot = self.nott(b)
		aTemp = self.andd(a, bNot)
		bTemp = self.andd(b, aNot)
		self.state = bool(self.orr(aTemp, bTemp))
		return self.state

class Xnor(Xor):
	def xnor(self, a, b):
		self.state = bool( self.nott(self.xor(a,b)))
		return self.state

class Latch(Not, Or):
	def SRlatch(self, a, b):
		Set = a
		Reset = b
		Q = self.orr(self.nott(Reset), Set)
		Qn = self.orr(Reset, self.nott(Set))
		return (bool(Q), bool(Qn))
