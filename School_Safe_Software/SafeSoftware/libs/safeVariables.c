#define true 1
#define false 0

uint8_t ticks = 0; //keeps rotary ticks
volatile uint8_t tick_count = 0; //keeps actual count entered.
volatile uint8_t direction = 1; //keeps direction so we can keep track when to jump to the next number.
uint8_t prev_direction = 1;
//keep track of how many times the direction changes.
uint8_t direction_count = 0;

int pin = 8888; //the actuall pin.
int new_pin = 8888; //currently displayed pin.
//keep track of wheter someone is logged in or not.
uint8_t isLoggedIn = false;

