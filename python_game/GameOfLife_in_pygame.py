import pygame, sys, time, random
from life import *
from pygame.locals import *

pygame.init()

life = Life(1600,1200);

running = True
	
#screenSize = (screenWidth,screenHeight) = (cellSize)*fieldWidth,(cellSize)*fieldHeight
screenSize = life.getSize();
screen = pygame.display.set_mode(screenSize, (FULLSCREEN|DOUBLEBUF|HWSURFACE))

fpsClock = pygame.time.Clock()

RED = (255,0,0) #(red, green, blue)
GREEN = (0,255,0)
BLUE = (0,0,255)
WHITE = (255,255,255)
BLACK = (0,0,0)
background = BLACK
life.setCellColor(WHITE)
cellSize = 10;
paused = False
while running:
	screen.fill(background)
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				running = False
			elif event.key == pygame.K_a:
				cellSize += 1;
				life.setCellSize(cellSize)
			elif event.key == pygame.K_b:
				cellSize -= 1;
				if cellSize == 0:
					cellSize = 1
				life.setCellSize(cellSize)
			if event.key == pygame.K_SPACE:
				if paused:
					paused = False
				else:
					paused = True
			else:
				life.createRandomField()
	if not paused:
		life.processLife(screen)
	pygame.display.update();
	fpsClock.tick(10);
pygame.quit()
