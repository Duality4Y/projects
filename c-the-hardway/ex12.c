#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if(argc == 2)
	{
		printf("You only have one argument. you suck.\n");
	}
	else if(argc > 1 && argc < 4)
	{
		printf("Here's your arguments: \n");
		for(i = 1;i<argc;i++)
		{
			printf("%s ", argv[i]);
		}
		printf("\n");
	}
	else if(argc >= 4)
	{
		printf("You have to many arguments. You suck.\n");
	}
	else
	{
		printf("you didn't enter enough arguments\n");
	}
	return 0;
}
