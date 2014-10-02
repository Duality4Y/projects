#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*define a stack size limit*/
#define STACK_SIZE 100

void getUserInputString(char *input)
{
	printf(">> ");
	
	int index = 0;
	char value = getc(stdin);
	
	while(value != '\n')
	{
		/*put our input value into the input string*/
		input[index++] = value;
		/*make the last character a '\0'*/
		input[index] = '\0';
		/*read in out new value.*/
		value = getc(stdin);
	}
}

void push(int *stack, int *stackPointer, int value)
{
	if((*stackPointer) > STACK_SIZE)
	{
		puts("stack overflow");
	}
	else
	{
		stack[(*stackPointer)++] = value;
		stack[*stackPointer] = '\0';
	}
}

int pop(int *stack, int *stackPointer)
{
	int value;
	if(*stackPointer >= 0 )
	{
		value = stack[--(*stackPointer)];
		stack[*stackPointer] = '\0';
		return value;
	}
	else
	{
		puts("I think we got a stack underflow");
		return -1;
	}
	return -1;
}

void printStack(int *stack, int stackPointer)
{
	printf("stackPointer: %d \n", stackPointer);
	printf("stack: ");
	int i;
	for(i = 0;i< stackPointer;i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void testRun(int *stack, int stackPointer)
{
	printf("push R: %d \n", 'R');
	push(stack, &stackPointer, 'R');
	
	printf("push o: %d \n", 'o');
	push(stack, &stackPointer, 'o');
	
	printStack(stack, stackPointer);
	
	printf("pop: %d \n", pop(stack, &stackPointer));
	printStack(stack, stackPointer);
	
	printf("pop: %d \n", pop(stack, &stackPointer));
	printStack(stack, stackPointer);
}

int main(void)
{
	/*array that holds the input string*/
	char inputString[100] = "";
	int inputLength = 0;
	
	/*will hold values.*/
	int value_stack[STACK_SIZE] = {'\0'};
	int value_stackPointer = 0;
	
	/*will hold operators.*/
	int operator_stack[STACK_SIZE] = {'\0'};
	int operator_stackPointer = 0;
	
	int accumulator = 0;
	//push initial accumulator value onto the value stack
	push(value_stack, &value_stackPointer, accumulator);
	
	bool running = true;
	
	/*
	 * print some general info like usefull commands.
	 * like '>' for displaying accumulator value.
	 * and '^' for displaying stack contents.
	 */
	puts(">> Type <Stack> to display stack and it's contents.");
		
	while(running)
	{
		getUserInputString(inputString);
		inputLength = strlen(inputString);
		
		printf("Parsing \n");
		
		/*parse the input*/
		char *str = inputString;
		while(*str)
		{
			//are we dealing with a number ?
			if(isdigit(*str))
			{
				//in this way the value is stored in the stack
				accumulator = (pop(value_stack, &value_stackPointer)*10)+((*str)-'0');
				push(value_stack, &value_stackPointer, accumulator);
			}
			//print stack contents
			else if( (*str) == '>')
			{
				printf("<Value stack> \n");
				printStack(value_stack, value_stackPointer);
				printf("<Operator stack> \n");
				printStack(operator_stack, operator_stackPointer);
			}
			else// if( (*str) != '\0')
			{
				puts("input error");
			}
			str++;
		}
		//we are done with the original input?
		inputString[0] = '\0';
		/*
		int i;
		for(i = 0;i<inputLength;i++)
		{
			int token = inputString[i];
			//check for number and collect it in the accumulator
			if(token >= '0' && token <= '9')
			{
				accumulator = (accumulator*10)+(token-'0');
			}
			//if exit is typed we exit the program
			else if(!strcmp("exit", inputString))
			{
				running = false;
				break;
			}
			//print the stack for debugging
			else if(token == '^')
			{
				printf("<Value stack> \n");
				printStack(value_stack, value_stackPointer);
				printf("<Operator stack> \n");
				printStack(operator_stack, operator_stackPointer);
			}
			else
			{
				printf("input error %d \n", i);
				break;
			}
		}*/
		//testRun(stack, stackPointer);
	}
	
	return 0;
}
