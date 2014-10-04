#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*define a stack size limit*/
#define STACK_SIZE 100
#define INPUT_STRING_MAX 100

char isOperator(char character)
{
	if(character == '+' || character == '-' || character == '/' || character == '*')
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
		//ignore input like spaces. and check if input was printable.
		if(isprint(value) && !isspace(value))
		{
			/*put our input value into the input string*/
			input[index] = value;
			/*make the last character a '\0'*/
			input[++index] = '\0';
		}
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
	if((*stackPointer) >= 0 )
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


//fancy way of displaying the error.
//makes finding it easier i think.
void displayError(char *inString, char *str_ptr)
{
	puts(inString);
	int i; //by calculating the difference between these
	//we can pinpoint where the "error occured in the input"
	for(i = 0;i<(str_ptr-inString);i++)
		putchar(' ');
	puts("^");
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
	bool nextNumNegative = false;
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
				//push a negative number if it has a '-' infront of it.
				if(nextNumNegative)
				{
					push(value_stack, &value_stackPointer, -accumulator);
					nextNumNegative = false;
				}
				else //else we just push the positive number
				{
					push(value_stack, &value_stackPointer, accumulator);
				}
				//reset the accumulator
				accumulator = 0;
				//only if not first element
				if( (str-inputString) > 0 )
				{
					str--; //or else we would skip a token
				}
			}
			//print stack contents
			else if( (*str) == '>')
			{
				printf("<Value stack> \n");
				printStack(value_stack, value_stackPointer);
				printf("<Operator stack> \n");
				printStack(operator_stack, operator_stackPointer);
			}
			//push operators onto the stack and/or handle special cases.
			else if(isOperator(*str))
			{
				if ( (*str) == '-')
				{
					
					//count the number of '-' operators we encounter.
					int numOfOps = 0;//atleast 1 is found
					while( (*str) ==  '-')
					{
						numOfOps++;
						str++;
					}
					str--; //or else we would skip a token.
					printf("num of ops: %d \n", numOfOps);
					
					if(numOfOps == 1)
					{
						//if first token in string, and next token is a digit.
						if( !(str-inputString) && isdigit( (*(str+1)) ))
						{
							nextNumNegative = true;
						}
						//if previous token is not a digit and next is a digit.
						else if( !isdigit( *(str-1) ) && isdigit( *(str+1) ))
						{
							nextNumNegative = true;
						}
						else if(isdigit( *(str-1) ) && isdigit( *(str+1) ))
						{
							push(operator_stack, &operator_stackPointer, *str);
						}
						else
						{
							displayError(inputString, str);
						}
					}
				}
				
				else
				{
					push(operator_stack, &operator_stackPointer, *str);
				}
			}
			//if e is enterd the program exits.
			else if(!strcmp(str, "exit"))
			{
				running = false;
				break;
			}
			else
			{
				puts("input error");
				displayError(inputString, str);
				break;
			}
			str++;
		}
		//process the data and do calculations.
		while(value_stackPointer > 1)
		{
			char operator = pop(operator_stack, &operator_stackPointer);
			bool invalidOp = false;
			switch(operator)
			{
				case '+': //do addition
					accumulator = pop(value_stack, &value_stackPointer)+pop(value_stack, &value_stackPointer);
					push(value_stack, &value_stackPointer, accumulator);
					break;
				case '-': //do subtraction
					accumulator = pop(value_stack, &value_stackPointer)-pop(value_stack, &value_stackPointer);
					push(value_stack, &value_stackPointer, accumulator);
					break;
				case '*': //do multiplication
					break;
				case '/': //do division
					break;
				default:
					puts("invalid data on operator stack");
					invalidOp = true;
				break;
			}
			if(invalidOp)
				break;
		}
		//after processing we display the result we know we have atleast 1 thing on the stack,
		//and that is our answer.
		if(value_stackPointer == 1)
		{
			printf("%d \n", pop(value_stack, &value_stackPointer));
		}
		//and we clear the original input string.
		//and stacks.
		memset(value_stack, '\0', STACK_SIZE);
		value_stackPointer = 0;
		memset(operator_stack, '\0', STACK_SIZE);
		operator_stackPointer = 0;
		memset(inputString, '\0', INPUT_STRING_MAX);
		//set the accumulator to 0
		accumulator = 0;
		//testRun(stack, stackPointer);
	}
	
	return 0;
}
