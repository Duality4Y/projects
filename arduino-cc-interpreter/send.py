import serial
import time
ser = serial.Serial("/dev/rfcomm0", 9600)


image = [
"                    "
"        ____        "
"       (  _ \       "
"        )   /       "
"       (__\_)       "
"                    "
]

rob = [
"                    "
" ___     _          "
"| _ \___| |__  ___  "
"|   / _ \ '_ \/ -_) "
"|_|_\___/_.__/\___| "
"                    "
]

text = [
	"here is a lot of text to send it's gonna need to be more then will fit on to the screen lol"
	" it has still gotta be more cause it still does fit on it"
]

def sendTest():
	for c in text:
		ser.write(c)
	"""
	ser.write(chr(128))
	for i in range(0,119):
		ser.write('A')
	ser.write('|')
	"""

def sendReady():
	ser.write(chr(128))

def senR():
	sendReady()
	#ser.write(image[0])
	ser.write(rob[0])
	#for character in image:
	#	ser.write(character)
senR()
#sendTest()
