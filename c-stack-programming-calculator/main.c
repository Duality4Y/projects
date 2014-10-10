#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
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

int countTokens(char value, char **str)
{
	/* this function will modify the original strings address.
	 * that is why pointer to pointer. so we can modify the pointers address
	 **/
	int numOfTokens = 0;
	while( (**str) == value)
	{
		numOfTokens++;
		(*str)++;
	}
	//for parsing reasons
	(*str)--;
	return numOfTokens;
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
		value = getchar();//getc(stdin);
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
	if((*stackPointer) >= 1)
	{
		value = stack[--(*stackPointer)];
		stack[*stackPointer] = '\0';
		return value;
	}
	else
	{
		puts("Stack underflow!");
		return 0;
	}
	return 0;
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

void reverseArray(int *array, unsigned int size)
{
	int i, j, temp;
	for(i = 0, j = (size-1);i<j;i++,j--)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
//this function checks if we are at the first token.
bool isFirstToken(char *inString, char *str_ptr)
{
	return (!(bool)(str_ptr-inString));
}

//this function will display in which point we are with processing.
void displayProcessingPoint(char *inString, char *str_ptr)
{
	puts(inString);
	ptrdiff_t i; //by calculating the difference between these
	//we can pinpoint where the "error occured in the input"
	for(i = 0;i<(!isFirstToken(inString, str_ptr));i++)
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
	
	int numOfOps = 0; //variable for operator counting.
	
	bool errorOccured = false;
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
				if(!isFirstToken(inputString, str))
				{
					str--; //or else we would skip a token
				}
			}
			//push operators onto the stack and/or handle special cases.
			else if(isOperator(*str))
			{
				if ( (*str) == '-')
				{
					
					//count the number of '-' operators we encounter.
					numOfOps = 0;
					while( (*str) ==  '-')
					{
						numOfOps++;
						str++;
					}
					str--; //or else we would skip a token.
					//printf("num of ops: %d \n", numOfOps);
					
					if(numOfOps == 1)
					{
						//if first token in string, and next token is a digit.
						if( isFirstToken(inputString, str) && isdigit( (*(str+1)) ))
						{
							nextNumNegative = true;
							displayProcessingPoint(inputString, str);
						}
						//if previous token is not a digit and next is a digit.
						else if( !isdigit( *(str-1) ) && isdigit( *(str+1) ))
						{
							nextNumNegative = true;
						}
						//if previous token is a digit and the next is also a digit.
						else if(isdigit( *(str-1) ) && isdigit( *(str+1) ))
						{
							push(operator_stack, &operator_stackPointer, *str);
						}
						else
						{
							displayProcessingPoint(inputString, str);
							errorOccured = true;
							break;
						}
					}
				}
				else if((*str) == '+')
				{
					countTokens('+', &str);
					push(operator_stack, &operator_stackPointer, *str);
				}
				else if((*str) == '*')
				{
					countTokens('*', &str);
					push(operator_stack, &operator_stackPointer, *str);
				}
				else if((*str) == '/')
				{
					countTokens('/', &str);
					push(operator_stack, &operator_stackPointer, *str);
				}
				else
				{
					printf("unknow operator parsed: %c \n", *str);
					displayProcessingPoint(inputString, str);
					errorOccured = true;
					break;
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
			//if exit is enterd the program exits.
			else if(!strcmp(str, "exit"))
			{
				running = false;
				break;
			}
			else
			{
				puts("input error at: ");
				displayProcessingPoint(inputString, str);
				errorOccured = true;
				break;
			}
			str++;
		}
		reverseArray(operator_stack, operator_stackPointer);
		reverseArray(value_stack, value_stackPointer);
		printf("<Value stack> \n");
		printStack(value_stack, value_stackPointer);
		printf("<Operator stack> \n");
		printStack(operator_stack, operator_stackPointer);
		//process the data and do calculations.
		while(operator_stackPointer)
		{
			/*
			printf("<Value stack> \n");
			printStack(value_stack, value_stackPointer);
			printf("<Operator stack> \n");
			printStack(operator_stack, operator_stackPointer);
			*/
			int operator = pop(operator_stack, &operator_stackPointer);
			int rvalue = pop(value_stack, &value_stackPointer);
			int lvalue = pop(value_stack, &value_stackPointer);
			printf("%d%c%d \n", lvalue, operator, rvalue);
			/*
			printf("value_stackPointer: %d \n", value_stackPointer);
			printf("operator_stackPointer: %d \n", operator_stackPointer);
			*/
			switch(operator)
			{
				case '+': //do addition
					accumulator = lvalue+rvalue;
					push(value_stack, &value_stackPointer, accumulator);
					break;
				case '-': //do subtraction
					accumulator = lvalue-rvalue;
					push(value_stack, &value_stackPointer, accumulator);
					break;
				case '*': //do multiplication
					accumulator = lvalue*rvalue;
					push(value_stack, &value_stackPointer, accumulator);
					break;
				case '/': //do division
					accumulator = lvalue/rvalue;
					push(value_stack, &value_stackPointer, accumulator);
					break;
				default:
					puts("invalid data on operator stack");
					break;
			}
		}
		//after processing we display the result we know we have atleast 1 thing on the stack,
		//and that is our answer.
		if(value_stackPointer == 1 && !errorOccured)
			printf("%d \n", pop(value_stack, &value_stackPointer));
		//and we clear the original input string.
		//and stacks.
		memset(value_stack, '\0', STACK_SIZE);
		value_stackPointer = 0;
		memset(operator_stack, '\0', STACK_SIZE);
		operator_stackPointer = 0;
		memset(inputString, '\0', INPUT_STRING_MAX);
		//set the accumulator to 0
		accumulator = 0;
	}
	
	return 0;
}
