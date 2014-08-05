white = (255,255,255)
black = (0,0,0)
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)

class GameObject(object):
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def getPos(self):
		return (self.x, self.y)
	def setPos(self, x, y):
		self.x = x
		self.y = y

class GameBlock(GameObject):
	def __init__(self, x, y, width, height):
		super(GameBlock, self).__init__(x, y)
		self.width = width;
		self.height = height;
	def getRect():
		return (self.x, self.y, self.width, self.height)
	def setRect(x, y, width, height):
		self.x = x
		self.y = y
		self.width = width
		self.height = height
	def draw(surface):
		pygame.draw.rect(surface, green, self.getRect(), 0)

class GameTile(GameBlock):
	def __init__(self, x, y, width, height, tile):
		super(GameTile, self).__init__(x, y, width, height)
		self.tile = tile
	def getTile():
		return self.tile
	def setTile(tile):
		self.tile = tile
