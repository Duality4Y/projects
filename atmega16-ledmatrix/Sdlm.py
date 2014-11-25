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
	#get pixel state
	def getState(self):
		return self.isSetOn
	#toggles the pixel on/off state
	def toggleState(self):
		self.isSetOn = not self.isSetOn
	#can be used to set the pixel on or off
	def setState(self, state):
		self.isSetOn = state
	def getPos(self):
		return self.pos
	def getIndexPos(self):
		return (self.x_index, self.y_index)

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
	def setPixel(self, pos):
		x, y = pos
		self.display_data[y] |= (1 << (x))
	def clearPixel(self, pos):
		x,y = pos
		self.display_data[y] &= ~(1 << (x))
	def togglePixel(self, pos):
		x, y = pos
		self.display_data[y] ^= (1<<x)
	def setAllPixels(self):
		self.display_data = [0xff]*matrix_width
	def clearAllPixels(self):
		self.display_data = [0]*matrix_width
	def togglePixels(self):
		for index,byte in enumerate(self.display_data):
			self.display_data[index] ^= 0xff
	def getPixel(self, pos):
		x,y = pos
		state = self.display_data[y] & (1<<x)
		return state
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
			#quit if escape pressed
			if event.key == pygame.K_ESCAPE:
				self.running = False
			#enable showing mouse position on ledmatrix
			if event.key == pygame.K_m:
				self.showPixelMouse = not self.showPixelMouse
			#r for reseting all the pixels. (turning them off)
			if event.key == pygame.K_r:
				for pixel in self.pixels:
					pixel.setState(pixel.off)
			#s for setting all the pixels. (turning them all on)
			if event.key == pygame.K_s:
				for pixel in self.pixels:
					pixel.setState(pixel.on)
			#i for inversing. turning leds that are on.
			if event.key == pygame.K_i:
				for pixel in self.pixels:
					pixel.toggleState()
		#left mouse button = 1
		#right mouse button = 3
		#midle mouse button = 2
		if event.type == pygame.MOUSEBUTTONDOWN:
			if event.button == 1:
				self.leftMpressed = True
			if event.button == 3:
				self.rightMpressed = True
		if event.type == pygame.MOUSEBUTTONUP:
			if event.button == 1:
				self.leftMpressed = False
			if event.button == 3:
				self.rightMpressed = False
	def process(self):
		mouse_pos = pygame.mouse.get_pos()
		#take action uppon events.
		self.matrix_screen.clearAllPixels()
		#if the left mouse button is pressed fill the pixel it's on.
		if self.leftMpressed:
			for pixel in self.pixels:
				if pixel.getState() == pixel.off and pixel.inPixel(mouse_pos):
					pixel.toggleState()
		#if the right mouse button is pressed switch the pixel it's on off.
		if self.rightMpressed:
			for pixel in self.pixels:
				if pixel.getState() == pixel.on and pixel.inPixel(mouse_pos):
					pixel.toggleState()
		
		#translate Pixels into matrix_screen data
		for pixel in self.pixels:
			if pixel.getState():
				self.matrix_screen.setPixel(pixel.getIndexPos())
		
		#overlay our mouse on the matrix data
		#if this option is enabled (m pressed) show a mouse on the ledmatrix display.
		if self.showPixelMouse:
			mx,my = pygame.mouse.get_pos()
			mx_index = mx/(window_width/matrix_width)
			my_index = my/(window_height/matrix_height)
			self.matrix_screen.togglePixel( (mx_index, my_index) )
		
		#send out our data
		self.matrix_screen.send()
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
			pygame.event.pump()
			for event in pygame.event.get():
				self.eventHandling(event)
			self.process()
			self.draw()
	def close(self):
		self.matrix_screen.close()
		pygame.quit()

demoScreen = Demo()
demoScreen.run()
demoScreen.close()
