import pygame,sys

class Circle(object):
	def __init__(self, screen):
		self.size = 10
		self.pos = (100,100)
		self.color = (0,255,0)
		self.screen = screen
	def draw(self):
		pygame.draw.circle(self.screen,self.color,self.pos, self.size, 1)
	def set_pos(self, x, y):
		self.pos = (x,y)

class Game(object):
	def __init__(self):
		pygame.init()
		self.screen = pygame.display.set_mode((500,500))
		self.circles = []
		self.circles.append(Circle(self.screen))
		pygame.display.set_caption("this")
		self.gameLoop()
	def update(self):
		pass
	def render(self):
		self.screen.fill((255,255,255))
		for circle in self.circles:
			circle.draw()
		pygame.display.update()
	def handleKeyboardMouse(self, event):
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				self.exit()
		elif event.type == pygame.KEYUP:
			pass
		elif event.type == pygame.MOUSEMOTION:
			pass
	def handleEvents(self):
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				self.exit()
			else:
				self.handleKeyboardMouse(event)
	def gameLoop(self):
		while True:
			self.handleEvents()
			self.update()
			self.render()
	def exit(self):
		pygame.quit()
		sys.exit(0)

if __name__ == "__main__":
	game = Game()
