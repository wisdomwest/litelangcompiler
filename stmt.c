#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"

/**
 * statements - Parse the statements
 * Return: void
 */
void statements(void)
{

	struct ASTnode *tree;
	int reg;

	while (1)
	{

		match(T_PRINT, "print");
		tree = binexpr(0);
		reg = genAST(tree);
		genprintint(reg);
		genfreeregs();
		semi();
		if (Token.token == T_EOF)
			return;
	}
}
