import serial
import io

port1 = "/dev/rfcomm1"
port2 = "/dev/rfcomm0"
baud = 4800
try:
	s = serial.Serial(port1, baud)
except:
	s = serial.Serial(port2, baud)

print "type break to exit."
while(True):
	command = raw_input(">> ")
	if(command == "break"):
		break
	else:
		command = int(command)
		print ">> send: "+str( ord( chr(command) ) )
		s.write(chr(command))
