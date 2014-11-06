import math
import pygame
from pygame.locals import *

white = (255,255,255)
black = (0,0,0)
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
yellow = (255,255,0)

tile_height = 40
tile_width = tile_height

window_height = 480
window_width = 640

platform_base_height = 40

"""Basic game object, from which everything is build."""
class GameObject(object):
	def __init__(self, x, y, surface):
		self.x = x
		self.y = y
		self.surface = surface
		self.ident = "GameObject"
	def getIdent(self):
		return self.ident
	def getPos(self):
		return (self.x, self.y)
	def setPos(self, x, y):
		self.x = x
		self.y = y
"""tiles and players and mobs are derived from this object."""
class GameBlock(GameObject):
	def __init__(self, x, y, width, height, surface):
		super(GameBlock, self).__init__(x, y, surface)
		self.width = width
		self.height = height
		self.ident = "GameBlock"
	def getRect(self):
		return (self.x, self.y, self.width, self.height)
	def setRect(self, x, y, width, height):
		self.x = x
		self.y = y
		self.width = width
		self.height = height
	def getRight(self):
		return (self.x+self.width)
	def getLeft(self):
		return (self.x)
	def getTop(self):
		return (self.y)
	def getBottom(self):
		return (self.y+self.height)
	def getMidPos(self):
		return (self.x+(self.width/2), self.y+(self.height/2))
	def getTopLeftCorner(self):
		return self.getPos()
	def getTopRightCorner(self):
		return ( (self.x+self.width), self.y)
	def getBottomLeftCorner(self):
		return (self.x, (self.y+self.height))
	def getBottomRightCorner(self):
		return (self.x+self.width, self.y+self.height)
	def getWidth(self):
		return self.width
	def getHeight(self):
		return self.height
	def printDebug(self):
		print "Position:			{}".format(self.getPos())
		print "self:				{}".format(self)
		print "rect:				{}".format(self.getRect())
		print "Left:				{}".format(self.getLeft())
		print "Right:				{}".format(self.getRight())
		print "Top:					{}".format(self.getTop())
		print "Bottom:				{}".format(self.getBottom())
		print "Width:				{}".format(self.getWidth())
		print "Height:				{}".format(self.getHeight())
		print "TopLeftCorner:		{}".format(self.getTopLeftCorner())
		print "TopRightCorner:		{}".format(self.getTopRightCorner())
		print "BottomLeftCorner:	{}".format(self.getBottomLeftCorner())
		print "BottomRightCorner:	{}".format(self.getBottomRightCorner())
		print "MidPosition:			{}".format(self.getMidPos())
	def detectCollision(self, rect1, rect2):
		if (rect1[0] < rect2[0] + rect2[2] and
			rect1[0] + rect1[2] > rect2[0] and
			rect1[1] < rect2[1] + rect2[3] and
			rect1[3] + rect1[1] > rect2[1]):
				return 1
		return 0
	def handleCollisions(self, gameobjects):
		pass
	def update(self):
		pass
	def handleEvents(self):
		pass
	#handle that is called to draw things. in this case a test cube with a line around it.
	def draw(self):
		pygame.draw.rect(self.surface, blue, self.getRect(), 0)
		pygame.draw.rect(self.surface, white, self.getRect(), 1)

"""tiles have static sprites (mostely)"""
class GameTile(GameBlock):
	def __init__(self, x, y, width, height, tile, surface):
		super(GameTile, self).__init__(x, y, width, height, surface)
		self.tile = tile
		self.ident = "GameTile"
	def getTile(self):
		return (self.tile)
	def setTile(self, tile):
		self.tile = tile

"""game mobs have dynamic sprites"""
class GameMob(GameBlock):
	def __init__(self, x, y, width, height, spriteset, surface):
		super(GameMob, self).__init__(x, y, width, height, surface)
		self.spriteset = spriteset
		self.ident = "GameMob"
	def getTileset(self):
		return (self.spriteset)
	def setTileset(self, spriteset):
		self.spriteset = spriteset

class companionCube(GameMob):
	def __init__(self, x, y, width, height, spriteset=None, surface=None):
		super(GameMob, self).__init__(x, y, width, height, surface)
		self.spriteset = spriteset
		
		#speed in pixels
		self.p_speed = 5
		self.dx = 0
		self.dy = 0
		self.accel = 4
		self.accelX = 4
		self.move = True
		
		#jumping related varaibles
		self.jumpHeight = tile_height*3
		self.jumping = False
		self.currentHeight = self.y
		
		self.mouseControlle = False
	def getTileset(self):
		return (self.spriteset)
	def setTileset(self, spriteset):
		self.spriteset = spriteset
	def handleEvents(self):
		keys = pygame.key.get_pressed()
		if keys[K_a]:
			self.dx = -self.p_speed
		if keys[K_d]:
			self.dx = self.p_speed
		if keys[K_s]:
			self.dy = self.p_speed
		if keys[K_w]:
			self.dy = -self.p_speed
		if not keys[K_w] and not keys[K_s]:
			self.dy = 0;
		if not keys[K_a] and not keys[K_d]:
			self.dx = 0;
		if keys[K_m]:
			if not keys[K_m]:
				self.mouseControlle != self.mouseControlle
	def update(self):
		if self.mouseControlle:
			self.x,self.y = pygame.mouse.get_pos()
		if self.move:
			#apply side ways movement
			self.x += self.dx
			#apply upwart/downwart movement
			self.y += self.dy
			
		if (self.currentHeight - self.y) >= self.jumpHeight and self.jumping:
			self.jumping = False
		if self.jumping and self.colliding:
			self.jumping = False
		#print "jumping  : {}".format(self.jumping)
	def draw(self):
		pygame.draw.rect(self.surface, green, self.getRect(), 0)
		pygame.draw.rect(self.surface, white, self.getRect(), 1)
	def handleCollisions(self, gameobjects):
		for gameobject in gameobjects:
			if gameobject.ident == "GameTile":
			#if gameobject.detectCollision(self.getRect(), gameobject.getRect()):
				xdif = gameobject.x-self.x
				ydif = gameobject.y-self.y
				#draw the x difference line in red
				#draw the y difference line in yellow
				pygame.draw.line(self.surface, red, (gameobject.x+xdif, gameobject.y), gameobject.getPos(), 1)
				pygame.draw.line(self.surface, yellow, (gameobject.x, gameobject.y+ydif), gameobject.getPos(), 1)
				#calc hypotnues and draw it.
				hypo = math.hypot(xdif,ydif)
				pygame.draw.line(self.surface, green, [10,10], [10+hypo, 10])
				
				try:
					print "sin:"+str(ydif/hypo)
					print "cos:"+str(xdif/hypo)
					print 360/((ydif/hypo)+(xdif/hypo))*math.pi
				except ZeroDivisionError:
					pass
