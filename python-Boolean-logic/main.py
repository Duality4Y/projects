import Logic

and1 = Logic.And()
or1 = Logic.Or()
nand1 = Logic.Nand()
nor1 = Logic.Nor()
not1 = Logic.Not()
xor1 = Logic.Xor()
xnor1 = Logic.Xnor()
latch1 = Logic.Latch()

firstnum = 1
secondnum = 0

def getInput():
	firstnum = raw_input("a input: ")
	secondnum = raw_input("b input: ")
truthTable = 	[[0,0],
				[0,1],
				[1,0],
				[1,1]]

print "not: "
print not1.nott(1)
print not1.nott(0)

print "and: "
for test in truthTable:
	print and1.andd(test[0],test[1])

print "nand: "
for test in truthTable:
	print nand1.nand(test[0],test[1])

print "or: "
for test in truthTable:
	print or1.orr(test[0],test[1])

print "nor: "
for test in truthTable:
	print nor1.nor(test[0],test[1])

print "xor: "
for test in truthTable:
	print xor1.xor(test[0], test[1])

print "xnor: "
for test in truthTable:
	print xnor1.xnor(test[0], test[1])

print "latch: "
for test in truthTable:
	print latch1.SRlatch(test[0], test[1])

while False:
	print "1. and"
	print "2. or"
	print "3. nand"
	print "4. nor"
	answer = raw_input("select: ")
	if(answer == "1"):
		getInput()
		print and1.andd(firstnum,secondnum)
	elif(answer == "2"):
		getInput()
		print or1.orr(firstnum, secondnum)
	elif(answer == "3"):
		getInput()
		print nand1.nand(firstnum, secondnum)
	elif(answer == "4"):
		getInput()
		print nor1.nor(firstnum, secondnum)
	if raw_input("continue ?") == "no":
		break
