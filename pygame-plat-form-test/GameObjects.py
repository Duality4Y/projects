import pygame
from pygame.locals import *

white = (255,255,255)
black = (0,0,0)
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)

tile_height = 40
tile_width = tile_height

window_height = 480
window_width = 640

platform_base_height = 40

leftwall  = 1   #(1,0,0,0)
rightwall = 2   #(0,1,0,0)
topwall   = 3   #(0,0,1,0)
botwall   = 4   #(0,0,0,1)

"""Basic game object, from which everything is build."""
class GameObject(object):
	def __init__(self, x, y):
		self.x = x
		self.y = y
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
	def __init__(self, x, y, width, height):
		super(GameBlock, self).__init__(x, y)
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
	def handleEvents(self, event):
		pass
	#handle that is called to draw things. in this case a test cube with a line around it.
	def draw(self, surface):
		pygame.draw.rect(surface, blue, self.getRect(), 0)
		pygame.draw.rect(surface, white, self.getRect(), 1)

"""tiles have static sprites (mostely)"""
class GameTile(GameBlock):
	def __init__(self, x, y, width, height, tile):
		super(GameTile, self).__init__(x, y, width, height)
		self.tile = tile
		self.ident = "GameTile"
	def getTile(self):
		return (self.tile)
	def setTile(self, tile):
		self.tile = tile
	def handleCollisions(self, gameObjects):
		for gameObject in gameObjects:
			print gameObject.ident;

"""game mobs have dynamic sprites"""
class GameMob(GameBlock):
	def __init__(self, x, y, width, height, spriteset):
		super(GameMob, self).__init__(x, y, width, height)
		self.spriteset = spriteset
		self.ident = "GameMob"
	def getTileset(self):
		return (self.spriteset)
	def setTileset(self, spriteset):
		self.spriteset = spriteset

class companionCube(GameMob):
	def __init__(self, x, y, width, height, spriteset):
		super(GameMob, self).__init__(x, y, width, height)
		self.spriteset = spriteset
		
		#speed in pixels
		self.p_speed = 1
		self.vx = 0
		self.vy = self.p_speed
		self.accel = 4
		self.accelX = 2
		
		#jumping related varaibles
		self.jumpHeight = tile_height*3
		self.jumping = False
		self.currentHeight = self.y
		
		self.mouseControlle = False
	def getTileset(self):
		return (self.spriteset)
	def setTileset(self, spriteset):
		self.spriteset = spriteset
	def handleEvents(self, event):
		if event.type == KEYDOWN:
			if event.key == K_a:
				self.vx = -self.p_speed
			elif event.key == K_d:
				self.vx = self.p_speed
			elif event.key == K_SPACE:
				if not self.jumping:
					self.jumping = True
				self.currentHeight = self.y
			elif event.key == K_p:
				self.printDebug()
			elif event.key == K_m:
				self.mouseControlle = True
		if event.type == KEYUP:
			if event.key == K_a:
				self.vx = 0
			elif event.key == K_d:
				self.vx = 0
	def update(self):
		if self.mouseControlle:
			self.x,self.y = pygame.mouse.get_pos()
		else:
			#apply gravity
			if not self.jumping:
				self.y += self.vy*self.accel
			else:
				self.y -= self.vy*self.accel
			#apply side ways movement
			self.x += self.vx*self.accelX
		
		if (self.currentHeight - self.y) >= self.jumpHeight and self.jumping:
			self.jumping = False
		if self.jumping and self.colliding:
			self.jumping = False
		print "jumping  : {}".format(self.jumping)
	def draw(self, surface):
		pygame.draw.rect(surface, green, self.getRect(), 0)
		pygame.draw.rect(surface, white, self.getRect(), 1)
	def handleCollisions(self, gameobjects):
		pass
