import pygame, sys
from pygame.locals import *
from GameObjects import *

#mob  = companionCube(10,10,16,33, None);
mob = companionCube(100, 100, 25, 25, None);
gameobjects = []
gameobjects.append(mob)
for i in range(0,window_width/2, tile_width):
	tile = GameTile(i,(window_height/2)-tile_height, tile_width, tile_height, None)
	gameobjects.append(tile)
gameobjects.append(GameTile(200,150, 40, 40, None))

pygame.init()

windowSurface = pygame.display.set_mode((640,480))
pygame.display.set_caption("this is a game")

fpsClock = pygame.time.Clock()

def drawObjects(surface):
	for gameobject in gameobjects:
		gameobject.draw(surface)

def handleEvents(event):
	for gameobject in gameobjects:
		gameobject.handleEvents(event)

def handleColitions():
	for gameobject in gameobjects:
		gameobject.handleCollisions(gameobjects)

def updateObjects():
	for gameobject in gameobjects:
		gameobject.update()

def main():
	running = True
	while running:
		windowSurface.fill(black)
		for event in pygame.event.get():
			if event.type == QUIT:
				running = False
			else:
				handleEvents(event)
		handleColitions()
		updateObjects()
		drawObjects(windowSurface)
		pygame.display.update()
		fpsClock.tick(60)
	pygame.quit()

if __name__ == "__main__":
	main()
