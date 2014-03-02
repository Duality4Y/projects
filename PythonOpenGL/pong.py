import pygame, sys
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

from GameObject import GameObject

class Scene(object):
	def __init__(self):
		self.running = True
		self.screen = (800,600)
		pygame.init()
		self.title = "my game!"
		self.key = pygame.key.get_pressed()
		self.surface = pygame.display.set_mode(self.screen, pygame.OPENGL|pygame.DOUBLEBUF)
		pygame.display.set_caption(self.title)
		self.teapot = False
		pygame.key.set_repeat(3,40)
		
		self.rotateAngleX = 0.0
		self.rotateAngleY = 0.0
		self.rotateAngleZ = 0.0
		
		self.transX = 0.0
		self.transY = 0.0
		self.transZ = 0.0
		
		glutInit()
		
		self.light = True
		
		glEnable(GL_DEPTH_TEST)
		glDepthFunc(GL_LESS)
		glEnable(GL_TEXTURE_2D)
		glEnable(GL_COLOR_MATERIAL)
		glEnable(GL_LIGHTING)
		glEnable(GL_LIGHT0)
		glLightfv(GL_LIGHT0, GL_DIFFUSE, (1.0,1.0,1.0))
		glLightfv(GL_LIGHT0, GL_AMBIENT, (0.2,0.2,0.2))
		glLightfv(GL_LIGHT0, GL_SPECULAR, (1.0,1.0,1.0))
		glLightfv(GL_LIGHT0, GL_POSITION, (5.0,5.0,-3.0))
		
		self.objects = []
		
		obj = GameObject((200,200),(400,300), "image.png", 1.0)
		self.objects.append(obj)
		
		self.gameLoop()	
	def render(self):
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
		glClearColor(0.5,0.5,0.75,0.0)
		
		for obj in self.objects:
			obj.render(self.screen[0],self.screen[1])
		
		pygame.display.flip()		
	def update(self):
		for obj in self.objects:
			obj.update()
	def checkAngle(self, angle):
		if angle >= 360:
			angle -= 360
		if angle <= -360:
			angle += 360
		return angle
	def handleKeyboard(self,event):
		if event.key == pygame.K_ESCAPE:
			self.exit()
		if event.key == pygame.K_l:
			if self.light == True:
				self.light = False
				glDisable(GL_LIGHTING)
				glDisable(GL_LIGHT0)
			else:
				self.light = True
				glEnable(GL_LIGHTING)
				glEnable(GL_LIGHT0)
		if event.key == pygame.K_x:
			self.rotateAngleX += 10
		if event.key == pygame.K_y:
			self.rotateAngleY += 10
		if event.key == pygame.K_z:
			self.rotateAngleZ += 10
		
		if event.key == pygame.K_a:
			self.transX -= 0.05
		if event.key == pygame.K_d:
			self.transX += 0.05
		if event.key == pygame.K_w:
			self.transZ += 0.05
		if event.key == pygame.K_s:
			self.transZ -= 0.05
		if event.key == pygame.K_q:
			self.transY += 0.05
		if event.key == pygame.K_e:
			self.transY -= 0.05
		
		if event.key == pygame.K_c:
			self.teapot = not self.teapot
	def handleEvents(self):
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				self.exit()
			elif event.type == pygame.KEYDOWN:
				self.handleKeyboard(event)
	def gameLoop(self):
		self.clock = pygame.time.Clock()
		while self.running == True:
			self.clock.tick(60)
			pygame.display.set_caption(self.title+"- FPS: "+str(int(self.clock.get_fps())));
			self.handleEvents()
			self.update()
			self.render()
	def exit(self):
		pygame.quit()
		sys.exit()

if __name__ == "__main__":
	scene = Scene()
