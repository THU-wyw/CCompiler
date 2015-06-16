#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class VariableDeclaration;
class FunctionDeclaration;
class FunctionDefinition;
class ExternalDeclaration;
class SyntaxNode {
public:
	//virtual ~SyntaxNode() = 0;
	virtual void codeGen(std::ostream& output) = 0;
	
};

class ExternalDeclaration : public SyntaxNode {
public:
	enum Type{
		VARIABLE_DECLARATION,
		FUNCTION_DECLARATION
	} type;

	union Declaration{
		VariableDeclaration *vd;
		FunctionDeclaration *fd;
	} declaration;

	ExternalDeclaration(Type t, Declaration d):type(t) {
		if (t == VARIABLE_DECLARATION){
			declaration.vd = d;
		}
		else{
			declaration.fd = d;
		}
	}
};

class Program: public SyntaxNode {
public:
	void pushDeclaration(ExternalDeclaration* e){
		_externalDeclarations.pushback(e);
	}
private:
	vector<ExternalDeclaration*> _externalDeclarations;
};

class Expression: public SyntaxNode {
};

class Identifier: public Expression {
public:
	Identifier(const std::string& name) { _name = name; }
	inline const std::string& getName() { return this->name_; }
	void codeGen(std::ostream& output) {}
private:
	std::string _name;

};

class ImmediateInteger: public Expression {
public:
	ImmediateInteger(int value) { _value = value; }
	void codeGen(std::ostream& output) {}

private:
	int _value;
};

class StringLiteral : public Expression {
public:
	StringLiteral(std::string value) { _value = value; }
	void codeGen(std::ostream& output) {}
private:
	std::string _value;
};

class UnaryExpression: public Expression {
public:	
	UnaryExpression(const Expression *e, string opt)
	{
		_unaryOperator = opt;
		_expression = e;
	}
private:
	Expression* _expression;
	//possible value : _--, _++, --_, ++_, &, *, +, -, ~, !
	string _unaryOperator;

};

class BinaryExpression: public Expression {
public:
	BinaryExpression(const Expression* left, const Expression* right, string opt)
	{
		_left = left;
		_right = right;
		_binaryOperator = opt;
	} 

private:
	// possible value : +, -, *, /, %, [], ., ->, <<, >>, <, >, <=, >=, 
	//                  ==, !=, &, ^, |, &&, ||
	string _binaryOperator;
	Expression* _left;
	Expression* _right;
};

class AssignmentExpression: public Expression {
public:
	AssignmentExpression(Expression *left, Expression *right, string opt)
	{
		_unaryExpression = left;
		_assignmentExpression = right;
		_assignmentOperator = opt;
	}
private:
	string _assignmentOperator;
	Expression *_unaryExpression;
	Expression *_assignmentExpression;
};

class Statement: public SyntaxNode {
public:
	virtual ~Statement() = 0;
};

class VariableType: public SyntaxNode {
public:
	enum Type{
		VOID,
		CHAR,
		INT,
		FLOAT
	};
	VariableType():type(Type::VOID), pointer(0){}
	Type type;
	int pointer;
	vector<Expression *> array;
};

class VariableDeclaration: public Statement {
public:
	VariableDeclaration():identifier(NULL), initializer(NULL){}
	Identifier	*identifier;
	VariableType vt;
	Expression *initializer;
};

class StatementsBlock: public Statement {
public:
	void pushStatement(Statement *s){
		_statements.pushback(s);
	}
private:
	vector<Statement*> _statements;
	Expression* _initValue;
};

class IfStatement: public Statement {
public:
	IfStatement(Expression *cond, StatementsBlock *thenS=NULL, StatementsBlock *elseS=NULL)
		:_condition(cond), _thenStatements(thenS), _elseStatements(elseS){}
private:
	Expression* _condition;
	StatementsBlock* _thenStatements;
	StatementsBlock* _elseStatements;
};

class JumpStatement: public Statement {
public:
	enum JumpType {
		CONTINUE,
		BREAK
	}type;
};

class ReturnStatement: public Statement {
public:
	ReturnStatement(Expression* rv): returnValue(rv){}
private:
	Expression * returnValue;
};

class WhileStatement: public Statement {
public:
	WhileStatement(Expression *cond, StatementsBlock, *sb, bool hasDo = false)
		: _condition(cond), _body(sb), _hasDo(hasDo) {}
private:
	Expression* _condition;
	StatementsBlock* _body;
	bool _hasDo;
};

class ExpressionStatement: public Statement {
public:
	ExpressionStatement(Expression *e):_expression(e){}
private:
	Expression* _expression;
};

class FunctionDeclaration: public Statement {
public:
	FunctionDeclaration(Identifier *ident, vector<VariableDeclaration*> *v;)
		:_identifier(ident), _arguments(v){}
	void setReturnType(VariableType vt){ _returnType = vt; }
	void setStatementBlock(StatementsBlock *sb) { _statements = sb; }
private:
	VariableType _returnType;
	Identifier *_identifier;
	vector<VariableDeclaration*> *_arguments;
	StatementsBlock *_statements;
};

class FunctionCall: public Expression {
public:
	FunctionCall(Indentifier *func, vector<Identifier *> *v;)
		:_identifier(ident), _arguments(v){}
private:
	Identifier* _identifier;
	vector<Identifier*> _arguments;
};
#endif

