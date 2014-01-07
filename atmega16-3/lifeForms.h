//a struct holds the details about the life form
typedef struct 
{
	const uint8_t width;
	const uint8_t heigth;
	const uint8_t size;
	uint8_t *pattern;
} LifeForm;


/*
 * The Feather Light space ship. (or glider)
 * 
 * size = 9
 * width = 3
 * heigth = 3
 * */
 
const uint8_t glider_width = 3;
const uint8_t glider_heigth = 3;
const uint8_t glider_size = glider_width*glider_heigth;

uint8_t glider[glider_size] = 
{
	0,1,0,
	0,0,1,
	1,1,1,
};

LifeForm Glider = {glider_width, glider_heigth, glider_size, glider};

/*
 * The lightweight spaceship (or LWSS for short or small fish).
 * 
 * width = 5;
 * heigth = 5;
 * size = 25;
 * */

const uint8_t fish_width = 5;
const uint8_t fish_heigth = 4;
const uint8_t fish_size = fish_width*fish_heigth;

uint8_t fish[fish_size] = 
{
	0,1,0,0,1,
	1,0,0,0,0,
	1,0,0,0,1,
	1,1,1,1,0,
};

LifeForm Fish = {fish_width, fish_width, fish_size, fish};
