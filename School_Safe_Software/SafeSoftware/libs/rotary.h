
volatile uint8_t ticks = 0; //keeps rotary ticks
volatile uint8_t tick_count = 0; //keeps actual count entered.
volatile uint8_t previous_ticks = 0;
volatile uint8_t direction = 1; //keeps direction so we can keep track when to jump to the next number.
volatile uint8_t rotary_has_turned = 0;
uint8_t prev_direction = 0;
//keep track of how many times the direction changes.
uint8_t direction_count = 0;

void initRotary();
