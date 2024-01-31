#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "token.h"

/**
 * main - main function entry point of compiler
 * Return: value
*/
int main(void)
{
	FILE *file;
	char current;

	file = fopen("test.llc", "r");
	current = fgetc(file);

	while(current != EOF)
	{
		printf("%c", current);
		current = fgetc(file);
	}
}
