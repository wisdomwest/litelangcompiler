#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"

/**
 * genAST - Generate the assembly code for an AST
 * @n: AST node
 * Return: int
 */
int genAST(struct ASTnode *n)
{
	int leftreg, rightreg;
	
	if (n->left)
		leftreg = genAST(n->left);
	if (n->right)
		rightreg = genAST(n->right);

	switch (n->op)
	{
		case A_ADD:
			return (cgadd(leftreg, rightreg));
		case A_SUBTRACT:
			return (cgsub(leftreg, rightreg));
		case A_MULTIPLY:
			return (cgmul(leftreg, rightreg));
		case A_DIVIDE:
			return (cgdiv(leftreg, rightreg));
		case A_INTLIT:
			return (cgload(n->intvalue));
		default:
			fprintf(stderr, "Unknown AST operator %d\n", n->op);
			exit(1);
	}
}

/**
 * genpreamble - Generate the preamble
 * Return: void
 */
void genpreamble(void)
{
	cgpreamble();
}

/**
 * genpostamble - Generate the postamble
 * Return: void
 */
void genpostamble(void)
{
	cgpostamble();
}

/**
 * genfreeregs - Free all registers
 * Return: void
 */
void genfreeregs(void)
{
	freeall_registers();
}

/**
 * genprintint - Generate code to print an integer
 * @reg: register to print
 * Return: void
 */
void genprintint(int reg)
{
	cgprintint(reg);
}
