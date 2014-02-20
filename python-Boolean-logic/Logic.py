class Logic(object):
	def __init__(self, state):
		self.state = state
	def printState(self):
		print self.state

class And(Logic):
	def __init__(self, state=False):
		Logic.__init__(self, state)
	def andd(self, a, b):
		self.state = (a and b)
		return bool(self.state),

class Nand(And):
	def __init__(self, state=True):
		And.__init__(self, state)
	def nand(self, a, b):
		self.state = self.andd(a, b)
		return bool(not self.state),

class Or(Logic):
	def __init__(self, state=False):
		Logic.__init__(self, state)
	def orr(self, a, b):
		self.state = (a or b)
		return bool(self.state),

class Nor(Or):
	def __init__(self, state=True):
		Or.__init__(self, state)
	def nor(self, a, b):
		self.state = self.orr(a, b)
		return bool(not self.state),

class Not(Logic):
	def __init__(self, state=True):
		Logic.__init__(self, state)
	def nott(self, a):
		return bool(not a),

class Xor(And, Or, Not, object):
	def __init__(self, state=False):
		self.state = False
	def xor(self,a, b):
		aNot = self.nott(a)
		bNot = self.nott(b)
		aTemp = self.andd(a, bNot)
		bTemp = self.andd(b, aNot)
		return bool(self.orr(aTemp, bTemp)),

class Xnor(Xor):
	def __init__(self, state=True):
		Xor.__init__(self, state)
	def xnor(self, a, b):
		return (bool( not self.xor(a,b))),

class Latch(Not, Or):
	def SRlatch(self, a, b):
		Set = b
		Reset = a
		Q = self.orr(self.nott(Reset), Set)
		Qn = self.orr(Reset, self.nott(Set))
		return (bool(Q), bool(Qn))
		
