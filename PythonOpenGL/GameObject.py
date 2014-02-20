import pygame
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

class GameObject(object):
	def __init__(self, size, position, texture, scale):
		self.genTexture(texture)
		self.pos = position
		self.size = size
		self.texturePath = texture
		self.scale = scale
	def genTexture(self, filename):
		img = pygame.image.load(filename)
		img.convert_alpha()
		
		data = pygame.image.tostring(img, "RGBA", False)
		
		self.texture = glGenTextures(1)
		glBindTexture(GL_TEXTURE_2D, self.texture)
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img.get_width(), img.get_height(), GL_RGBA, GL_UNSIGNED_BYTE, data)
		
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR)
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
	
	def update(self):
		pass
	def render(self, width, height):
		pass
	
