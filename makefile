all:
	$(MAKE) syntax
	$(MAKE) lexicon
	g++ interpreter/parser/lexical-analyser.cpp interpreter/parser/syntactical-analyser.cpp -o interpreter/parser/zl
	./interpreter/parser/zl test.zl

syntax:
	bison -d -v -o interpreter/parser/syntactical-analyser.cpp interpreter/parser/syntax.ypp

lexicon:
	flex -o interpreter/parser/lexical-analyser.cpp interpreter/parser/lexicon.l
