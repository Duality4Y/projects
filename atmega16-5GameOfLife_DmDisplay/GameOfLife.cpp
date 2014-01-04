/*
 * author Duality / Robert
 * edited: 03-01-2014
 * 
 * game of life implementation(c++)
 * here: http://rosettacode.org/wiki/Conway%27s_Game_of_Life/C
*/

//#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
//why can't i get it to just include the .h 
#include "DmDisplay/DmDisplay.cpp"

#define CELL(I,J) 	(field[size*(I)+(J)])
#define ALIVE(I,J) 	t[size*(I)+(J)] = 1
#define DEAD(I,J) 	t[size*(I)+(J)] = 0

const uint8_t cellSize = 2;
const uint8_t width = cellSize*5;
const uint8_t height = cellSize*5;
const uint8_t fieldSize = width*height;
uint8_t field[fieldSize];


DmDisplay lcd;
void clearField(uint8_t *field)
{
	uint8_t size = fieldSize;
	while(size--) field[size] = 0;
}

int count_alive(const char *field, int i, int j, int size)
{
	int x, y, a = 0;
	for(x=i-1;x<=(i+1);x++)
	{
		for(y=j-1;y<=(j+1);y++)
		{
			if((x==i) && (y==j)) continue;
			if((y<size) && (x<size) && (x>=0) && (y>=0))
			{
				a += CELL(x,y);
			}
		}
	}
	return a;
}

void evolve(const char *field, char *t, int size)
{
	int i, j, alive, cs;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			alive = count_alive(field, i, j, size);
			cs = CELL(i,j);
			if(cs)
			{
				if((alive > 3) || (alive < 2))
				{
					DEAD(i,j);
				}
				else
				{
					ALIVE(i,j);
				}
			}
			else
			{
				if(alive == 3)
				{
					ALIVE(i,j);
				}
				else
				{
					DEAD(i,j);
				}
			}
		}
	}
}

int main(void)
{
	clearField(field);
	while(1){}
	return 0;
}
