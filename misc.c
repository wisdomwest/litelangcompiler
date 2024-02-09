#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"

/**
 * match - Ensure the current token is a particular symbol
 * @t: token type
 * @what: what to match
 * Return: void
 */
void match(int t, char *what)
{
	if (Token.token == t)
	{
		scan(&Token);
	}
	else
	{
		printf("%s expected on line %d\n", what, Line);
		exit(1);
	}
}

/**
 * semi - Ensure the current token is a semi-colon
 * Return: void
 */
void semi(void)
{
	match(T_SEMI, ";");
}
