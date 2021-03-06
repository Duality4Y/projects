#!/usr/bin/python

import random, sys
#import patters here if they are in a different file.
from RainPattern import RainPattern
from PolicePattern import PolicePattern

# Barberpole pattern was originally made in C by Duality
class BarberpolePattern:
	# Rotating stripes of certain colors, default red/white
	def __init__(self, backwards=False, color1=(255, 0, 0), color2=(20, 20, 20)):
		self.backwards = backwards
		self.color1 = color1
		self.color2 = color2
		self.pos = 0
		
		self.width = 10
		self.height = 17
		self.size = self.width*self.height
	def generate(self):
		data = []
		if self.backwards:
			leds = xrange(self.size, 0, 1)
		else:
			leds = xrange(0, self.size, 1)
		for i in leds:
			place = (i % self.width) + self.pos
			if (place >= self.width):
				place -= self.width
			if (place < self.width/2):
				data.append(self.color1)
			else:
				data.append(self.color2)
		self.pos += 1
		if (self.pos >= self.width):
			self.pos = 0
		return data

class ColorFadePattern:
	# Integral color shifting
	def __init__(self):
		self.phase = 0
		self.phasetable = [
			(255,   0,   0),
			(255,  64,   0),
			(255, 128,   0),
			(255, 192,   0),
			(255, 255,   0),
			(192, 255,   0),
			(128, 255,   0),
			( 64, 255,   0),
			(  0, 255,   0),
			(  0, 192,   0),
			(  0, 192,  64),
			(  0, 192, 128),
			(  0, 255, 192),
			(  0, 255, 255),
			(  0, 192, 255),
			(  0, 128, 255),
			(  0,   0, 255),
			( 64,   0, 255),
			(128,   0, 255),
			(192,   0, 255),
			(255,   0, 255),
			(255, 128, 255),
			(255, 255, 255),
			(255, 255, 128),
			(255, 128, 128),
			(255, 128,   0),
		]

	def generate(self):
		data = []
		for i in xrange(170):
			r, g, b = self.phasetable[int(self.phase)]
			data.append((r, g, b))
		self.phase += 1
		if (self.phase >= len(self.phasetable)):
			self.phase = 0
		return data
