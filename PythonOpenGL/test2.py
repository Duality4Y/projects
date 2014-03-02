import pygame, sys
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

class Scene(object):
	def __init__(self):
		self.running = True
		self.screen = (500,500)
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
		
		self.genTexture("image.png")
		
		self.gameLoop()
	def genTexture(self, filename):
		img = pygame.image.load(filename)
		img.convert_alpha()
		
		data = pygame.image.tostring(img, "RGBA", False)
		
		self.texture = glGenTextures(1)
		glBindTexture(GL_TEXTURE_2D, self.texture)
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img.get_width(), img.get_height(),GL_RGBA, GL_UNSIGNED_BYTE, data)
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR)
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
		
		
	def render(self):
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
		glClearColor(0.5,0.5,0.75,0.0)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()	
		gluPerspective(45.0, 1.0,1.0, 15.0)
		gluLookAt(0,2,5,0,0,-1,0,1,0)
		
		glTranslatef(self.transX, self.transY, self.transZ)
		glPushMatrix()
		
		glRotatef(self.rotateAngleX, 1, 0, 0)
		glPushMatrix()
		glRotatef(self.rotateAngleY, 0, 1, 0)
		glPushMatrix()
		glRotatef(self.rotateAngleZ, 0, 0, 1)
		glPushMatrix()
		
		self.geometry()
		
		glPopMatrix()
		glPopMatrix()
		glPopMatrix()
		glPopMatrix()
		
		pygame.display.flip()
		
	def geometry(self):
		if self.teapot:
			glutSolidTeapot(1)
		else:
			self.rectAngle()
	def rectAngle(self):
		glBegin(GL_QUADS)
		
		glNormal3f(0.0, 1.0, 0.0)
		glTexCoord2f(0.0,0.0)
		glVertex3f(-1,1,-1)
		
		
		glTexCoord2f(1.0,0.0)
		glVertex3f(1,1,-1)
		
		
		glTexCoord2f(1.0,1.0)
		glVertex3f(1,-1,-1)
		
		
		glTexCoord2f(0.0,1.0)
		glVertex3f(-1,-1,-1)
		
		
		
		glEnd()
		
	def update(self):
		self.rotateAngleX = self.checkAngle(self.rotateAngleX)
		self.rotateAngleY = self.checkAngle(self.rotateAngleY)
		self.rotateAngleZ = self.checkAngle(self.rotateAngleZ)
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
