#include "defs.h"
#include "data.h"
#include "decl.h"

/* lexer scanning - scanner */

/**
  * chr_position - get position of char in string
  * @str: pointer to string
  * @chr: character
  * Return: postion or -1 if c not found
  */
static int chr_position(char *str, int chr)
{
	char *p;

	p = strchr(str, chr);
	return (p ? p - str : -1);
}

/**
  * next - get next character from file
  * Return: next character
  */
static int next(void)
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
static void putback(int c)
{
	Putback = c;
}

/**
  * skip - skip input we dont want to deal with
  * Return: next character
  */
static int skip(void)
{
	int c;

	c = next();
	while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
	{
		c = next();
	}
	return (c);
}

/**
  * scanint - scan and return interger lietal
  * @c: character
  * Return: value
  */
static int scanint(int c)
{
	int k, value = 0;

	while ((k = chr_position("0123456789", c)) >= 0)
	{
		value = value * 10 + k;
		c = next();
	}
	/* non-int we put back */
	putback(c);
	return (value);
}

/**
  * lexer - scan and return next token in the file input
  * @t: tokens
  * Return: 1 if token valid, 0 if no tokens left
  */
int lexer(struct token *t)
{
	int c;

	/* skip unwanted */
	c = skip();

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
				t->intvalue = scanint(c);
				t->token = T_INTLIT;
				break;
			}

			printf("Unrecognised character %c on line %d\n", c, Line);
			exit(1);
	}
	/* token found */
	return (1);
}
