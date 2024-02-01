lex: main.c lib/lexer.c
	cc -o lex -g main.c lib/lexer.c

clean: 
	rm -f lex *.o
