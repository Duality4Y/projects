import serial
import pygame

white = (255,255,255)
black = (0,0,0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

window_width = 800
window_height = 800
#atari 2600 width = 160 height = 192
matrix_width = 8
matrix_height = 8

window_surface = pygame.display.set_mode((window_width, window_height));

class Pixel(object):
	def __init__(self, pos, color, surface):
		self.normalColor = color
		self.inColor = blue
		self.pos = pos
		self.width = window_width/matrix_width
		self.height = window_height/matrix_height
		self.x, self.y = self.pos
		self.rect = (self.x, self.y, self.width, self.height)
		self.surface = surface
		self.isSetOn = False
	def draw(self):
		if(self.isSetOn):
			pygame.draw.rect(self.surface, self.inColor, self.rect, 0)
		else:
			pygame.draw.rect(self.surface, self.normalColor, self.rect, 0)
		pygame.draw.rect(self.surface, white, self.rect, 1)
	def inPixel(self, pos):
		mx,my = pos
		if (mx > self.x) and (mx < self.x+self.width)		\
			and (my > self.y) and (my < self.y+self.height):
				if(self.isSetOn):
					self.isSetOn = False
				else:
					self.isSetOn = True

pixels = []
width_range = xrange(0, window_width, window_width/matrix_width)
height_range = xrange(0, window_height, window_height/matrix_height)

for y in height_range:
	for x in width_range:
		pixels.append(Pixel((x,y), green, window_surface))

pixel_data = []

pygame.init()
running = True
while running:
	pygame.event.pump()
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.MOUSEBUTTONDOWN:
			mouse_pos = pygame.mouse.get_pos()
			for pixel in pixels:
				pixel.inPixel(mouse_pos)
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				running = False
	
	window_surface.fill(black)
	
	for pixel in pixels:
		pixel.draw()
	
	pygame.display.update()

pygame.quit()
