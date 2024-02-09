#include "include/defs.h"
#include "include/data.h"
#include "include/decl.h"


int freereg[4];
char *reglist[4] = { "r8", "r9", "r10", "r11" };

/**
 * freeall_registers - Set all registers to be free
 * Return: void
*/
void freeall_registers(void)
{
	freereg[0] = freereg[1] = freereg[2] = freereg[3] = 1;
}

/**
 * alloc_register - Allocate a register
 * Return: int
*/
int alloc_register(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (freereg[i])
		{
			freereg[i] = 0;
			return (i);
		}
	}
	fprintf(stderr, "Out of registers!\n");
	exit(1);
}

/**
 * free_register - Free a register
 * @reg: register to free
 * Return: void
*/
void free_register(int reg)
{
	if (freereg[reg] != 0)
	{
		fprintf(stderr, "Error trying to free register %d\n", reg);
		exit(1);
	}
	freereg[reg] = 1;
}

/**
 * cgpreamble - Generate the preamble
 * Return: void
*/
void cgpreamble(void)
{
	freeall_registers();
	fputs("\tglobal\tmain\n"
	"\textern\tprintf\n"
	"\tsection\t.text\n"
	"LC0:\tdb\t\"%d\",10,0\n"
	"printint:\n"
	"\tpush\trbp\n"
	"\tmov\trbp, rsp\n"
	"\tsub\trsp, 16\n"
	"\tmov\t[rbp-4], edi\n"
	"\tmov\teax, [rbp-4]\n"
	"\tmov\tesi, eax\n"
	"\tlea	rdi, [rel LC0]\n"
	"\tmov	eax, 0\n"
	"\tcall	printf\n"
	"\tnop\n"
	"\tleave\n"
	"\tret\n"
	"\n"
	"main:\n" "\tpush\trbp\n" "\tmov	rbp, rsp\n", Outfile);
}

/**
 * cgpostamble - Generate the postamble
 * Return: void
*/
void cgpostamble()
{
	fputs("\tmov	eax, 0\n" "\tpop	rbp\n" "\tret\n", Outfile);
}

/**
 * cgload - Load a value into a register
 * @value: value to load
 * Return: int
*/
int cgload(int value)
{

	int r = alloc_register();


	fprintf(Outfile, "\tmov\t%s, %d\n", reglist[r], value);
	return (r);
}

/**
 * cgadd - Add a value to a register
 * @r1: register to add
 * @r2: register to add
 * Return: int
*/
int cgadd(int r1, int r2)
{
	fprintf(Outfile, "\tadd\t%s, %s\n", reglist[r2], reglist[r1]);
	free_register(r1);
	return (r2);
}

/**
 * cgsub - Subtract a value from a register
 * @r1: register to subtract
 * @r2: register to subtract
 * Return: int
*/
int cgsub(int r1, int r2)
{
	fprintf(Outfile, "\tsub\t%s, %s\n", reglist[r1], reglist[r2]);
	free_register(r2);
	return (r1);
}

/**
 * cgmul - Multiply a value with a register
 * @r1: register to multiply
 * @r2: register to multiply
 * Return: int
*/
int cgmul(int r1, int r2)
{
	fprintf(Outfile, "\timul\t%s, %s\n", reglist[r2], reglist[r1]);
	free_register(r1);
	return (r2);
}

/**
 * cgdiv - Divide a value from a register
 * @r1: register to divide
 * @r2: register to divide
 * Return: int
*/
int cgdiv(int r1, int r2)
{
	fprintf(Outfile, "\tmov\trax, %s\n", reglist[r1]);
	fprintf(Outfile, "\tcqo\n");
	fprintf(Outfile, "\tidiv\t%s\n", reglist[r2]);
	fprintf(Outfile, "\tmov\t%s, rax\n", reglist[r1]);
	free_register(r2);
	return (r1);
}

/**
 * cgprintint - Print an integer
 * @r: register to print
 * Return: void
*/
void cgprintint(int r)
{
	fprintf(Outfile, "\tmov\trdi, %s\n", reglist[r]);
	fprintf(Outfile, "\tcall\tprintint\n");
	free_register(r);
}
