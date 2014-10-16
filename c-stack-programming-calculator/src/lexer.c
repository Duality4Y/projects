#include "lexer.h"

void getInput(char *buf)
{
	unsigned index = 0;
	int value = getc(stdin);
	while(value != '\n') //while we are not at the end of a line
	{
		//if value is printable put it in inputstring
		if(isprint(value))
		{
			buf[index++] = value;
			buf[index] = '\0'; //always nul terminate our string.
		}
		//get our next value.
		value = getc(stdin);
	}
	printf("input: \n%s \n", buf);
}

Token_t* getTokens(void)
{
	getInput(inputString);
	return NULL;
}
