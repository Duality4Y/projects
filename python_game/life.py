"""
	this file contains that describe the cells and the field.
"""

fieldWidth = 100
fieldHeight = 100
fieldSize = fieldWidth*fieldHeight
field = [1]*fieldSize
buffer = [0]*fieldSize

surviveAbility = 2
reproductiveNumber = 3
cellSize = 3
def checkUpper(field, position):
	if position-fieldWidth > 0:
		if field[position-fieldWidth]:
			return 1
		else:
			return 0
	else:
		return 0
	return 0

def checkLower(field, position):
	if position+fieldWidth<fieldSize:
		if field[position+fieldWidth]:
			return 1
		else:
			return 0
	else:
		return 0
	return 0

#check if there is a cell to the left of the current position in field.
def checkLeft(field, position):
	if(position-1>0):
		if(field[position-1]):
			return 1
		else:
			return 0
	else:
		return 0
	return 0
#check if there is a cell to the right of the current position in field.
def checkRight(field, position):
	if(position+1<fieldSize):
		if(field[position+1]):
			return 1
		else:
			return 0
	else:
		return 0
	return 0

#check if there is a cell to the upper left of the current position in field.
def checkUpperLeft(field, position):
	if(position-fieldWidth+1>0):
		if(field[position-fieldWidth+1]):
			return 1
		else:
			return 0
	else:
		return 0
	return 0
  
#check if there is a cell to the upper right of the current position in field.
def checkUpperRight(field, position):
	if(position-fieldWidth-1>0):
		if(field[position-fieldWidth-1]):
			return 1
		else:
			return 0
	else:
		return 0
	return 0
  
#check if there is a cell to the lower Left of the current position in field.
def checkLowerLeft(field, position):
	if(position+fieldWidth-1<fieldSize):
		if(field[position+fieldWidth-1]):
			return 1
		else:
			return 0
	else:
		return 0
	return 0

#check if there is a cell to the lower Right of the current position in field.
def checkLowerRight(field, position):
	if(position+fieldWidth+1<fieldSize):
		if(field[position+fieldWidth+1]):
			return 1
		else:
			return 0
	else:
		return 0
	return 0

#return how many lifing cels are around a position in field.
def totalAround(field, position):
	around = checkUpper(field, position)+checkLower(field, position)+checkLeft(field, position)+checkRight(field, position)+checkUpperLeft(field, position)+checkUpperRight(field, position)+checkLowerLeft(field, position)+checkLowerRight(field, position);
	return around
