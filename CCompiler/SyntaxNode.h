#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class VariableDeclaration;
class FunctionDeclaration;
class FunctionDefinition;
class Declaration;
class SyntaxNode {
public:
	//virtual ~SyntaxNode() = 0;
	virtual void codeGen(ostream& output) = 0;
	virtual void printTree(ostream& output) = 0;
	
};

class Program: public SyntaxNode {
public:
	void pushDeclaration(Declaration* d){
		declarations_.push_back(d);
	}
	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	vector<Declaration*> declarations_;
};

class Expression: public SyntaxNode {
public:
	enum Type {
		UNARY,
		BINARY,
		ASSIGN
	}type;
	void codeGen(ostream& output);
	void printTree(ostream& output);
};

class Identifier: public Expression {
public:
	Identifier(const std::string& name) { name_ = name; }
	inline const std::string& getName() { return this->name_; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	std::string name_;

};

class ImmediateInteger: public Expression {
public:
	ImmediateInteger(int value) { value_ = value; }
	
	void codeGen(ostream& output);
	void printTree(ostream& output);

private:
	int value_;
};

class StringLiteral : public Expression {
public:
	StringLiteral(std::string value) { value_ = value; }
	
	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	std::string value_;
};

class UnaryExpression: public Expression {
public:	
	UnaryExpression(Expression *e, string opt)
	{
		unary_operator_ = opt;
		expression_ = e;
		type = UNARY;
	}

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	Expression* expression_;
	//possible value : _--, _++, --_, ++_, &, *, +, -, ~, !
	string unary_operator_;

};

class BinaryExpression: public Expression {
public:
	BinaryExpression(Expression* left, Expression* right, string opt)
	{
		left_ = left;
		right_ = right;
		binary_operator = opt;
		type = BINARY;
	} 

	void codeGen(ostream& output);
	void printTree(ostream& output);

private:
	// possible value : +, -, *, /, %, [], ., ->, <<, >>, <, >, <=, >=, 
	//                  ==, !=, &, ^, |, &&, ||
	string binary_operator;
	Expression* left_;
	Expression* right_;
};

class AssignmentExpression: public Expression {
public:
	AssignmentExpression(Expression *left, Expression *right, string opt)
	{
		unary_expression_ = left;
		assignment_expression_ = right;
		assignment_operator = opt;
		type = ASSIGN;
	}

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	string assignment_operator;
	Expression *unary_expression_;
	Expression *assignment_expression_;
};

class VariableType: public SyntaxNode {
public:
	enum Type{
		VOID,
		CHAR,
		INT,
		FLOAT
	};
	VariableType():type(VOID), pointer(0){}
	Type type;
	int pointer;
	vector<Expression *> array;

	void codeGen(ostream& output);
	void printTree(ostream& output);
};

class Statement: public SyntaxNode {
public:
	enum Type{
		BLOCK,
		IF,
		JUMP,
		RETURN,
		WHILE,
		EXPRESSION,
		DECLARATION
	}type;

	void codeGen(ostream& output);
	void printTree(ostream& output);
};

class StatementsBlock: public Statement {
public:
	void pushStatement(Statement *s){
		statements_.push_back(s);
		type = BLOCK;
	}

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	vector<Statement*> statements_;
	Expression* init_value;
};

class IfStatement: public Statement {
public:
	IfStatement(Expression *cond, Statement *thenS=NULL, Statement *elseS=NULL)
		:condition_(cond), then_statements_(thenS), else_statements_(elseS){ type = IF; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	Expression* condition_;
	Statement* then_statements_;
	Statement* else_statements_;
};

class JumpStatement: public Statement {
public:
	enum JumpType {
		CONTINUE,
		BREAK
	}type;
	JumpStatement(JumpType jt){ 
		Statement::type = JUMP; JumpStatement::type = jt;
	}

	void codeGen(ostream& output);
	void printTree(ostream& output);
};

class ReturnStatement: public Statement {
public:
	ReturnStatement(Expression* rv): return_value_(rv){ type = RETURN; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	Expression * return_value_;
};

class WhileStatement: public Statement {
public:
	WhileStatement(Expression *cond, Statement *sb, bool hasDo = false)
		: condition_(cond), body_(sb), has_do_(hasDo) { type = WHILE; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	Expression* condition_;
	Statement* body_;
	bool has_do_;
};

class ExpressionStatement: public Statement {
public:
	ExpressionStatement(Expression *e):expression_(e){ type = EXPRESSION; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	Expression* expression_;
};

class Declaration : public Statement{
public:
	enum Type{
		VARIABLE,
		FUNCTION
	} type;
	Declaration(){ Statement::type = DECLARATION; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
};

class VariableDeclaration: public Declaration {
public:
	VariableDeclaration():identifier(NULL), initializer(NULL){ Declaration::type = VARIABLE; }
	Identifier	*identifier;
	VariableType vt;
	Expression *initializer;

	void codeGen(ostream& output);
	void printTree(ostream& output);
};

class FunctionDeclaration: public Declaration {
public:
	FunctionDeclaration(Identifier *ident, vector<VariableDeclaration*> *v)
		:identifier_(ident), arguments_(v){ type = FUNCTION; }
	void setReturnType(VariableType vt){ return_type_ = vt; }
	void setStatementsBlock(Statement *sb) { statements_ = (StatementsBlock*)sb; }

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	VariableType return_type_;
	Identifier *identifier_;
	vector<VariableDeclaration*> *arguments_;
	StatementsBlock *statements_;
};

class FunctionCall: public Expression {
public:
	FunctionCall(Expression *func, vector<Expression *> *v){
		identifier_ = (Identifier*) func;
		arguments_ = (vector<Identifier*>*)v;
	}

	void codeGen(ostream& output);
	void printTree(ostream& output);
private:
	Identifier* identifier_;
	vector<Identifier*> *arguments_;
};
#endif

