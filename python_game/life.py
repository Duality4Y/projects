"""
	this file contains that describe the cells and the field.
"""

import pygame
import random

class Life(object):
	def __init__(self, width = 800, height = 600, size = 10, color = (100,100,100)):
		self.surviveAbility = 2
		self.reproductiveNumber = 3
		
		self.cellRadius = size
		self.cellSize = self.cellRadius*2
		self.cellBorderWidth = 2
		self.cellColor = color
		
		self.x = 0;
		self.y = 0;
		
		self.width =  width
		self.height = height
		
		self.fieldWidth = int(self.width/self.cellSize)
		self.fieldHeight = int(self.height/self.cellSize)
		self.fieldSize = self.fieldWidth*self.fieldHeight
		self.field = [1]*self.fieldSize
		
		self.buffer = [0]*self.fieldSize
		
		self.position = 0;
		
		self.createRandomField();
	def setCellSize(self,size):
		self.__init__(self.width,self.height,size,self.cellColor);
		self.createRandomField();
	def setCellColor(self, color):
		self.cellColor = color
	def getFieldSize(self):
		return self.fieldSize
	def getSize(self):
		return (self.width, self.height)
	def processLife(self,screen):
		for self.position,cell in enumerate(self.field):
			if(self.field[self.position]):
				if(self.totalAround(self.field, self.position) == self.surviveAbility):
					self.buffer[self.position]=1
				elif(self.totalAround(self.field, self.position) == self.surviveAbility+1):
					self.buffer[self.position]=1
				else:
					self.buffer[self.position]=0
			else:
				if(self.totalAround(self.field, self.position) == self.reproductiveNumber):
					self.buffer[self.position] = 1
				else:
					self.buffer[self.position] = 0
			cellX, cellY = self.calcPos();
			if cell:
				self.displayCell(cellX, cellY, screen)
		self.copy_buffer(self.buffer, self.field);
	def calcPos(self):
		self.calc_xy(self.position)
		return (self.x*self.cellSize)+self.cellRadius, (self.y*self.cellSize)+self.cellRadius
	def displayCell(self, x, y, screen):
		pygame.draw.circle(screen,self.cellColor,(x,y),self.cellRadius,int(self.cellSize/10))
	#create a random field
	def createRandomField(self):
		for i,cell in enumerate(self.field):
			self.field[i] = random.randint(0,1);
	def copy_buffer(self, buffer, field):
		size = self.fieldSize
		while(size):
			size -= 1;
			self.field[size] = self.buffer[size];
	def calc_xy(self,position):
		self.x = position%self.fieldWidth
		if((self.x) == 0):
			self.y += 1
			if(self.y >= (self.fieldHeight)):
				self.y = 0
	def getCellRect(self):
		temp_x,temp_y = self.calcPos();
		return (temp_x,temp_y,self.cellSize,self.cellSize)
	def checkUpper(self, field, position):
		if position-self.fieldWidth > 0:
			if field[position-self.fieldWidth]:
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	def checkLower(self, field, position):
		if position+self.fieldWidth<self.fieldSize:
			if field[position+self.fieldWidth]:
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#check if there is a cell to the left of the current position in field.
	def checkLeft(self, field, position):
		if(position-1>0):
			if(field[position-1]):
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#check if there is a cell to the right of the current position in field.
	def checkRight(self, field, position):
		if(position+1<self.fieldSize):
			if(field[position+1]):
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#check if there is a cell to the upper left of the current position in field.
	def checkUpperLeft(self, field, position):
		if(position-self.fieldWidth+1>0):
			if(field[position-self.fieldWidth+1]):
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#check if there is a cell to the upper right of the current position in field.
	def checkUpperRight(self, field, position):
		if(position-self.fieldWidth-1>0):
			if(field[position-self.fieldWidth-1]):
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#check if there is a cell to the lower Left of the current position in field.
	def checkLowerLeft(self, field, position):
		if(position+self.fieldWidth-1<self.fieldSize):
			if(field[position+self.fieldWidth-1]):
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#check if there is a cell to the lower Right of the current position in field.
	def checkLowerRight(self, field, position):
		if(position+self.fieldWidth+1<self.fieldSize):
			if(field[position+self.fieldWidth+1]):
				return 1
			else:
				return 0
		else:
			return 0
		return 0
	#return how many lifing cels are around a position in field.
	def totalAround(self, field, position):
		around = self.checkUpper(field, position)+self.checkLower(field, position)+self.checkLeft(field, position)+self.checkRight(field, position)+self.checkUpperLeft(field, position)+self.checkUpperRight(field, position)+self.checkLowerLeft(field, position)+self.checkLowerRight(field, position);
		return around
