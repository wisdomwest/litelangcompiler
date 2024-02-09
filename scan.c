#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"

/**
 * chrpos - Find the position of a character in a string
 * @s: string
 * @c: character
 * Return: int
 */
int chrpos(char *s, int c)
{
	char *p;

	p = strchr(s, c);
	return (p ? p - s : -1);
}

/**
 * next - Get the next character from the input
 * Return: int
 */
int next(void)
{
	int c;

	if (Putback)
	{		
		c = Putback;		
		Putback = 0;
		return (c);
	}

	c = fgetc(Infile);		
	if ('\n' == c)
		Line++;			
	return (c);
}

/**
 * putback - Put a character back onto the input
 * @c: character
 * Return: void
 */
void putback(int c)
{
	Putback = c;
}

/**
 * skip - Skip white space and get the next character
 * Return: int
 */
int skip(void)
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
 * scanint - Scan an integer literal
 * @c: character
 * Return: int
 */
int scanint(int c)
{
	int k, val = 0;


	while ((k = chrpos("0123456789", c)) >= 0)
	{
		val = val * 10 + k;
		c = next();
	}


	putback(c);
	return (val);
}

/**
 * scanident - Scan an identifier
 * @c: character
 * @buf: buffer
 * @lim: limit
 * Return: int
 */
int scanident(int c, char *buf, int lim)
{
	int i = 0;


	while (isalpha(c) || isdigit(c) || '_' == c)
	{

		if (lim - 1 == i)
		{
			printf("identifier too long on line %d\n", Line);
			exit(1);
		}
		else if (i < lim - 1)
		{
			buf[i++] = c;
		}
		c = next();
	}


	putback(c);
	buf[i] = '\0';
	return (i);
}

/**
 * keyword - Check if a string is a keyword
 * @s: string
 * Return: int
 */
int keyword(char *s)
{
	switch (*s)
	{
		case 'p':
			if (!strcmp(s, "print"))
				return (T_PRINT);
			break;
	}
	return (0);
}

/**
 * scan - Get the next token from the input
 * @t: token
 * Return: int
 */
int scan(struct token *t)
{
	int c, tokentype;


	c = skip();


	switch (c)
	{
		case EOF:
			t->token = T_EOF;
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
		case ';':
			t->token = T_SEMI;
			break;
		default:


			if (isdigit(c))
			{
				t->intvalue = scanint(c);
				t->token = T_INTLIT;
				break;
			}
			else if (isalpha(c) || '_' == c)
			{
				scanident(c, Text, TEXTLEN);


				if (tokentype = keyword(Text))
				{
					t->token = tokentype;
					break;
				}

				printf("Unrecognised symbol %s on line %d\n", Text, Line);
				exit(1);
			}

			printf("Unrecognised character %c on line %d\n", c, Line);
			exit(1);
	}

	return (1);
}
