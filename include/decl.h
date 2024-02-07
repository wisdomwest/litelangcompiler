#ifndef DECL_H_
#define DECL_H_

int scan(struct token *t);

/**
  * struct ASTnode - AST structure
  * @op: op code
  * @left: left side of tree
  * @right: right side of tree
  * @intvalue: value of int
  * Description: defines ast structure
*/
struct ASTnode *mkastnode(int op, struct ASTnode *left,
			  struct ASTnode *right, int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
int genAST(struct ASTnode *n);
void genpreamble(void);
void genpostamble(void);
void genfreeregs(void);
void genprintint(int reg);
void freeall_registers(void);
void cgpreamble(void);
void cgpostamble(void);
int cgload(int value);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);
struct ASTnode *binexpr(int ptp);
void statements(void);
void match(int t, char *what);
void semi(void);

#endif
