dag:lexer.o parser.o node.o symbol.o 
	g++ -o dag lexer.o parser.o node.o symbol.o -ll
lexer.o: lex.yy.c 
	g++ -o lexer.o -c lex.yy.c
parser.o: dag.tab.c
	g++ -o parser.o -c dag.tab.c
node.o: node.cpp
	g++ -o node.o -c node.cpp
symbol.o: symbol.cpp
	g++ -o symbol.o -c symbol.cpp
lex.yy.c: dag.tab.h dag.l
	flex dag.l
dag.tab.c dag.tab.h: dag.y
	bison -d dag.y 
clean:*.o
	rm *.o 