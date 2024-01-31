#include "lexer.h"

/**
  * print_token - print token type according to struct
  * @token: token extracted
  * Return: void
  */
void print_token(Token token)
{
	int i;

	printf("TOKEN VALUE: ");
	for (i = 0; token.value[i] != '\0'; i++)
	{
		printf("%c", token.value[i]);
	}
	if (token.type == INT)
	{
		printf(" TOKEN TYPE: INT\n");
	}
	if (token.type == KEYWORD)
	{
		printf(" TOKEN TYPE: KEYWORD\n");
	}
	if (token.type == SEPARATOR)
	{
		printf(" TOKEN TYPE: SEPARATOR\n");
	}
}

/**
  */
Token *generate_number(char *current, int *current_index)
{
}

/**
  */
Token *generate_keyword(char *current, int *current_index)
{
}

/**
  */
Token *lexer(FILE *file)
{
}
