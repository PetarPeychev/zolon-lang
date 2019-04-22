zl : zl.o InteractiveInterface.o Interpreter.o Scanner.o Token.o Parser.o \
	 ArithmeticOperation.o Binding.o BooleanLiteral.o Function.o \
     FunctionApplication.o InvalidBinding.o InvalidExpression.o \
	 LogicalOperation.o NumberLiteral.o RelationalOperation.o Statement.o \
	 Value.o Environment.o
	g++ \
	zl.o \
	InteractiveInterface.o \
	Interpreter.o \
	Scanner.o \
	Token.o \
	Parser.o \
	ArithmeticOperation.o \
	Binding.o \
	BooleanLiteral.o \
	Function.o \
	FunctionApplication.o \
	InvalidBinding.o \
	InvalidExpression.o \
	LogicalOperation.o \
	NumberLiteral.o \
	RelationalOperation.o \
	Statement.o \
	Value.o \
	Environment.o \
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
	syntactical_analysis/Parser.o \
	syntax_tree/ArithmeticOperation.o \
	syntax_tree/Binding.o \
	syntax_tree/BooleanLiteral.o \
	syntax_tree/Function.o \
	syntax_tree/FunctionApplication.o \
	syntax_tree/InvalidBinding.o \
	syntax_tree/InvalidExpression.o \
	syntax_tree/LogicalOperation.o \
	syntax_tree/NumberLiteral.o \
	syntax_tree/RelationalOperation.o \
	syntax_tree/Statement.o \
	evaluation/Value.o \
	evaluation/Environment.o \
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

Parser.o : syntactical_analysis/Parser.cpp
	g++ -c syntactical_analysis/Parser.cpp

ArithmeticOperation.o : syntax_tree/ArithmeticOperation.cpp
	g++ -c syntax_tree/ArithmeticOperation.cpp

Binding.o : syntax_tree/Binding.cpp
	g++ -c syntax_tree/Binding.cpp

BooleanLiteral.o : syntax_tree/BooleanLiteral.cpp
	g++ -c syntax_tree/BooleanLiteral.cpp

Function.o : syntax_tree/Function.cpp
	g++ -c syntax_tree/Function.cpp

FunctionApplication.o : syntax_tree/FunctionApplication.cpp
	g++ -c syntax_tree/FunctionApplication.cpp

InvalidBinding.o : syntax_tree/InvalidBinding.cpp
	g++ -c syntax_tree/InvalidBinding.cpp

InvalidExpression.o : syntax_tree/InvalidExpression.cpp
	g++ -c syntax_tree/InvalidExpression.cpp

LogicalOperation.o : syntax_tree/LogicalOperation.cpp
	g++ -c syntax_tree/LogicalOperation.cpp

NumberLiteral.o : syntax_tree/NumberLiteral.cpp
	g++ -c syntax_tree/NumberLiteral.cpp

RelationalOperation.o : syntax_tree/RelationalOperation.cpp
	g++ -c syntax_tree/RelationalOperation.cpp

Statement.o : syntax_tree/Statement.cpp
	g++ -c syntax_tree/Statement.cpp

Value.o : evaluation/Value.cpp
	g++ -c evaluation/Value.cpp

Environment.o : evaluation/Environment.cpp
	g++ -c evaluation/Environment.cpp
