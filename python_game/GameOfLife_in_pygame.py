import pygame, sys, time, random
from life import *
from pygame.locals import *

pygame.init()

running = True
	
screenSize = (screenWidth,screenHeight) = (cellSize*2)*fieldWidth,(cellSize*2)*fieldHeight
screen = pygame.display.set_mode(screenSize)

x,y = 0,0

fpsClock = pygame.time.Clock()

RED = (255,0,0) #(red, green, blue)
GREEN = (0,255,0)
BLUE = (0,0,255)
WHITE = (255,255,255)
BLACK = (0,0,0)

cell_color = BLACK
background = WHITE

def copy_buffer(buffer,field):
	size = fieldSize
	while(size):
		size -= 1;
		field[size] = buffer[size];

def calc_xy(x,y,position):
	x = position%fieldWidth
	if((x) == 0):
		y+=1
		if(y>=(fieldHeight)):
			y = 0
	return x,y

def createRandomField(field):
	for i,cell in enumerate(field):
		field[i] = random.randint(0,1);
createRandomField(field)
while running:
	screen.fill(background)
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.KEYDOWN:
			createRandomField(field)
	
	for i,cell in enumerate(field):
		position = i
		if(field[position]):
			if(totalAround(field, position)==surviveAbility):
				buffer[position]=1
			elif(totalAround(field, position)==surviveAbility+1):
				buffer[position]=1
			else:
				buffer[position]=0
		else:
			#but if a position in the field is empty
			#and it has 3 around, that position becomes alife.

			if(totalAround(field, position)==reproductiveNumber):
				buffer[position] = 1
			else:
				buffer[position] = 0
		x,y = calc_xy(x,y,i)
		cellX, cellY = (x*cellSize*2)+cellSize, (y*cellSize*2)+cellSize
		if cell:
			pygame.draw.circle(screen,cell_color,(cellX,cellY),cellSize,1)
			
	copy_buffer(buffer,field)
	pygame.display.update()
	fpsClock.tick(30)
