#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H
#include <iostream>
#include <string>
#include <vector>

class SyntaxNode {
public:
	virtual ~SyntaxNode() = 0;
	virtual void codeGen(std::ostream& output) = 0;
	enum VariableType {
		INT,
		FLOAT,
		CHAR,
		CHAR_ARRAY,
		INT_ARRAY,
		FLOAT_ARRAY,
		VOID
	};
};

class Program: public SyntaxNode {
private:
	struct ExternalDeclaration {
		enum {
			VARIABLE_DECLARATION,
			FUNCTION_DECLARATION,
			FUNCTION_DEFINITION
		} type;
		union {
			VariableDeclaration* variable_declaration;
			FunctionDeclaration* function_declaration;
			FunctionDefinition* function_definition;
		};
	};
	std::vector<ExternalDeclaration*> external_declarations_;
};

class Expression: public SyntaxNode {
public:
	virtual ~Expression() = 0;
};

class Identifier: public Expression {
public:
	Identifier(const std::string& name);
	inline const std::string& get_name() { return this->name_; }
private:
	std::string name_;
};

class ImmediateInteger: public Expression {
private:
	int value_;
};

class UnaryExpression: public Expression {
public:
	enum UnaryOperator{
		LOGICAL_NEGTIVE
	};

private:
	Expression* expression_;
	UnaryOperator operator_;
};

class BinaryExpression: public Expression {
public:
	enum BinaryOperator{
		ADDITION,
		SUBTRACTION,
		MULTIPLICATION,
		DIVISION,
		MODULO,
		ADDRESS,

	};

private:
	BinaryOperator operator_;
	Expression* left_;
	Expression* right_;
}; 

class FunctionCall: public Expression {
private:
	Identifier* function_;
	std::vector<Expression*> arguments_;
};

class AssignmentExpression: public Expression {
private:
	Identifier* identifier_;
	Expression* expression_;
};

class Statement: public SyntaxNode {
public:
	virtual ~Statement() = 0;
};

class VariableDeclaration: public Statement {
private:
	Identifier* identifier_;
	VariableType type_;
};

class StatementsBlock: public Statement {
private:
	std::vector<Statement*> statements_;
	Expression* init_value_;
};

class IfStatement: public Statement {
private:
	Expression* condition_;
	StatementsBlock* then_statements_;
	StatementsBlock* else_statements_;
};

class WhileStatement: public Statement {
private:
	Expression* condition_;
	StatementsBlock* body_;
};

class ExpressionStatement: public Statement {
private:
	Expression* expression_;
};

class FunctionDeclaration: public SyntaxNode {
private:
	VariableType type_;
	std::string function_name_;
	std::vector<Identifier*> arguments_;
};

class FunctionDefinition: public SyntaxNode {

private:
	VariableType type_;
	std::string function_name_;
	std::vector<Identifier*> arguments_;
	StatementsBlock* body_;
};
#endif

