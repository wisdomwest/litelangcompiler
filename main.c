#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "token.h"

/**
  * lexer - lexer function
  * @file: pointer to llc file
  * Return: void
*/
void lexer(FILE *file)
{
	char current;

	current = fgetc(file);

	while (current != EOF)
	{
		if (current == ';')
		{
			printf("FOUND SEMICOLON\n");
		}
		else if (current == '(')
		{
			printf("FOUND OPEN PAREN\n");
		}
		else if (current == ')')
		{
			printf("FOUND CLOSE PAREN\n");
		}
		else if (isdigit(current))
		{
			printf("FOUND DIGIT: %d\n", current - '0');
		}
		else if (isalpha(current))
		{
			printf("FOUND CHARACTER: %c\n", current);
		}
		current = fgetc(file);
	}
}

/**
 * main - main function entry point of compiler
 * Return: value
*/
int main(void)
{
	FILE *file;

	file = fopen("test.llc", "r");

	lexer(file);
}
