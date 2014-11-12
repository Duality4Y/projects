import math, sys
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
		return (int(self.x), int(self.y) )
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
		#pygame.draw.rect(self.surface, blue, self.getRect(), 0)
		#pygame.draw.rect(self.surface, white, self.getRect(), 1)
		pass

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

class Vector(object):
	def __init__(self, position, angle=None, magnitude=None):
		self.magnitude = magnitude	#length of the vector
		self.angle = angle 			#angle in which it points.
		self.position = position	#it's position
		#unit vector
		self.dx_unit = 0
