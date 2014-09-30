#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
	
	printf(">> input_str: %s \n", input);
}

void push(int *stack, int *stackPointer, int value)
{
	stack[(*stackPointer)++] = value;
	stack[*stackPointer] = '\0';
}

int pop(int *stack, int *stackPointer)
{
	int value;
	if(*stackPointer > 0 )
	{
		value = stack[--(*stackPointer)];
		stack[*stackPointer] = '\0';
		return value;
	}
	else
	{
		printf("I think we got a stack underflow");
		return -1;
	}
	return -1;
}

void printStack(int *stack, int stackPointer)
{
	printf(">> stackPointer: %d \n", stackPointer);
	printf(">> stack: ");
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
	int value_stack[100] = {'\0'};
	int value_stackPointer = 0;
	
	/*will hold operators.*/
	int operator_stack[100] = {'\0'};
	int operator_stackPointer = 0;
	
	int accumulator = 0;
	
	bool running = true;
	
	while(running)
	{
		getUserInputString(inputString);
		inputLength = strlen(inputString);
		printf(">> len:%d \n", inputLength);
		printf(">> Processing \n");
		/*parse the input*/
		int i;
		for(i = 0;i<inputLength;i++)
		{
			int token = inputString[i];
			/*check for number*/
			if(token >= '0' && token <= '9')
			{
				accumulator = (accumulator*10)+(token-'0');
			}
			/*if exit is typed we exit the program*/
			else if(!strcmp("exit", inputString))
			{
				running = false;
				break;
			}
			/*with this we can see what the accumulator value is.*/
			else if (token == '>')
			{
				printf(">> accumulator value: %d \n", accumulator);
			}
			/*print the stack for debugging*/
			else if(token == '^')
			{
				printf("Value stack: \n");
				printStack(value_stack, value_stackPointer);
				printf("Operator stack: \n");
				printStack(operator_stack, operator_stackPointer);
			}
			else
			{
				printf(">> input error \n");
				break;
			}
		}
		//testRun(stack, stackPointer);
	}
	
	return 0;
}
