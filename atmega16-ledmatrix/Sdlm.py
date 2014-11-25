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
	on = True
	off = False
	isSetOn = False
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
		
		self.rect = (self.x, self.y, self.width, self.height)
		
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

#data to matrix translation class.
#also does data transmission
class SDLM(object):
	def __init__(self):
		try:
			self.serial_port = serial.Serial(com_device, com_baud)
		except serial.SerialException:
			print "No device found on: %s" % com_device
			self.serial_port = None
		self.display_data = [0]*matrix_width
	def send(self):
		if self.serial_port == None:
			return
		for byte in self.display_data:
			self.serial_port.write(chr(byte))
	def setPixel(self, x, y, isSet):
		x_index = x/(window_width/matrix_width)
		y_index = y/(window_height/matrix_height)
		self.display_data[y_index] |= (isSet << (x_index))
	def invertPixel(self, x, y):
		x_index = x/(window_width/matrix_width)
		y_index = y/(window_height/matrix_height)
		self.display_data[y_index] ^= (1<<x_index)
	def setAllPixels(self):
		self.display_data = [0xff]*matrix_width
	def clearAllPixels(self):
		self.display_data = [0]*matrix_width
	def invertPixels(self):
		for index,byte in enumerate(self.display_data):
			self.display_data[index] ^= 0xff
	def close(self):
		if self.serial_port == None:
			return
		self.serial_port.close()

class Demo(object):
	leftMpressed = False
	rightMpressed = False
	showPixelMouse = False
	running = True
	def __init__(self):
		self.matrix_screen = SDLM()
		
		self.surface = pygame.display.set_mode((window_width, window_height))
		self.fpsClock = pygame.time.Clock()
		self.FPS = 30
		
		self.pixels = []
		width_range = xrange(0, window_width, window_width/matrix_width)
		height_range = xrange(0, window_height, window_height/matrix_height)
		
		for y in height_range:
			for x in width_range:
				self.pixels.append( Pixel((x, y), black, self.surface))
		
		pygame.init()
	def eventHandling(self, event):
		if event.type == pygame.QUIT:
			self.running = False
		if event.type == pygame.KEYDOWN:
			pass
		if event.type == pygame.MOUSEBUTTONDOWN:
			pass
		if event.type == pygame.MOUSEBUTTONUP:
			pass
	def process(self):
		#take action uppon events.
		if self.leftMpressed:
			pass
		if self.rightMpressed:
			pass
		if self.showPixelMouse:
			pass
		#send out our data
		SDLM.send()
	def draw(self):
		#fill a background with black
		self.surface.fill(black)
		#draw pixels over it.
		for pixel in self.pixels:
			pixel.draw()
		#update the screen and wait a bit (for the amount of self.fps)
		pygame.display.update()
		self.fpsClock.tick(self.FPS)
	def run(self):
		while self.running:
			break;
	def close(self):
		self.matrix_screen.close()
		pygame.quit()

demoScreen = Demo()
demoScreen.close()
