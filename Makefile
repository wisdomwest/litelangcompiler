llc: cgn.c expr.c gen.c main.c misc.c scan.c stmt.c ast.c
	cc -o llc -g cgn.c expr.c gen.c main.c misc.c scan.c stmt.c ast.c

clean:
	rm -f llc *.o *.s out

test: llc input01
	./llc input01
	nasm -f elf64 out.s
	cc -no-pie -o out out.o
	./out
