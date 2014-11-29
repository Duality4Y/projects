import argparse, socket, time
import imp

from artnet import buildPacket
from convert import convertSnakeModes

from patterns import matrix_width, matrix_height

UDP_PORT = 6454

parser = argparse.ArgumentParser()
parser.add_argument("-d", "--delay", help="controlle flow speed.", metavar="<delay>", nargs="?", default=0.15, type=float)
parser.add_argument("-c", "--config", help="load config.", metavar="<config_conf.py>", nargs="?", default="default_conf.py", type=str)
args = parser.parse_args()

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
		data = convertSnakeModes(data, matrix_width, matrix_height)
		sock.sendto(buildPacket(0, data), (t, UDP_PORT))
	time.sleep(args.delay)
