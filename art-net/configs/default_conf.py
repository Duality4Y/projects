#import all patterns availble for use.
from patterns.Patterns import *

led_ceiling_matrix_ip = "10.42.4.5"

TARGETS = {
	#led_ceiling_matrix_ip:RainPattern(chance=0.4)
	led_ceiling_matrix_ip:BarberpolePattern()
}
