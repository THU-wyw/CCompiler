#include "SyntaxNode.h"
using namespace std;
void Program::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

void Program::PushDeclaration(Declaration* declaration) {
	this->declarations_.push_back(declaration);
}

Identifier::Identifier(std::string& name): name_(name) {

}

void Identifier::GenerateCode(ostream& output)
{
	//TODO for sister yuan yang
}

ImmediateInteger::ImmediateInteger(int value): value_(value) {

}

void ImmediateInteger::GenerateCode(ostream& output)
{
	//TODO for sister yuan yang
}

StringLiteral::StringLiteral(string& value): value_(value) {

}

void StringLiteral::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

UnaryExpression::UnaryExpression(Expression *expression, Operator unary_operator):
	expression_(expression),
	unary_operator_(unary_operator) {

}

void UnaryExpression::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

BinaryExpression::BinaryExpression(Expression* left, Expression* right, Operator binary_operator):
	left_(left),
	right_(right),
	binary_operator_(binary_operator) {

}

void BinaryExpression::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

AssignmentExpression::AssignmentExpression(Expression *left, Expression *right, Operator assignment_operator):
	unary_expression_(left),
	assignment_expression_(right),
	assignment_operator_(assignment_operator) {

}

void AssignmentExpression::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

void StatementsBlock::PushStatement(Statement *statement) {
	this->statements_.push_back(statement);
}

void StatementsBlock::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

IfStatement::IfStatement(Expression *condition, Statement *then_statement, Statement *else_statement /* = NULL */) {
	this->condition_ = condition;
	this->then_statement_ = then_statement;
	this->else_statement_ = then_statement_;
}

void IfStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

JumpStatement::JumpStatement(JumpType jump_type) {
	this->type_ = jump_type;
}

void JumpStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

ReturnStatement::ReturnStatement(Expression* return_value):
	return_value_(return_value) {

}

void ReturnStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

WhileStatement::WhileStatement(Expression *condition, Statement *body, bool has_do /* = false */) {
	this->condition_ = condition;
	this->body_ = body;
	this->has_do_ = has_do;
}

void WhileStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

ExpressionStatement::ExpressionStatement(Expression *expression) {
	this->expression_ = expression;
}

void ExpressionStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

VariableDeclaration::VariableDeclaration() {
	this->identifier_ = NULL;
	this->initializer_ = NULL;
}

void VariableDeclaration::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

FunctionDeclaration::FunctionDeclaration(Identifier *identifier, std::vector<VariableDeclaration*> *arguments) {
	this->identifier_ = identifier;
	this->arguments_ = arguments;
}

void FunctionDeclaration::GenerateCode(ostream& output) {
	//TODO for sister yuan yangs
}

FunctionCall::FunctionCall(Identifier *function_name, std::vector<Expression *> *arguments) {
	this->identifier_ = function_name;
	this->arguments_ = arguments;
}

void FunctionCall::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
}

int tabs = 0;
void printTabs(ostream& output)
{
	int i;
	for (i = 0; i < tabs; i++)
	{
		output << "\t";
	}
}

void printNode(ostream& output, SyntaxNode *sn)
{
	tabs ++; printTabs(output);
	sn->PrintTree(output);
	tabs --;
}

void printStr(ostream& output, string s)
{
	tabs ++; printTabs(output);
	output << s << endl;
	tabs --;
}

void Program::PrintTree(ostream& output)
{
	output << "Program" << endl;
	vector<Declaration*>::iterator iter;
	for (iter = declarations_.begin(); iter != declarations_.end(); iter++)
	{
		printNode(output, (*iter));
	}
}

void Identifier::PrintTree(ostream& output)
{
	output << "Identifier: " << name_ << endl;
}

void ImmediateInteger::PrintTree(ostream& output)
{
	output << "ImmediateInteger: " << value_ << endl;
}

void StringLiteral::PrintTree(ostream& output)
{
	output << "StringLiteral: " << value_ << endl;
}

void UnaryExpression::PrintTree(ostream& output)
{
	output << "UnaryExpression: " << unary_operator_ << endl;
	printNode(output, expression_);
}

void BinaryExpression::PrintTree(ostream& output)
{
	output << "BinaryExpression: " << binary_operator_ << endl;
	printNode(output, left_);
	printNode(output, right_);
}

void AssignmentExpression::PrintTree(ostream& output)
{
	output << "AssignmentExpression: " << assignment_operator_ << endl;
	printNode(output, unary_expression_);
	printNode(output, assignment_expression_);
}


void StatementsBlock::PrintTree(ostream& output)
{
	output << "StatementsBlock:" << endl;
	vector<Statement*>::iterator iter;
	for (iter = statements_.begin(); iter != statements_.end(); iter++)
	{
		printNode(output, *iter);
	}
}

void IfStatement::PrintTree(ostream& output)
{
	output << "IfStatement:" << endl;
	printStr(output, "Condition:");
	printNode(output, condition_);
	if (then_statement_ != NULL)
	{
		printStr(output, "then:");
		printNode(output, then_statement_);
	}
	if (else_statement_ != NULL)
	{
		printStr(output, "else:");
		printNode(output, else_statement_);
	}
}

void JumpStatement::PrintTree(ostream& output)
{
	string s;
	switch(type_)
	{
	case JumpStatement::CONTINUE:
		s = "Continue";
		break; 
	case JumpStatement::BREAK:
		s = "Break";
		break;
	default:
		s = "Jump Error";
		break;
	}
	output << "JumpStatement: " << s << endl;
}

void ReturnStatement::PrintTree(ostream& output)
{
	output << "ReturnStatement: " << endl;
	printNode(output, return_value_);
}

void WhileStatement::PrintTree(ostream& output)
{
	output << "WhileStatement: " << "(has_do: " << has_do_ << ")" << endl;
	printStr(output, "Condition: ");
	printNode(output, condition_);
	printStr(output, "LoopBody: ");
	printNode(output, body_);
}

void ExpressionStatement::PrintTree(ostream& output)
{
	output << "ExpressionStatement:" << endl;
	printNode(output, expression_);
}

void Declaration::PrintTree(ostream& output)
{

}

void VariableDeclaration::PrintTree(ostream& output)
{
	output << "VariableDeclaration: " << endl;
//	printNode(output, &variable_type_);
	printNode(output, identifier_);
	if (initializer_ != NULL) printNode(output, initializer_);
}

void FunctionDeclaration::PrintTree(ostream& output)
{
	output << "FunctionDeclaration: " << endl;
	printStr(output, "ReturnType:");
//	printNode(output, &return_type_);
	printStr(output, "FunctionIdentifier:");
	printNode(output, identifier_);
	printStr(output, "FunctionArguments:");
	vector<VariableDeclaration*>::iterator iter;
	for (iter = arguments_->begin(); iter != arguments_->end(); iter++)
	{
		printNode(output, *iter);
	}
	printStr(output, "FunctionStatement:");
	printNode(output, statements_);
}

void FunctionCall::PrintTree(ostream& output)
{
	output << "FunctionCall:" << endl;
	printStr(output, "FunctionIdentifier:");
	printNode(output, identifier_);
	printStr(output, "FunctionArguments:");
	if (arguments_ == NULL) return;
	for (auto iter = arguments_->begin(); iter != arguments_->end(); iter ++)
	{
		printNode(output, *iter);
	}

}
