bison -d -o CParser.cpp CParser.y 2> outputB.txt &  flex -o CToken.cpp CToken.l & g++ -o parser.exe SyntaxNode.h CParser.cpp CToken.cpp main.cpp 2> output.txt