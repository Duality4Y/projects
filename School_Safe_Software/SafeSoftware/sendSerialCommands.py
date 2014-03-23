import serial
import io

port = "/dev/rfcomm0"
baud = 4800

s = serial.Serial(port, baud)
print "type break to exit."
while(True):
	command = raw_input(">> ")
	if(command == "break"):
		break
	else:
		command = int(command)
		print ">> send: "+str( ord( chr(command) ) )
		s.write(chr(command))
		"""
		try:
			print ">> recieved: %d" % ord(s.read(size=1))
		except TypeError, ValueError:
			print ">> invalid input."
		"""
