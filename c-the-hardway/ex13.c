/*a comment*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int argcount = 0;
	char letter = 0;
	
	if(argc < 2)
	{
		printf("ERROR: You need one or more arguments.\n");
		return 1;//return 1 for exiting without succes.
	}
	
	//argcount = 1 because first argument is program name.
	for(argcount = 1;argcount < argc;argcount++)
	{
		printf("argument: %d\n", argcount);
		for(i = 0, letter = 0;(argv[argcount][i] != '\0');i++)
		{
			letter = argv[argcount][i];
			switch(letter)
			{
				case 'a':
				case 'A':
					printf("%d: 'A'\n", i);
					break;
				case 'e':
				case 'E':
					printf("%d: 'E'\n", i);
					break;
				case 'i':
				case 'I':
					printf("%d: 'I' \n", i);
					break;
				case 'o':
				case 'O':
					printf("%d: 'O' \n", i);
					break;
				case 'u':
				case 'U':
					printf("%d: 'U' \n", i);
					break;
				case 'y':
				case 'Y':
					if(i > 2)
					{
						//it's only sometimes y
						printf("%d: 'Y' \n", i);
					}
					break;
				default:
					printf("%d: %c is not a vowel\n", i, letter);
					break;
			}
		}
		printf("\n");
	}
	return 0;
}
