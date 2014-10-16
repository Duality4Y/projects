#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <malloc.h>
#include "Token.h"

char inputString[100];

Token_t* getTokens(void); //this function will deliver us a linked list of tokens.
void getInput(char *);
#endif
