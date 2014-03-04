import Logic

and1 = Logic.And()
nand1 = Logic.Nand()
or1 = Logic.Or()
nor1 = Logic.Nor()
not1 = Logic.Not()
xor1 = Logic.Xor()
xnor1 = Logic.Xnor()
latch1 = Logic.NorLatch()
latch2 = Logic.NandLatch()

truthTable = 	[[0,0],
				[0,1],
				[1,0],
				[1,1]]

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

print "not: "
print not1.nott(1)
print not1.nott(0)

print "xor: "
for test in truthTable:
	print xor1.xor(test[0], test[1])

print "xnor: "
for test in truthTable:
	print xnor1.xnor(test[0], test[1])

print "latch: "
for test in truthTable:
	print "Q: %d, Qn: %d" %(latch1.latch(test[0], test[1]))

print "instable test"
for i in range(0, 10):
	print "Q: %d, Qn: %d" %(latch1.latch(1, 1))
	print "Q: %d, Qn: %d" %(latch1.latch(1, 1))

print "nand latch"
for test in truthTable:
	print "Q: %d, Qn: %d" %(latch2.latch(Set,Reset))
