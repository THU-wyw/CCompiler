#include "SyntaxNode.h"
using namespace std;
void Program::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	output << "public class " << "ClassName" << "{" << endl;
	for(auto iter = declarations_.begin(); iter != declarations_.end(); iter++)
	{
		(*iter)->GenerateCode(output);
	}
	output << "}" <<endl;
}

void Program::PushDeclaration(Declaration* declaration) {
	this->declarations_.push_back(declaration);
}

Identifier::Identifier(std::string& name): name_(name) {

}

void Identifier::GenerateCode(ostream& output)
{
	//TODO for sister yuan yang
	output << this->name_;
}

ImmediateInteger::ImmediateInteger(int value): value_(value) {

}

void ImmediateInteger::GenerateCode(ostream& output)
{
	//TODO for sister yuan yang
	output << value_;
}

StringLiteral::StringLiteral(string& value): value_(value) {

}

void StringLiteral::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	output << value_;
}

UnaryExpression::UnaryExpression(Expression *expression, Operator unary_operator):
	expression_(expression),
	unary_operator_(unary_operator) {

}

void UnaryExpression::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*Expression* expression_;
	//possible value : _--, _++, --_, ++_, &, *, +, -, ~, !
	Operator unary_operator_;*/
	switch (unary_operator_)
	{
	case UnaryExpression::INC_PRE:
		output << "++(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	case UnaryExpression::DEC_PRE:
		output << "--(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	case UnaryExpression::INC_AFTER:
		output << "(";
		expression_->GenerateCode(output);
		output << ")++";
		break;
	case UnaryExpression::DEC_AFTER:
		output << "(";
		expression_->GenerateCode(output);
		output << ")--";
		break;
	case UnaryExpression::REFERENCE:
		output << "&(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	case UnaryExpression::DEREFERENCE:
		output << "*(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	case UnaryExpression::MINUS:
		output << "-(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	case UnaryExpression::NOT_BIT:
		output << "~(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	case UnaryExpression::NOT:
		output << "!(";
		expression_->GenerateCode(output);
		output << ")";
		break;
	default:
		break;
	}
}

BinaryExpression::BinaryExpression(Expression* left, Expression* right, Operator binary_operator):
	left_(left),
	right_(right),
	binary_operator_(binary_operator) {

}

void BinaryExpression::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*Operator binary_operator_;
	Expression* left_;
	Expression* right_;*/
	if(binary_operator_ == BinaryExpression::INDEX)
	{
		left_->GenerateCode(output);
		output << "[";
		right_->GenerateCode(output);
		output << "]";
		return;
	}

	left_->GenerateCode(output);
	switch (binary_operator_)
	{
		case BinaryExpression::ADD:
			output << " + ";
			break;
		case BinaryExpression::SUB:
			output << " - ";
			break;
		case BinaryExpression::MUL:
			output << " * ";
			break;
		case BinaryExpression::DIV:
			output << " / ";
			break;
		case BinaryExpression::MOD:
			output << " % ";
			break;
		case BinaryExpression::DOT:
			output << ".";
			break;
		case BinaryExpression::POINTER:
			output << " -> ";
			break;
		case BinaryExpression::SHIFT_LEFT:
			output << " << ";
			break;
		case BinaryExpression::SHIFT_RIGHT:
			output << " > ";
			break;
		case BinaryExpression::LESS:
			output << " < ";
			break;
		case BinaryExpression::GREATER:
			output << " > ";
			break;
		case BinaryExpression::LESS_EQUAL:
			output << " <= ";
			break;
		case BinaryExpression::GREATER_EQUAL:
			output << " >= ";
			break;
		case BinaryExpression::EQUAL:
			output << " == ";
			break;
		case BinaryExpression::NOT_EQUAL:
			output << " != ";
			break;
		case BinaryExpression::AND_BIT:
			output << " & ";
			break;
		case BinaryExpression::XOR_BIT:
			output << " ^ ";
			break;
		case BinaryExpression::OR_BIT:
			output << " | ";
			break;
		case BinaryExpression::AND:
			output << " && ";
			break;
		case BinaryExpression::OR:
			output << " || ";
			break;
		default:
			break;
	}
	right_->GenerateCode(output);
}

AssignmentExpression::AssignmentExpression(Expression *left, Expression *right, Operator assignment_operator):
	unary_expression_(left),
	assignment_expression_(right),
	assignment_operator_(assignment_operator) {

}

void AssignmentExpression::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*Operator assignment_operator_;
	Expression *unary_expression_;
	Expression *assignment_expression_;*/
	unary_expression_->GenerateCode(output);
	switch (assignment_operator_)
	{
	case AssignmentExpression::ASSIGN:
		output << " = ";
		break;
	case AssignmentExpression::ADD_ASSIGN:
		output << " += ";
		break;
	case AssignmentExpression::SUB_ASSIGN:
		output << " -= ";
		break;
	case AssignmentExpression::MUL_ASSIGN:
		output << " *= ";
		break;
	case AssignmentExpression::DIV_ASSIGN:
		output << " /= ";
		break;
	case AssignmentExpression::MOD_ASSIGN:
		output << " %= ";
		break;
	case AssignmentExpression::SHIFT_LEFT_ASSIGN:
		output << " <<= ";
		break;
	case AssignmentExpression::SHIFT_RIGHT_ASSIGN:
		output << " >>= ";
		break;
	case AssignmentExpression::EXCLUSIVE_OR_ASSIGN:
		output << " ^= ";
		break;
	case AssignmentExpression::INCLUSIVE_OR_ASSIGN:
		output << " |= ";
		break;
	case AssignmentExpression::AND_ASSIGN:
		output << " &= ";
		break;
	default:
		break;
	}
	assignment_expression_->GenerateCode(output);
}

void StatementsBlock::PushStatement(Statement *statement) {
	this->statements_.push_back(statement);
}

void StatementsBlock::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*std::vector<Statement*> statements_;
	Expression* init_value;*/
	output << "{" << endl;
	for(auto iter = this->statements_.begin(); iter != this->statements_.end(); iter++)
	{
		(*iter)->GenerateCode(output);
		output << ";" << endl;
	}
	output << "}" << endl;
	//this->init_value->GenerateCode(output);
}

IfStatement::IfStatement(Expression *condition, Statement *then_statement, Statement *else_statement /* = NULL */) {
	this->condition_ = condition;
	this->then_statement_ = then_statement;
	this->else_statement_ = then_statement_;
}

void IfStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*Expression* condition_;
	Statement* then_statement_;
	Statement* else_statement_;*/
	output << "if(";
	this->condition_->GenerateCode(output);
	output << ")";
	this->then_statement_->GenerateCode(output);

	if(else_statement_ != NULL)
	{
		output << "else";
		this->else_statement_->GenerateCode(output);
	}
}

JumpStatement::JumpStatement(JumpType jump_type) {
	this->type_ = jump_type;
}

void JumpStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	switch (type_)
	{
	case JumpStatement::CONTINUE:
		output << "continue";
		break;
	case JumpStatement::BREAK:
		output << "break";
		break;
	default:
		break;
	}
}

ReturnStatement::ReturnStatement(Expression* return_value):
	return_value_(return_value) {

}

void ReturnStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	//Expression * return_value_;
	output << "return ";
	return_value_->GenerateCode(output);
}

WhileStatement::WhileStatement(Expression *condition, Statement *body, bool has_do /* = false */) {
	this->condition_ = condition;
	this->body_ = body;
	this->has_do_ = has_do;
}

void WhileStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*Expression* condition_;
	Statement* body_;
	bool has_do_;*/
	if(has_do_)
	{
		output << "do{"<<endl;
		body_->GenerateCode(output);
		output << "while(";
		condition_->GenerateCode(output);
		output << ")";
	}
	else
	{
		output << "while(";
		condition_->GenerateCode(output);
		output << ")";
		body_->GenerateCode(output);
	}
}

ForStatement::ForStatement(Statement* initializer, Expression* operation, Expression* condition, Statement* body) {
	this->initializer_ = initializer;
	this->operation_ = operation;
	this->condition_ = condition;
	this->body_ = body;
}

void ForStatement::GenerateCode(std::ostream& output) {
	//TODO for sister yuan yang
	/*Statement* initializer_;
	Expression* operation_;
	Expression* condition_;
	Statement* body_;*/
	output << "for(";
	initializer_->GenerateCode(output);
	output <<"; ";
	condition_->GenerateCode(output);
	output <<"; ";
	operation_->GenerateCode(output);
	output << ")";
	body_->GenerateCode(output);
}

ExpressionStatement::ExpressionStatement(Expression *expression) {
	this->expression_ = expression;
}

void ExpressionStatement::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	if (this->expression_ != NULL) {
		expression_->GenerateCode(output);
	}
}

VariableDeclaration::VariableDeclaration() {
	this->identifier_ = NULL;
	this->initializer_ = NULL;
}

void VariableDeclaration::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*Identifier	*identifier_;
	Type* type_;
	Expression *initializer_;*/
	//TODO for Type

	output << " ";
	identifier_->GenerateCode(output);
	if(initializer_ != NULL)
	{
		output << " = ";
		this->initializer_->GenerateCode(output);
	}
}

FunctionDeclaration::FunctionDeclaration(Identifier *identifier, std::vector<VariableDeclaration*> *arguments) {
	this->identifier_ = identifier;
	this->arguments_ = arguments;
}

void FunctionDeclaration::GenerateCode(ostream& output) {
	//TODO for sister yuan yangs
	/*	
	Type* return_type_;
	Identifier *identifier_;
	std::vector<VariableDeclaration*> *arguments_;
	StatementsBlock *statements_;
	*/
	//修饰符
	if(this->identifier_->getName() == "main")//main函数特殊处理
	{
		output << "public static void main(String[] args)";
	}
	else
	{
		output << "public static ";
		//返回值
		//TODO for type

		//函数名
		this->identifier_->GenerateCode(output);

		//参数列表
		output << "(";
		for(auto iter = this->arguments_->begin(); iter != this->arguments_->end(); iter++)
		{
			(*iter)->GenerateCode(output);
			if(iter != this->arguments_->end()-1)
				output << ", ";
		}
		output << ")";
	}

	//函数定义
	this->statements_->GenerateCode(output);
}

FunctionCall::FunctionCall(Identifier *function_name, std::vector<Expression *> *arguments) {
	this->identifier_ = function_name;
	this->arguments_ = arguments;
}

void FunctionCall::GenerateCode(ostream& output) {
	//TODO for sister yuan yang
	/*	Identifier* identifier_;
	std::vector<Expression*> *arguments_;*/
	//special cases to be added
	identifier_->GenerateCode(output);
	output << "(";
	for(auto iter = arguments_->begin(); iter != arguments_->end(); iter++)
	{
		(*iter)->GenerateCode(output);
		if(iter != arguments_->end() - 1)
			output <<", ";
	}
	output << ")";
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

void ForStatement::PrintTree(std::ostream& output) {
	output << "ForStatement: " << endl;
	printStr(output, "Initializer: ");
	printNode(output, initializer_);
	printStr(output, "Operation: ");
	printNode(output, operation_);
	printStr(output, "Condition: ");
	printNode(output, condition_);
	printStr(output, "LoopBody: ");
	printNode(output, body_);
}

void ExpressionStatement::PrintTree(ostream& output)
{
	output << "ExpressionStatement:" << endl;
	if (this->expression_ != NULL) {
		printNode(output, expression_);
	} else {

	}
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