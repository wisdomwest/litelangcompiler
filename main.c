#include "include/lexer.h"


static void init(int Line, int Putback)
{
	Line = 1;
	Putback = '\n';
}


/* Print out a usage if started incorrectly */
static void usage(char *prog)
{
	fprintf(stderr, "Usage: %s infile\n", prog);
	exit(1);
}

/* List of printable tokens */
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

// Loop scanning in all the tokens in the input file.
// Print out details of each token found.
static void scanfile(int Line, int Putback, FILE *Infile)
{
	struct token T;

	while (lexer(&T, Line, Putback, Infile))
	{
		printf("Token %s", tokstr[T.token]);
		if (T.token == T_INTLIT)
			printf(", value %d", T.intvalue);
		printf("\n");
	}
}

// Main program: check arguments and print a usage
// if we don't have an argument. Open up the input
// file and call scanfile() to scan the tokens in it.
void main(int argc, char *argv[])
{
	int Line;
	int Putback;
	FILE *Infile;

	if (argc != 2)
		usage(argv[0]);

	init(Line, Putback);

	if ((Infile = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}

	scanfile(Line, Putback, Infile);
	exit(0);
}
