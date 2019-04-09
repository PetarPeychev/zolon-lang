zl : zl.o InteractiveInterface.o Interpreter.o Scanner.o Token.o
	g++ \
	zl.o \
	InteractiveInterface.o \
	Interpreter.o \
	Scanner.o \
	Token.o \
	-o zl
	
	find . -name "*.gch" -type f -delete 
	find . -name "*.o" -type f -delete

zl-d:
	g++ -g \
	zl.cpp \
	cli/InteractiveInterface.cpp \
	Interpreter.cpp \
	lexical_analysis/Scanner.cpp \
	lexical_analysis/Token.cpp \
	-o zl-d
	gdb zl-d

zl.o : zl.cpp
	g++ -c zl.cpp

InteractiveInterface.o : cli/InteractiveInterface.cpp
	g++ -c cli/InteractiveInterface.cpp

Interpreter.o : Interpreter.cpp
	g++ -c Interpreter.cpp

Scanner.o : lexical_analysis/Scanner.cpp
	g++ -c lexical_analysis/Scanner.cpp

Token.o : lexical_analysis/Token.cpp
	g++ -c lexical_analysis/Token.cpp
