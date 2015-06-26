#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H
#include <iostream>
#include <string>
#include <vector>
#include "Type.h"

class VariableDeclaration;
class FunctionDeclaration;
class FunctionDefinition;
class Declaration;
class SyntaxNode {
public:
	//virtual ~SyntaxNode() = 0;
	virtual void GenerateCode(std::ostream& output) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
	
};

class Program: public SyntaxNode {
public:
	void PushDeclaration(Declaration* declaration);
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	std::vector<Declaration*> declarations_;
};

class Expression: public SyntaxNode {
public:
	virtual void GenerateCode(std::ostream& output) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
};

class Identifier: public Expression {
public:
	Identifier(std::string& name);
	inline std::string& getName() { return this->name_; }

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	std::string name_;
};

class ImmediateInteger: public Expression {
public:
	ImmediateInteger(int value);
	
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);

private:
	int value_;
};

class StringLiteral: public Expression {
public:
	StringLiteral(std::string& value);
	
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	std::string value_;
};

class UnaryExpression: public Expression {
public:	
	enum Operator {
		INC_PRE,
		DEC_PRE,
		INC_AFTER,
		DEC_AFTER,
		REFERENCE,
		DEREFERENCE,
		MINUS,
		NOT_BIT,
		NOT
	};
	UnaryExpression(Expression *expression, Operator unary_operator);
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Expression* expression_;
	//possible value : _--, _++, --_, ++_, &, *, +, -, ~, !
	Operator unary_operator_;

};

class BinaryExpression: public Expression {
public:
	enum Operator {
		ADD,
		SUB,
		MUL,
		DIV,
		MOD,
		INDEX,
		DOT,
		POINTER,
		SHIFT_LEFT,
		SHIFT_RIGHT,
		LESS,
		GREATER,
		LESS_EQUAL,
		GREATER_EQUAL,
		EQUAL,
		NOT_EQUAL,
		AND_BIT,
		XOR_BIT,
		OR_BIT,
		AND,
		OR
	};
	BinaryExpression(Expression* left, Expression* right, Operator binary_operator);
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);

private:
	// possible value : +, -, *, /, %, [], ., ->, <<, >>, <, >, <=, >=, 
	//                  ==, !=, &, ^, |, &&, ||
	Operator binary_operator_;
	Expression* left_;
	Expression* right_;
};

class AssignmentExpression: public Expression {
public:
	enum Operator {
		ASSIGN,
		ADD_ASSIGN,
		SUB_ASSIGN,
		MUL_ASSIGN,
		DIV_ASSIGN,
		MOD_ASSIGN,
		SHIFT_LEFT_ASSIGN,
		SHIFT_RIGHT_ASSIGN,
		EXCLUSIVE_OR_ASSIGN,
		INCLUSIVE_OR_ASSIGN,
		AND_ASSIGN
	};
	AssignmentExpression(Expression *left, Expression *right, Operator assignment_operator);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Operator assignment_operator_;
	Expression *unary_expression_;
	Expression *assignment_expression_;
};

//class VariableType: public SyntaxNode {
//public:
//	enum Type{
//		VOID,
//		CHAR,
//		INT,
//		FLOAT
//	};
//	VariableType():type(VOID), pointer(0){}
//	Type type;
//	int pointer;
//	std::vector<Expression *> array;
//
//	virtual void GenerateCode(std::ostream& output);
//	virtual void PrintTree(std::ostream& output);
//};

class Statement: public SyntaxNode {
public:
	virtual void GenerateCode(std::ostream& output) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
};

class StatementsBlock: public Statement {
public:
	void PushStatement(Statement *statement);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	std::vector<Statement*> statements_;
	Expression* init_value;
};

class IfStatement: public Statement {
public:
	IfStatement(Expression *condition, Statement *then_statement, Statement *else_statement = NULL);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Expression* condition_;
	Statement* then_statement_;
	Statement* else_statement_;
};

class JumpStatement: public Statement {
public:
	enum JumpType {
		CONTINUE,
		BREAK
	};
	JumpStatement(JumpType jump_type);
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	JumpType type_;
};

class ReturnStatement: public Statement {
public:
	ReturnStatement(Expression* return_value);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Expression * return_value_;
};

class WhileStatement: public Statement {
public:
	WhileStatement(Expression *condition, Statement *body, bool has_do = false);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Expression* condition_;
	Statement* body_;
	bool has_do_;
};

class ForStatement: public Statement {
public:
	ForStatement(Statement* initializer, Expression* operation, Expression* condition, Statement* body);
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);

private:
	Statement* initializer_;
	Expression* operation_;
	Expression* condition_;
	Statement* body_;
};

class ExpressionStatement: public Statement {
public:
	ExpressionStatement(Expression *expression);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Expression* expression_;
};

class DeclarationStatement: public Statement {
public:
	DeclarationStatement(VariableDeclaration* declaration);
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);

private:
	VariableDeclaration* declaration_;
};

class Declaration : public Statement {
public:
	virtual void GenerateCode(std::ostream& output) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
};

class VariableDeclaration: public Declaration {
public:
	VariableDeclaration();
	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
	inline void set_type(Type* type) { this->type_ = type; }
	inline Type* get_type() { return this->type_; }
	inline void set_basic_type(Type::BasicType basic_type) { this->type_->set_basic_type(basic_type); }
	inline void set_initializer(Expression* initializer) { this->initializer_ = initializer; }
	inline Identifier* get_identifier() { return identifier_; }
	inline void set_identifier(Identifier* identifier) { this->identifier_ = identifier; }

private:
	Identifier	*identifier_;
	Type* type_;
	Expression *initializer_;
};

class FunctionDeclaration: public Declaration {
public:
	FunctionDeclaration(Identifier *identifier, std::vector<VariableDeclaration*> *arguments);
	inline void set_return_type(Type* return_type){ return_type_ = return_type; }
	inline void set_body(Statement *body) { statements_ = static_cast<StatementsBlock*>(body); }

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Type* return_type_;
	Identifier *identifier_;
	std::vector<VariableDeclaration*> *arguments_;
	StatementsBlock *statements_;
};

class FunctionCall: public Expression {
public:
	FunctionCall(Identifier *function_name, std::vector<Expression *> *arguments);

	virtual void GenerateCode(std::ostream& output);
	virtual void PrintTree(std::ostream& output);
private:
	Identifier* identifier_;
	std::vector<Expression*> *arguments_;
};
#endif

