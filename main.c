#include "lexer.h"

/**
  * main - entry point of compiler
  * Return: void
  */

int main(void)
{
	FILE *file;

	file = fopen("test.llc", "r");

	Token *tokens = lexer(file);
}
