import serial
import pygame

white = (255,255,255)
black = (0,0,0)
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)

window_width = 400
window_height = 400
matrix_width = 8
matrix_height = 8

com_baud = 500000
com_device = '/dev/ttyUSB0'

#a basic pixel class for drawing pixel representations onto the screen.
class Pixel(object):
	#"global variable" for the class Pixel
	self.on = True
	self.off = False
	self.isSetOn = False
	#initialization setting up some usefull variables.
	def __init__(self, pos, color, surface, inColor = red):
		self.normalColor = color
		self.inColor = inColor
		
		self.width = window_width/matrix_width
		self.height = window_height/matrix_height
		
		self.pos = pos
		self.x,self.y = self.pos
		self.x_index = self.x/self.width
		self.y_index = self.y/self.height
		
		self.rect = (self.x, self.y, self.width, sefl.height)
		
		self.surface = surface
		
	#function handle for drawing the pixel onto self.surface.
	def draw(self):
		if(self.isSetOn):
			pygame.draw.rect(self.surface, self.inColor, self.rect, 0)
		else:
			pygame.draw.rect(self.surface, self.normalColor, self.rect, 0)
		pygame.draw.rect(self.surface, white, self.rect, 1)
	#check if mouse inside the pixel area, and set the onState accordingly
	def inPixel(self, pos):
		x,y = pos
		if (x > self.x) and (x < self.x+self.width)		\
			and (y > self.y) and (y < self.y+self.height):
				return True
		else:
			return False
	#toggles the pixel on/off state
	def togglePixel(self):
		self.isSetOn = not self.isSetOn
	#can be used to set the pixel on or off
	def setPixel(self, state):
		self.isSetOn = state

#the app class.
#Serial Display Led Matrix
class SDLM(object):
	#states for event handling
	#mouse states:
	self.leftMpressed = False
	self.rightMpressed = False
	#state that whill determine
	#if a mouse to be showed on the ledmatrix:
	self.showPixelMouse = False
	#game loop condition:
	self.running = True
	def __init__(self):
		#create a surface to draw on
		self.surface = pygame.display.set_mode((window_width, window_height))
		#create a fps clock object (to limit cpu time more)
		self.fpsClock = pygame.time.Clock()
		
		#create ranges to make itteration easier (divide plane into junks over with and height)
		self.width_range = xrange(0, window_width, window_width/matrix_width)
		self.height_range = xrange(0, window_height, window_height/matrix_height)
		
		#create a empty list for keeping track on our pixels
		self.pixels = []
		
		#itterate over the list and fill in the pixels
		for y in height_range:
			for x in width_range:
				self.pixels.append( Pixel((x,y), black, self.surface) )
		
		#creat a list with 0's in it that we will use to calculate pixel positions
		#for the ledmatrix.
		self.display_bytes = [0]*matrix_width
		
		#initialize pygame
		pygame.init()
		
		#open a serial connection
		self.serial_port = serial.Serial(com_device, com_baud)
	def eventHandling(self, event):
		#if x pressed quit the app
		if event.type == pygame.QUIT:
			self.running = False
		if event.type == pygame.KEYDOWN:
			#if the escape key pressed quit the app
			if event.key == pygame.K_ESCAPE:
				running = False
			#enable showing mouse position on the ledmatrix.
			if event.key == pygame.K_m:
				self.showPixelMouse = not self.showPixelMouse
			#r for resetting all the pixels. (turning them all off)
			if event.key == pygame.K_r:
				for pixel in self.pixels:
					pixel.isSetOn = False
			#s for setting all the pixels. (turning them all on)
			if event.key == pygame.K_s:
				for pixel in self.pixels:
					pixel.isSetOn = True
			#i for inversing all the pixels. (if on turn off and vice versa)
			if event.key == pygame.k_i:
				for pixel in self.pixels:
					pixel.isSetOn = not pixels.isSetOn
	def close(self):
		pygame.quit()
		self.serial_port.close()
	def run(self):
		
