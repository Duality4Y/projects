#include <stdio.h>

int main(int argc, char *argv[])
{
	//go through each string in argv
	int i = argc;
	while(i)
	{
		i--;
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	//let's make our own array of strings
	char *states[] = 
	{
		"California", "Oregon",
		"Washington", "Texas"
	};
	i = 0;
	while(i < argc)
	{
		states[i] = argv[i];
		i++;
		if(i >= 4)
		{
			break;
		}
	}
	*(argv+1) = "t";
	int num_states = 4;
	i = 0;
	while(i<num_states)
	{
		printf("state %d: %s\n", i, states[i]);
		i++;
	}
	
	return 0;
}
