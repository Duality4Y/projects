import os, sys, math, pygame, pygame.mixer
from pygame.locals import *

class Circle(object):
	def __init__(self, (x,y), size, color = (255,255,255), width = 1):
		self.x = x
		self.y = y
		self.size = size
		self.color = color
		self.width = width
	
	def display(self):
		pygame.draw.circle(screen, self.color, (self.x, self.y), self.size, self.width)

black = 0,0,0
white = 255, 255, 255
red = 255,0,0
green = 0,255,0
blue = 0,0,255

screen_size = screen_width, screen_height = 600,400

screen = pygame.display.set_mode(screen_size)

clock = pygame.time.Clock()
pygame.display.set_caption('First Class!')

circle1 = Circle((100,100), 10, red)
circle2 = Circle((200,200), 30, blue)
circle3 = Circle((300,150), 40, green, 40)
circle4 = Circle((450, 250), 120, black, 0)

fps_limit = 60
run_me = True
while run_me:
	clock.tick(fps_limit)
	
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			run_me = False
	
	screen.fill(white)
	circle1.display()
	circle2.display()
	circle3.display()
	circle4.display()
	pygame.display.flip()

pygame.quit()
sys.exit()
