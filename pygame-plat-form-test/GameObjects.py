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
		pygame.draw.rect(surface, white, self.getRect(), 1)
	def getWidth(self):
		return self.width
	def getHeight(self):
		return self.height
	def detectCollision(self, rect1, rect2):
		#if (rect1.x < rect2.x + rect2.width and
		#	rect1.x + rect1.width > rect2.x and
		#	rect1.y < rect2.y + rect2.height and
		#	rect1.height + rect1.y > rect2.y):
		#		return 1
		if (rect1[0] < rect2[0] + rect2[2] and
			rect1[0] + rect1[2] > rect2[0] and
			rect1[1] < rect2[1] + rect2[3] and
			rect1[3] + rect1[1] > rect2[1]):
				return 1
		return 0

class GameTile(GameBlock):
	def __init__(self, x, y, width, height, tile):
		super(GameTile, self).__init__(x, y, width, height)
		self.tile = tile
		self.ident = "GameTile"
	def getTile(self):
		return (self.tile)
	def setTile(self, tile):
		self.tile = tile

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
		self.p_speed = 5
		self.vx = self.p_speed
		self.vy = self.p_speed
		#movement booleans (keeping track of what movement to do
		self.moveLeft = False
		self.moveRight = False
		self.moveDown = False
		self.moveUp = False
		
		#jumping related varaibles
		self.jumpHeight = 0
		self.jumping = False
		
		#our own identity if someones searches for us you know.
		self.ident = "companionCube"
	def getTileset(self):
		return (self.spriteset)
	def setTileset(self, spriteset):
		self.spriteset = spriteset
	def handleEvents(self, event):
		if event.type == KEYDOWN:
			if event.key == K_w:
				self.moveUp = True
			if event.key == K_a:
				self.moveLeft = True
			if event.key == K_d:
				self.moveRight = True
			if event.key == K_s:
				self.moveDown = True
		if event.type == KEYUP:
			if event.key == K_w:
				self.moveUp = False
			if event.key == K_a:
				self.moveLeft = False
			if event.key == K_d:
				self.moveRight = False
			if event.key == K_s:
				self.moveDown = False
	def update(self):
		if self.moveUp:
			self.setPos(self.getPos()[0], self.getPos()[1]-self.vy)
		if self.moveDown:
			self.setPos(self.getPos()[0], self.getPos()[1]+self.vy)
		if self.moveLeft:
			self.setPos(self.getPos()[0]-self.vx, self.getPos()[1])
		if self.moveRight:
			self.setPos(self.getPos()[0]+self.vx, self.getPos()[1])
	def draw(self, surface):
		pygame.draw.rect(surface, green, self.getRect(), 0)
	def handleCollisions(self, gameobjects):
		for identity in gameobjects:
			if identity.ident == "GameTile":
				if((self.y+self.height > identity.getPos()[1]) and (self.y < identity.getPos()[1]+identity.getWidth())) and (self.x + self.width > identity.getPos()[0]) and (self.x < identity.getPos()[0]+identity.getWidth()):
					if self.moveRight and ((self.x+self.width) > identity.getPos()[0]):
						print "Hit left wall."
						self.x -= self.vx
					if self.moveLeft and (self.x < identity.getPos()[0]+identity.getWidth()):
						print "Hit Right wall."
						self.x += self.vx
					if self.moveDown and ((self.y+self.height) > identity.getPos()[1]):
						print "Hit upper wall."
						self.y -= self.vy
					if self.moveUp and (self.y < (identity.getPos()[1]+identity.getHeight())):
						print "Hit bottom wall."
						self.y += self.vy