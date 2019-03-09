all:
	$(MAKE) syntax
	$(MAKE) lexicon
	g++ compiler/lexical-analyser.c compiler/syntactical-analyser.c -o compiler/nzc
	./compiler/nzc test.zl

syntax:
	bison -d -v -o compiler/syntactical-analyser.c compiler/syntax.y

lexicon:
	flex -o compiler/lexical-analyser.c compiler/lexicon.l
