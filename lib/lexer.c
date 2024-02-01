#include "../include/lexer.h"


/* lexer scanning - scanner */


/**
  * chr_position - get position of char in string
  * @str: pointer to string
  * @chr: character
  * Return: postion or -1 if c not found
  */
static int chr_position(char *str, int chr)
{
	char *pos;

	pos = strchr(str, chr);
	return (pos ? pos - str : -1);
}

/**
  * next - get next character from file
  * Return: next character
  */
static int next(int Line, int Putback, FILE *Infile)
{
	int c;

	/* Use the character putback if there is one */
	if (Putback)
	{
		c = Putback;
		Putback = 0;
		return (c);
	}

	/* read from input file gvar */
	c = fgetc(Infile);
	/* increment gvar line count */
	if ('\n' == c)
		Line++;
	return (c);
}

/**
  * putback - putback unwanted character
  * @c: char
  * Return: void
  */
static void putback(int c, int Putback)
{
	Putback = c;
}

/**
  * skip - skip input we dont want to deal with
  * Return: next character
  */
static int skip(int Line, int Putback, FILE *Infile)
{
	int c;

	c = next(Line, Putback, Infile);
	while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
	{
		c = next(Line, Putback, Infile);
	}

	return (c);
}

/**
  * scanint - scan and return interger lietal
  * @c: character
  * Return: value
  */
static int scanint(int c, int Line, int Putback, FILE *Infile)
{
	int pos;
	int value;

	pos = chr_position("0123456789", c);
	value = 0;

	while (pos >= 0)
	{
		value = value * 10 + pos;
		c = next(Line, Putback, Infile);
	}

	/* non-int we put back */
	putback(c, Putback);
	return (value);
}

/**
  * lexer - scan and return next token in the file input
  * @t: tokens
  * Return: 1 if token valid, 0 if no tokens left
  */
int lexer(struct token *t, int Line, int Putback, FILE *Infile)
{
	int c;

	/* skip unwanted */
	c = skip(Line, Putback, Infile);

	/* get token by input char c */
	switch (c)
	{
		case EOF:
			return (0);
		case '+':
			t->token = T_PLUS;
			break;
		case '-':
			t->token = T_MINUS;
			break;
		case '*':
			t->token = T_STAR;
			break;
		case '/':
			t->token = T_SLASH;
			break;
		default:
			/* if digit scan int literal */
			if (isdigit(c))
			{
				t->intvalue = scanint(c, Line, Putback, Infile);
				t->token = T_INTLIT;
				break;
			}

			printf("Unrecognised character %c on line %d\n", c, Line);
			exit(1);
	}

	/* token found */
	return (1);
}
