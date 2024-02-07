#ifndef DEFS_H_
#define DEFS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define TEXTLEN		512	


enum {
  T_EOF,
  T_PLUS,
  T_MINUS,
  T_STAR,
  T_SLASH,
  T_INTLIT,
  T_SEMI,
  T_PRINT
};

struct token {
  int token;
  int intvalue;			
};


enum {
  A_ADD,
  A_SUBTRACT,
  A_MULTIPLY,
  A_DIVIDE,
  A_INTLIT
};

struct ASTnode {
  int op;	
  struct ASTnode *left;
  struct ASTnode *right;
  int intvalue;
};

#endif
