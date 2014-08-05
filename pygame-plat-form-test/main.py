import pygame, sys
from pygame.locals import *
from GameObjects import *

block  = GameBlock(10,10,60,30);
gameBlocks = []
gameBlocks.append(block)

pygame.init()

windowSurface = pygame.display.set_mode((640,480))
pygame.display.set_caption("this is a game")

def drawObjects():
	for gameBlock in gameBlocks:
		gameBlocks.draw(windowSurface);

def main():
	pass

if __name__ == "__main__":
	main()
