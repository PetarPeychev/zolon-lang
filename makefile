all:
	$(MAKE) syntax
	$(MAKE) lexicon
	g++ compiler/lexical-analyser.cpp compiler/syntactical-analyser.cpp -o compiler/nzc
	./compiler/nzc test.zl

syntax:
	bison -d -v -o compiler/syntactical-analyser.cpp compiler/syntax.ypp

lexicon:
	flex -o compiler/lexical-analyser.cpp compiler/lexicon.l
