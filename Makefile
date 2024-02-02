lex: main.c lexer.c
	cc -o lex -g main.c lexer.c

clean: 
	rm -f lex *.o
