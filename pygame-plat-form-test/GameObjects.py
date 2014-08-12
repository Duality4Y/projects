import pygame
from pygame.locals import *

white = (255,255,255)
black = (0,0,0)
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)

tile_height = 16
tile_width = tile_height

window_height = 480
window_width = 640

platform_base_height = 40

leftwall  = 1   #(1,0,0,0)
rightwall = 2   #(0,1,0,0)
topwall   = 3   #(0,0,1,0)
botwall   = 4   #(0,0,0,1)

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
	def handleCollisions(self, gameobjects):
		pass
	def update(self):
		pass
	def handleEvents(self, event):
		pass
	def draw(self, surface):
		pygame.draw.rect(surface, blue, self.getRect(), 0)

class GameTile(GameBlock):
	def __init__(self, x, y, width, height, tile):
		super(GameTile, self).__init__(x, y, width, height)
		self.tile = tile
		self.ident = "GameTile"
	def getTile(self):
		return (self.tile)
	def setTile(self, tile):
		self.tile = tile
	def getWidth():
		return self.width
	def getHeight():
		return self.height

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
		
		self.moveLeft = False
		self.moveRight = False
		
		self.jumpHeight = 0
		self.jumping = False
		
		self.base = window_height - platform_base_height
		self.gameobjects = None
		
		self.ident = "companionCube"
	def getTileset(self):
		return (self.spriteset)
	def setTileset(self, spriteset):
		self.spriteset = spriteset
	def handleEvents(self, event):
		#handle all events moving in this case
		if event.type == KEYDOWN:
			if event.key == K_a:
				self.moveLeft = True
			elif event.key == K_d:
				self.moveRight = True
			if event.key == K_SPACE:
				self.jumping = True
			if event.key == K_p and self.gameobjects:
				print "p pressed"
				for tile in self.gameobjects:
					print str(tile.getIdent())
		if event.type == KEYUP:
			if event.key == K_a:
				self.moveLeft = False
			elif event.key == K_d:
				self.moveRight = False
	#a function that update this that move and sprites and stuff.
	def update(self):
		if self.moveRight:
			self.setPos(self.getPos()[0]+1, self.getPos()[1]);
		if self.moveLeft:
			self.setPos(self.getPos()[0]-1, self.getPos()[1]);
	def draw(self, surface):
		pygame.draw.rect(surface, green, self.getRect(), 0)
	def handleCollisions(self, gameobjects):
		self.gameobjects = gameobjects
		for item in gameobjects:
			if item.getIdent == "GameTile":
				if ((self.y >= item.y) and (self.x > item.x) and (self.x < item.x+item.width)):
					self.y = item.y
				else:
					self.y -= 1
