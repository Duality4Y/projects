import pygame, sys
from pygame.locals import *
from GameObject import *
import time

pygame.init()

width,height = 1200,700
size = (width, height)

screen = pygame.display.set_mode(size)

test1 = Testy([0,0],[60,90],(200,200))
running = True

Mx = 0
My = 0

while running:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == KEYDOWN:
			if event.key == K_ESC:
				running = False
		if event.type == MOUSEMOTION:
			Mx,My = event.pos
	screen.fill((255,255,255))
	#test1.draw(screen)
	test1.drawSheet(screen)
	pygame.draw.rect(screen,(0,0,0),test1.getRect(),1)
	pygame.display.flip()
	time.sleep(1)
pygame.quit()
