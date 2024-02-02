#include "include/defs.h"
#define extern_
#include "include/data.h"
#undef extern_
#include "include/decl.h"
#include <errno.h>

/* Compiler setup and top-level execution */

/**
 * init - int global vars
 * Return: void
 */
static void init(void)
{
	Line = 1;
	Putback = '\n';
}

/**
 * usage - usage for compiler
 * @prog: command
 * Return: void
*/
static void usage(char *prog)
{
	fprintf(stderr, "Usage: %s infile\n", prog);
	exit(1);
}

char *tokstr[] = { "+", "-", "*", "/", "intlit" };

/**
 * scanfile - scan a file get tokens
 * Return: void
*/
static void scanfile(void)
{
	struct token T;

	while (lexer(&T))
	{
		printf("Token %s", tokstr[T.token]);
		if (T.token == T_INTLIT)
			printf(", value %d", T.intvalue);
		printf("\n");
	}
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: 0 on success, -1 on failure
*/
int main(int argc, char *argv[])
{
	Infile =  fopen(argv[1], "r");

	if (argc != 2)
		usage(argv[0]);

	init();

	if (Infile == NULL)
	{
		fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}

	scanfile();
	exit(0);
}
