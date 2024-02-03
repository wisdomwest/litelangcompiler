#ifndef DEFS_H_
#define DEFS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


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

/* Abstract Syntax Tree */

/**
  * enum a_tokens - abstract syntax tree tokens
  * @A_PLUS: token plus
  * @A_MINUS: token minus
  * @A_STAR: token multiply
  * @A_SLASH: token divide
  * @A_INTLIT: token decimal
  * Description: tokens for the ast
  */
enum a_tokens
{
	A_PLUS,
	A_MINUS,
	A_STAR,
	A_SLASH,
	A_INTLIT
};

/**
  * struct ASTnode - AST structure
  * @op: op code
  * @left: left side of tree
  * @right: right side of tree
  * @intvalue: value of int
  * Description: defines ast structure
  */
struct ASTnode
{
	int op;
	struct ASTnode *left;
	struct ASTnode *right;
	int intvalue;
};

#endif
