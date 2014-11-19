import serial
import pygame

#create some colors
white = (255,255,255)
black = (0,0,0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

window_width = 400
window_height = 400
#atari 2600 width = 160 height = 192
matrix_width = 8
matrix_height = 8

#create a surface to draw on.
window_surface = pygame.display.set_mode((window_width, window_height));

fpsClock = pygame.time.Clock()

#open a serial port for communication.
com_baud = 500000
com_device = '/dev/ttyUSB0'
serial_port = serial.Serial(com_device, com_baud)

class Pixel(object):
	#initialization setting up some usefull variables.
	def __init__(self, pos, color, surface):
		self.normalColor = color
		self.inColor = red
		
		self.width = window_width/matrix_width
		self.height = window_height/matrix_height
		
		self.pos = pos
		self.x, self.y = self.pos
		self.x_index = self.x/self.width
		self.y_index = self.y/self.height
		
		self.rect = (self.x, self.y, self.width, self.height)
		
		self.surface = surface
		
		self.isSetOn = False
	#drawing function, draws one color if it's set to on.
	#and another if it's set to off.
	def draw(self):
		if(self.isSetOn):
			pygame.draw.rect(self.surface, self.inColor, self.rect, 0)
		else:
			pygame.draw.rect(self.surface, self.normalColor, self.rect, 0)
		pygame.draw.rect(self.surface, white, self.rect, 1)
	#checks if pos is inside the pixel, and changes state acording to that.
	def inPixel(self, pos):
		x,y = pos
		if (x > self.x) and (x < self.x+self.width)		\
			and (y > self.y) and (y < self.y+self.height):
				if(self.isSetOn):
					self.isSetOn = False
				else:
					self.isSetOn = True

#create an empty list fill it with width_range*height_range amount of pixels.
pixels = []
width_range = xrange(0, window_width, window_width/matrix_width)
height_range = xrange(0, window_height, window_height/matrix_height)

for y in height_range:
	for x in width_range:
		pixels.append(Pixel((x,y), black, window_surface))

#an list that will hold bytes that are send to the display
display_byte_data = [0]*matrix_width

#hold mouse button states.
leftMpressed = False
rightMpressed = False

#holds state for showing a "pixel" mouse on the led matrix or not
showPixelMouse = False

#initialize pygame.
pygame.init()
running = True
while running:
	pygame.event.pump()
	for event in pygame.event.get():
		#quit the pygame app if x pressed
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.KEYDOWN:
			#or quit if the escape key was pressed.
			if event.key == pygame.K_ESCAPE:
				running = False
			#enable showing mouse position on the ledmatrix
			if event.key == pygame.K_m:
				showPixelMouse = not showPixelMouse
			#r for reseting all the pixels. (turning them off)
			if event.key == pygame.K_r:
				for pixel in pixels:
					pixel.isSetOn = False
			#s for setting all the pixels. (turning them all on)
			if event.key == pygame.K_s:
				for pixel in pixels:
					pixel.isSetOn = True
			#i for inversing all the pixels. the ones that are on become off and vice versa
			if event.key == pygame.K_i:
				for pixel in pixels:
					pixel.isSetOn = not pixel.isSetOn
		#if event.type == pygame.KEYUP:
			#disable showing "pixel" mouse position on ledmatrix
			#if event.key == pygame.K_m:
			#	showPixelMouse = False
		#mouse button checking. and state setting.
		if event.type == pygame.MOUSEBUTTONDOWN:
			if event.button == 1:
				leftMpressed = True
			if event.button == 3:
				rightMpressed = True
		if event.type == pygame.MOUSEBUTTONUP:
			if event.button == 1:
				leftMpressed = False
			if event.button == 3:
				rightMpressed = False
	
	"""
		if the left mouse button is pressed and the pixel is not filled.
		fill it.
		else if the right button is pressed erase the pixel. (unfill it )
	"""
	if leftMpressed:
		mouse_pos = pygame.mouse.get_pos()
		for pixel in pixels:
			if not pixel.isSetOn:
				pixel.inPixel(mouse_pos)
	elif rightMpressed:
		mouse_pos = pygame.mouse.get_pos()
		for pixel in pixels:
			if pixel.isSetOn:
				pixel.inPixel(mouse_pos)
	
	
	window_surface.fill(black)
	
	#draw all the pixels to the screen.
	for pixel in pixels:
		pixel.draw()
	
	#make the list empty (nothing displayed)
	#do some math create bytes depending on thier position and if they are on or not.
	display_byte_data = [0]*matrix_width
	for index,pixel in enumerate(pixels):
		display_byte_data[pixel.y_index] |= (pixel.isSetOn << (pixel.x_index) )
	
	#show a "pixel" mouse if m is/was pressed once
	if showPixelMouse:
		mx,my = pygame.mouse.get_pos()
		mx_index = mx/(window_width/matrix_width)
		my_index = my/(window_height/matrix_height)
		#print mx,my,mx_index,my_index
		display_byte_data[my_index] ^= (1<<mx_index)
	
	#transmit the screen over serial.
	for byte in display_byte_data:
		serial_port.write(chr(byte))
	
	#pygame updates the screen so we can also see the pixels on our screen.
	pygame.display.update()
	#make pygame wait 30 ticks (30 fps or 1/30 seconds). for conserving cpu.
	fpsClock.tick(30)

#always close serial port.
serial_port.close()
#and give free the resources pygame was using.
pygame.quit()

