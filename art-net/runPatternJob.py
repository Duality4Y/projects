import argparse, socket, time
import sys, os, imp

from artnet import buildPacket
from convert import convertSnakeModes

UDP_PORT = 6454

parser = argparse.ArgumentParser()
parser.add_argument("-d", "--delay", nargs="?", default=0.15, type=float)
parser.add_argument("-c", "--config", nargs="?", default="default_conf.py", type=str)
args = parser.parse_args()

#from configs import pattern_conf as config
if args.config == None:
	print "Please enter path to configuration --configs /path/to/config.py"
	sys.exit(1)

package = "configs"

fp, path, description = imp.find_module(package)
fp, path, description = imp.find_module(str(args.config)[:-3], [path])
config = imp.load_module("configuration", fp, path, description)
TARGETS = config.TARGETS

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, True)

while(True):
	for t in TARGETS:
		pattern = TARGETS[t]
		data = pattern.generate()
		data = convertSnakeModes(data, 10, 17)
		sock.sendto(buildPacket(0, data), (t, UDP_PORT))
	time.sleep(args.delay)
