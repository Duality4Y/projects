#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	//go through each string in argv
	//why am i skipping argv[0]?
	//because that would be the name of you program ?
	//and we want to print parameter only ?
	for(i=1;i<argc;i++)
	{
		printf("arg %d: %s\n", i, argv[i]);
	}
	//lets make our own array of strings
	char *states[] = 
	{
		"California", "Oregon",
		argv[1], "Texas"
	};
	int num_states = 4;
	for(i = 0;i<num_states;i++)
	{
		printf("state %d: %s\n", i, states[i]);
	}
	return 0;
}
