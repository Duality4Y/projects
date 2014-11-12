import os, sys, math, pygame, pygame.mixer
import random
from pygame.locals import *

screen_size = screen_width, screen_height = 1900,1200

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

colors = [black, red, green, blue]

number_of_circles = 10
circles = []

for n in range(number_of_circles):
	size = random.randint(10,20)
	x = random.randint(size, screen_width-size)
	y = random.randint(size, screen_height-size)
	color = random.choice(colors)
	circles.append( Circle((x,y), size, color) )

screen = pygame.display.set_mode(screen_size, FULLSCREEN)

clock = pygame.time.Clock()
pygame.display.set_caption('First Class!')

fps_limit = 60
run_me = True
while run_me:
	clock.tick(fps_limit)
	
	for event in pygame.event.get():
		if event.type == pygame.QUIT or event.type == KEYDOWN:
			run_me = False
	screen.lock()
	screen.fill(white)
	for circle in circles:
		circle.display()
	screen.unlock()
	pygame.display.flip()

pygame.quit()
sys.exit()
