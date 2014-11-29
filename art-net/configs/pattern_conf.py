#import all patterns availble for use.
from patterns.Patterns import *

led_ceiling_matrix_ip = "10.42.4.210"

TARGETS = {
	led_ceiling_matrix_ip:RainPattern(chance=0.2)
}
