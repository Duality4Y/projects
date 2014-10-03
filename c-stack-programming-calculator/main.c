#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*define a stack size limit*/
#define STACK_SIZE 100

char isOperator(char character)
{
	if(character == '+' || character == '-' || character = '/' || character = '*')
		return 1;
	else
		return 0;
	return 0;
}

void getUserInputString(char *input)
{
	printf(">> ");
	
	int index = 0;
	char value = getc(stdin);
	
	while(value != '\n')
	{
		/*put our input value into the input string*/
		input[index] = value;
		/*make the last character a '\0'*/
		input[++index] = '\0';
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
	
	bool wasNumber = false;
	
	bool running = true;
	
	/*
	 * print some general info like usefull commands.
	 * and '>' for displaying stack contents.
	 */
	puts("\nInput '>' to display stack and it's contents.");
		
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
				//extract that number
				while(isdigit(*str))
				{
					//use the accumulator to store and modify the number.
					accumulator = (accumulator*10)+((*str)-'0');
					str++;
				}
				//push that number onto the value stack
				push(value_stack, &value_stackPointer, accumulator);
				//reset the accumulator
				accumulator = 0;
				printf("now: %c \n", *str);
				str-=1; //if not set back by one there is a bug that it skips the next
				//character since at the end of controle we advance one and thus skip.
			}
			//print stack contents
			else if( (*str) == '>')
			{
				printf("<Value stack> \n");
				printStack(value_stack, value_stackPointer);
				printf("<Operator stack> \n");
				printStack(operator_stack, operator_stackPointer);
			}
			//push operators onto the stack
			else if(isOperator(*str))
			{
				push(operator_stack, &operator_stackPointer, *str);
			}
			//if e is enterd the program exits.
			else if((*str) == 'e')
			{
				running = false;
				break;
			}
			else
			{
				puts("input error");
			}
			str++;
		}
		//still have to implement the process function (which does the actual calculating)
		//after processing we clear the stacks.
		//and we clear the original input string.
		memset(value_stack, '\0', value_stackPointer);
		value_stackPointer = 0;
		memset(operator_stack, '\0', operator_stackPointer);
		operator_stackPointer = 0;
		memset(inputString, '\0', inputLength);
		//testRun(stack, stackPointer);
	}
	
	return 0;
}
