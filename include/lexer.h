#ifndef _LEXER_H_
#define _LEXER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/* Global variables */
extern int Line;
extern int Putback;
extern FILE *Infile;

/* Structure and enum definitions */

/**
  * enum tokens - enum tokens
  * @T_PLUS: token plus
  * @T_MINUS: token minus
  * @T_STAR: token multiply
  * @T_SLASH: token divide
  * @T_INTLIT: token decimal
  * Description: token field can be one of these values
 */
enum tokens
{
	T_PLUS,
	T_MINUS,
	T_STAR,
	T_SLASH,
	T_INTLIT
};

/**
  * struct token - Token structure
  * @token: token
  * @intvalue: integer literal
  * Description: storage for token scanned
  */
struct token
{
	int token;
	int intvalue;
};

/* Function prototypes for all compiler files */
int lexer(struct token *t);
#endif
