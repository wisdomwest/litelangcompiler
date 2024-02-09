#include "include/defs.h"
#define extern_
#include "include/data.h"
#undef extern_
#include "include/decl.h"
#include <errno.h>

/**
 * init - Initialize the global variables
 * Return: void
 */
void init()
{
	Line = 1;
	Putback = '\n';
}

/**
 * usage - Print usage message and exit
 * @prog: program name
 * Return: void
 */
void usage(char *prog)
{
	fprintf(stderr, "Usage: %s infile\n", prog);
	exit(1);
}

/**
 * main - Main function
 * @argc: argument count
 * @argv: argument vector
 * Return: int
 */
void main(int argc, char *argv[])
{
	Infile = fopen(argv[1], "r");
	Outfile = fopen("out.s", "w");

	if (argc != 2)
		usage(argv[0]);

	init();

	if (Infile == NULL)
	{
		fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}
	if (Outfile == NULL)
	{
		fprintf(stderr, "Unable to create out.s: %s\n", strerror(errno));
		exit(1);
	}

	scan(&Token);			/* Get the first token from the input */
	genpreamble();		/* Output the preamble */
	statements();			/* Parse the statements in the input */
	genpostamble();		/* Output the postamble */
	fclose(Outfile);		/* Close the output file and exit */
	exit(0);
}
