import pygame

class Sprite(object):
	def __init__(self, position, size):
		self.pos = position
		self.size = size
		self.rect = (self.pos[0],self.pos[1],self.size[0],self.size[1])
		
	def getRect(self):
		return self.rect
	def setRect(self, rect):
		self.rect = rect
		
	def getSize(self):
		return self.size
	def setSize(self, size):
		self.size = size
		self.updateRect(self.pos,self.size)
		
	def getPos(self):
		return self.pos
	def setPos(self,pos):
		self.pos = pos
		self.updateRect(self.pos,self.size)
		
	def updateRect(self, position, size):
		self.setRect((position[0],position[1],size[0],size[1]))

class Spritesheet(Sprite):
	def __init__(self, pos, size,sheetSize):
		Sprite.__init__(self, pos, size)
		self.sheetSize = sheetSize
		self.sheet = pygame.Surface(self.getSheetsize())
		self.sheet.fill((100,100,100))
		self.sheetRect = self.getSheetRect()
		self.texture = pygame.Surface(self.getSize())
	def getSheetRect(self):
		return (self.getPos()[0],self.getPos()[1],self.getSheetsize()[0]+self.getPos()[0],self.getSheetsize()[1]+self.getPos()[1])
	def getSheetsize(self):
		return self.sheetSize
		

"""
	these are test classes.
"""

class Testy(Spritesheet):
	def __init__(self, pos, size, sheetSize):
		Spritesheet.__init__(self, pos, size, sheetSize)
	def draw(self, screen):
		screen.blit(self.texture,self.getPos(),self.getRect())
	def drawSheet(self, screen):
		screen.blit(self.sheet, self.getPos(), self.getSheetRect())

class Circle(Sprite):
	def __init__(self, pos, size, color = (0,0,0),fill = 0):
		Sprite.__init__(self,pos,size)
		self.color = color
		self.fill = fill
	def draw(self, screen):
		pygame.draw.circle(screen,self.color,(self.getPos()),self.getSize()[0],self.fill)

class Cube(Sprite):
	def __init__(self,size, pos, color = (0,0,0)):
		Sprite.__init__(self,pos,size)
		self.color = color
	def draw(self,screen):
		pygame.draw.rect(screen,self.color,self.getRect(),0)
