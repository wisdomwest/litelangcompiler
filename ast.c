#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"

/* defines ast function */

/*takes values for all four fields in an AST node. It allocates the node, populates the field values and returns a pointer to the node*/

/**
  */
struct ASTnode *makenode(int op, struct ASTnode *left,struct ASTnode *right, int intvalue)
{
	struct ASTnode *n;

	/* memory for new node */
	n = (struct ASTnode *) malloc(sizeof(struct ASTnode));
	if (n == NULL)
	{
		fprintf(stderr, "no malloc in ast\n");
		exit(1);
	}

	/*copy values and return*/

	n->op = op;
	n->left = left;
	n->right = right;
	n->intvalue = intvalue;
	return (n);
}


