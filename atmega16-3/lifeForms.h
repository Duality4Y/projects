//a struct holds the details about the life form
typedef struct 
{
	uint8_t width;
	uint8_t heigth;
	uint8_t size;
	uint8_t *pattern;
} LifeForm;


/*
 * a walker
 * size = 9
 * width = 3
 * heigth = 3
 * */
uint8_t walker[9] = 
{
	0,1,0,
	0,0,1,
	1,1,1,
};

LifeForm Walker {3, 3,3*3, 0};
