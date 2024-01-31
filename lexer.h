#ifndef _LEXER_H_
#define _LEXER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
  INT,
  KEYWORD,
  SEPARATOR,
  END_OF_TOKENS,
} TokenType;

typedef struct {
  TokenType type;
  char *value;
} Token;

#endif
