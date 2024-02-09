#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"


struct ASTnode *primary(void)
{
	struct ASTnode *n;

	switch (Token.token)
	{
		case T_INTLIT:
			n = mkastleaf(A_INTLIT, Token.intvalue);
			scan(&Token);
			return (n);
		default:
			fprintf(stderr, "syntax error on line %d, token %d\n", Line,
				Token.token);
			exit(1);
	}
}


/**
 * arithop - Convert token type to AST operation
 * @tokentype: token type
 * Return: int
 */
int arithop(int tokentype)
{
	switch (tokentype)
	{
		case T_PLUS:
			return (A_ADD);
		case T_MINUS:
			return (A_SUBTRACT);
		case T_STAR:
			return (A_MULTIPLY);
		case T_SLASH:
			return (A_DIVIDE);
		default:
			fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
			exit(1);
	}
}

int OpPrec[] = { 0, 10, 10, 20, 20, 0 };

/**
 * op_precedence - Get the precedence of a token
 * @tokentype: token type
 * Return: int
 */
int op_precedence(int tokentype)
{
	int prec = OpPrec[tokentype];

	if (prec == 0)
	{
		fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
		exit(1);
	}
	return (prec);
}


struct ASTnode *binexpr(int ptp)
{
	struct ASTnode *left, *right;
	int tokentype;

	left = primary();

	tokentype = Token.token;
	if (tokentype == T_SEMI)
		return (left);


	while (op_precedence(tokentype) > ptp)
	{
		scan(&Token);


		right = binexpr(OpPrec[tokentype]);

		left = mkastnode(arithop(tokentype), left, right, 0);

		tokentype = Token.token;
		if (tokentype == T_SEMI)
			return (left);
	}

	return (left);
}
