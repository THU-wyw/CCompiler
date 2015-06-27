#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Type.h"

class VariableDeclaration;
class FunctionDeclaration;
class FunctionDefinition;
class Declaration;
class CParserDriver;
class SyntaxNode {
public:
	//virtual ~SyntaxNode() = 0;
	virtual void GenerateCode(std::ostream& output, int indentations) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
protected:
	void PrintTabs(std::ostream& output, int tabs);
};

class Program: public SyntaxNode {
public:
	void PushDeclaration(Declaration* declaration);
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
	inline void set_main_class_name_(const std::string& class_name) { this->main_class_name_ = class_name; }
private:
	std::vector<std::unique_ptr<Declaration>> declarations_;
	std::string main_class_name_;
};

class Expression: public SyntaxNode {
public:
	virtual void GenerateCode(std::ostream& output, int indentations) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
};

class Identifier: public Expression {
public:
	Identifier(std::string& name);
	inline std::string& getName() { return this->name_; }

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::string name_;
};

class ImmediateInteger: public Expression {
public:
	ImmediateInteger(int value);
	
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);

private:
	int value_;
};

class StringLiteral: public Expression {
public:
	StringLiteral(std::string& value);
	
	virtual void GenerateCode(std::ostream& output, int indentations);
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
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Expression> expression_;
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
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);

private:
	// possible value : +, -, *, /, %, [], ., ->, <<, >>, <, >, <=, >=, 
	//                  ==, !=, &, ^, |, &&, ||
	Operator binary_operator_;
	std::unique_ptr<Expression> left_;
	std::unique_ptr<Expression> right_;
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

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	Operator assignment_operator_;
	std::unique_ptr<Expression> unary_expression_;
	std::unique_ptr<Expression> assignment_expression_;
};

class Statement: public SyntaxNode {
public:
	virtual void GenerateCode(std::ostream& output, int indentations) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
};

class StatementsBlock: public Statement {
public:
	void PushStatement(Statement *statement);

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::vector<std::unique_ptr<Statement>> statements_;
	std::unique_ptr<Expression> init_value;
};

class IfStatement: public Statement {
public:
	IfStatement(Expression *condition, Statement *then_statement, Statement *else_statement = NULL);

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Expression> condition_;
	std::unique_ptr<Statement> then_statement_;
	std::unique_ptr<Statement> else_statement_;
};

class JumpStatement: public Statement {
public:
	enum JumpType {
		CONTINUE,
		BREAK
	};
	JumpStatement(JumpType jump_type);
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	JumpType type_;
};

class ReturnStatement: public Statement {
public:
	ReturnStatement(Expression* return_value);

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Expression> return_value_;
};

class WhileStatement: public Statement {
public:
	WhileStatement(Expression *condition, Statement *body, bool has_do = false);

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Expression> condition_;
	std::unique_ptr<Statement> body_;
	bool has_do_;
};

class ForStatement: public Statement {
public:
	ForStatement(VariableDeclaration* initializer, Expression* operation, Expression* condition, Statement* body);
	ForStatement(Expression* initializer, Expression* operation, Expression* condition, Statement* body);
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);

private:
	std::unique_ptr<Expression> expression_initializer_;
	std::unique_ptr<VariableDeclaration> declaration_initializer_;
	std::unique_ptr<Expression> operation_;
	std::unique_ptr<Expression> condition_;
	std::unique_ptr<Statement> body_;
};

class ExpressionStatement: public Statement {
public:
	ExpressionStatement(Expression *expression);

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Expression> expression_;
};

class DeclarationStatement: public Statement {
public:
	DeclarationStatement(VariableDeclaration* declaration);
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);

private:
	std::unique_ptr<VariableDeclaration> declaration_;
};

class Declaration : public Statement {
public:
	virtual void GenerateCode(std::ostream& output, int indentations) = 0;
	virtual void PrintTree(std::ostream& output) = 0;
};

class VariableDeclaration: public Declaration {
public:
	VariableDeclaration();
	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
	inline void AddArraySpecifier(Expression* expression) { this->type_ = Type::CreateArrayType(expression, type_.release()); }
	inline void AddPointerSpecifier() { this->type_ = Type::CreatePointerType(type_.release()); }
	inline void set_basic_type(Type::BasicType basic_type) { this->type_->SetRootType(basic_type); }
	inline void set_initializer(Expression* initializer) { this->initializer_ = initializer; }
	inline void set_identifier(Identifier* identifier) { this->identifier_ = std::unique_ptr<Identifier>(identifier); }
	void SetAsFunctionDeclaration(FunctionDeclaration& function);
private:
	std::unique_ptr<Identifier> identifier_;
	std::unique_ptr<Type> type_;
	Expression *initializer_;
};

class FunctionDeclaration: public Declaration {
public:
	FunctionDeclaration(std::vector<VariableDeclaration*>& arguments);
	inline void set_identifier(Identifier* identifier) { identifier_ = std::unique_ptr<Identifier>(identifier); }
	inline void set_return_type(Type* return_type){ return_type_ = std::unique_ptr<Type>(return_type); }
	inline void set_body(Statement *body) { statements_ = std::unique_ptr<StatementsBlock>(static_cast<StatementsBlock*>(body)); }

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Type> return_type_;
	std::unique_ptr<Identifier> identifier_;
	std::vector<std::unique_ptr<VariableDeclaration>> arguments_;
	std::unique_ptr<StatementsBlock> statements_;
};

class FunctionCall: public Expression {
public:
	FunctionCall(Identifier *function_name, std::vector<Expression *>& arguments);

	virtual void GenerateCode(std::ostream& output, int indentations);
	virtual void PrintTree(std::ostream& output);
private:
	std::unique_ptr<Identifier> identifier_;
	std::vector<std::unique_ptr<Expression>> arguments_;
};
#endif

