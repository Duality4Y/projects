/*
 * A token struct wil contain a type.
 * it can be a operator type
 * it can be a value type
 * it can be a syntax type
 * 
 * case operator type.
 * char operator will be filled.
 * 
 * case value type.
 * int value will be filled.
 * 
 * case syntax type
 * representation will be put in token;
 * 
 * keep an index to easly find a Token node.
 * unsigned index will hold the value.
 * */

#ifndef TOKEN_H
#define TOKEN_H

typedef struct Token_t
{
	int type;
	int value;
	char* token; //token string representation. can't imagine syntax with words bigger then 8 or so characters.
	char operator; //for math operators. or single operators.
	struct Token_t *next;
}Token_t;

#endif
