#include "SyntaxNode.h"
#include <fstream>
using namespace std;
void Program::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	PrintTabs(output, indentations);
	output << "public class " << this->main_class_name_ << "{" << endl;
	for(auto iter = declarations_.begin(); iter != declarations_.end(); iter++)
	{
		(*iter)->GenerateCode(output, indentations + 1);
	}
	PrintTabs(output, indentations);
	output << "}" <<endl;
}

void SyntaxNode::PrintTabs(std::ostream& output, int tabs) {
	output << string(4 * tabs, ' ');
}

void Program::PushDeclaration(Declaration* declaration) {
	this->declarations_.push_back(unique_ptr<Declaration>(declaration));
}

Identifier::Identifier(std::string& name): name_(name) {

}

void Identifier::GenerateCode(ostream& output, int indentations)
{
	//TODO for sister yuan yang
	output << this->name_;
}

ImmediateInteger::ImmediateInteger(int value): value_(value) {

}

void ImmediateInteger::GenerateCode(ostream& output, int indentations)
{
	//TODO for sister yuan yang
	output << value_;
}

StringLiteral::StringLiteral(string& value): value_(value) {

}

void StringLiteral::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	output << value_;
}

UnaryExpression::UnaryExpression(Expression *expression, Operator unary_operator):
	expression_(expression),
	unary_operator_(unary_operator) {

}

void UnaryExpression::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Expression* expression_;
	//possible value : _--, _++, --_, ++_, &, *, +, -, ~, !
	Operator unary_operator_;*/
	switch (unary_operator_)
	{
	case UnaryExpression::INC_PRE:
		output << "++(";
		break;
	case UnaryExpression::DEC_PRE:
		output << "--(";
		break;
	case UnaryExpression::INC_AFTER:
		output << "(";
		break;
	case UnaryExpression::DEC_AFTER:
		output << "(";
		break;
	case UnaryExpression::REFERENCE:
		output << "&(";
		break;
	case UnaryExpression::DEREFERENCE:
		output << "*(";
		break;
	case UnaryExpression::MINUS:
		output << "-(";
		break;
	case UnaryExpression::NOT_BIT:
		output << "~(";
		break;
	case UnaryExpression::NOT:
		output << "!(";
		break;
	default:
		break;
	}
	expression_->GenerateCode(output, indentations);
	output << ")";
}

BinaryExpression::BinaryExpression(Expression* left, Expression* right, Operator binary_operator):
	left_(left),
	right_(right),
	binary_operator_(binary_operator) {

}

void BinaryExpression::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Operator binary_operator_;
	Expression* left_;
	Expression* right_;*/
	if(binary_operator_ == BinaryExpression::INDEX)
	{
		left_->GenerateCode(output, indentations);
		output << "[";
		right_->GenerateCode(output, indentations);
		output << "]";
		return;
	}

	left_->GenerateCode(output, indentations);
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
	right_->GenerateCode(output, indentations);
}

AssignmentExpression::AssignmentExpression(Expression *left, Expression *right, Operator assignment_operator):
	unary_expression_(left),
	assignment_expression_(right),
	assignment_operator_(assignment_operator) {

}

void AssignmentExpression::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Operator assignment_operator_;
	Expression *unary_expression_;
	Expression *assignment_expression_;*/
	unary_expression_->GenerateCode(output, indentations);
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
	assignment_expression_->GenerateCode(output, indentations);
}

void StatementsBlock::PushStatement(Statement *statement) {
	this->statements_.push_back(unique_ptr<Statement>(statement));
}

void StatementsBlock::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*std::vector<Statement*> statements_;
	Expression* init_value;*/
	PrintTabs(output, indentations - 1);
	output << "{" << endl;
	for(auto iter = this->statements_.begin(); iter != this->statements_.end(); iter++)
	{
		(*iter)->GenerateCode(output, indentations);
	}
	PrintTabs(output, indentations - 1);
	output << "}" << endl;
	//this->init_value->GenerateCode(output);
}

IfStatement::IfStatement(Expression *condition, Statement *then_statement, Statement *else_statement /* = nullptr */)
	: condition_(condition),
	then_statement_(then_statement),
	else_statement_(else_statement) {
}

void IfStatement::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Expression* condition_;
	Statement* then_statement_;
	Statement* else_statement_;*/
	PrintTabs(output, indentations);
	output << "if (";
	this->condition_->GenerateCode(output, indentations + 1);
	output << ")" << endl;
	this->then_statement_->GenerateCode(output, indentations + 1);

	if(else_statement_)
	{
		PrintTabs(output, indentations);
		output << "else " << endl;
		this->else_statement_->GenerateCode(output, indentations + 1);
	}
}

JumpStatement::JumpStatement(JumpType jump_type) {
	this->type_ = jump_type;
}

void JumpStatement::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	PrintTabs(output, indentations);
	switch (type_)
	{
	case JumpStatement::CONTINUE:
		output << "continue;" << endl;
		break;
	case JumpStatement::BREAK:
		output << "break;" << endl;
		break;
	default:
		break;
	}
}

ReturnStatement::ReturnStatement(Expression* return_value):
	return_value_(return_value) {

}

void ReturnStatement::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	//Expression * return_value_;
	PrintTabs(output, indentations);
	output << "return";
	if (return_value_) {
		output << " ";
		return_value_->GenerateCode(output, indentations);
	}
	output << ";" << endl;
}

WhileStatement::WhileStatement(Expression *condition, Statement *body, bool has_do /* = false */)
	: condition_(condition),
	body_(body),
	has_do_(has_do) {
}

void WhileStatement::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Expression* condition_;
	Statement* body_;
	bool has_do_;*/
	if(has_do_)
	{
		PrintTabs(output, indentations);
		output << "do {" << endl;
		body_->GenerateCode(output, indentations + 1);
		PrintTabs(output, indentations);
		output << "while (";
		condition_->GenerateCode(output, indentations);
		output << ")";
	}
	else
	{
		PrintTabs(output, indentations);
		output << "while (";
		condition_->GenerateCode(output, indentations);
		output << ")" << endl;
		body_->GenerateCode(output, indentations + 1);
	}
}

ForStatement::ForStatement(Expression* initializer, Expression* operation, Expression* condition, Statement* body)
	: expression_initializer_(initializer),
	declaration_initializer_(nullptr),
	operation_(operation),
	condition_(condition),
	body_(body) {
}

ForStatement::ForStatement(VariableDeclaration* initializer, Expression* operation, Expression* condition, Statement* body)
	: expression_initializer_(nullptr),
	declaration_initializer_(initializer),
	operation_(operation),
	condition_(condition),
	body_(body) {
}

void ForStatement::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Statement* initializer_;
	Expression* operation_;
	Expression* condition_;
	Statement* body_;*/
	PrintTabs(output, indentations);
	output << "for (";
	if (expression_initializer_ != nullptr)
		expression_initializer_->GenerateCode(output, indentations);
	else 
		declaration_initializer_->GenerateCode(output, indentations);
	output <<"; ";
	condition_->GenerateCode(output, indentations);
	output <<"; ";
	operation_->GenerateCode(output, indentations);
	output << ")" << endl;
	body_->GenerateCode(output, indentations + 1);
}

ExpressionStatement::ExpressionStatement(Expression *expression)
	: expression_(expression) {
}

void ExpressionStatement::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	PrintTabs(output, indentations);
	if (expression_) {
		expression_->GenerateCode(output, indentations);
	}
	output << ";" << endl;
}

DeclarationStatement::DeclarationStatement(VariableDeclaration* declaration)
	: declaration_(declaration) {

}

void DeclarationStatement::GenerateCode(ostream& output, int indentations) {
	PrintTabs(output, indentations);
	this->declaration_->GenerateCode(output, indentations);
	output << ";" << endl;
}

void DeclarationStatement::PrintTree(std::ostream& output) {

}

VariableDeclaration::VariableDeclaration()
	: identifier_(nullptr),
	initializer_(nullptr) {
	this->type_ = Type::CreateBasicType();
}

void VariableDeclaration::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*Identifier	*identifier_;
	Type* type_;
	Expression *initializer_;*/
	//TODO for Type
	type_->PrintTypeName(output);
	output << " ";
	identifier_->GenerateCode(output, indentations);
	if(initializer_ != nullptr)
	{
		output << " = ";
		this->initializer_->GenerateCode(output, indentations);
	}
}

void VariableDeclaration::SetAsFunctionDeclaration(FunctionDeclaration& function) {
	function.set_return_type(this->type_.release());
	function.set_identifier(this->identifier_.release());
}

FunctionDeclaration::FunctionDeclaration(std::vector<VariableDeclaration*>& arguments) {
	for (auto argument: arguments) {
		this->arguments_.push_back(unique_ptr<VariableDeclaration>(argument));
	}
}

void FunctionDeclaration::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yangs
	/*	
	Type* return_type_;
	Identifier *identifier_;
	std::vector<VariableDeclaration*> *arguments_;
	StatementsBlock *statements_;
	*/
	//修饰符
	PrintTabs(output, indentations);
	if(this->identifier_->getName() == "main")//main函数特殊处理
	{
		output << "public static void main(String[] args)" << endl;
	}
	else
	{
		output << "public static ";
		//返回值
		//TODO for type

		//函数名
		this->identifier_->GenerateCode(output, indentations);

		//参数列表
		output << "(";
		for(auto iter = this->arguments_.begin(); iter != this->arguments_.end(); iter++)
		{
			(*iter)->GenerateCode(output, indentations);
			if(iter != this->arguments_.end()-1)
				output << ", ";
		}
		output << ")" << endl;
	}

	//函数定义
	this->statements_->GenerateCode(output, indentations + 1);
}

FunctionCall::FunctionCall(Identifier *function_name, std::vector<Expression *>& arguments) {
	this->identifier_ = unique_ptr<Identifier>(function_name);
	for (auto argument: arguments) {
		this->arguments_.push_back(unique_ptr<Expression>(argument));
	}
}

void FunctionCall::GenerateCode(ostream& output, int indentations) {
	//TODO for sister yuan yang
	/*	Identifier* identifier_;
	std::vector<Expression*> *arguments_;*/
	//special cases to be added
	identifier_->GenerateCode(output, indentations);
	output << "(";
	for(auto iter = arguments_.begin(); iter != arguments_.end(); iter++)
	{
		(*iter)->GenerateCode(output, indentations);
		if(iter != arguments_.end() - 1)
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
	for (auto iter = declarations_.begin(); iter != declarations_.end(); iter++)
	{
		tabs ++; printTabs(output);
		(*iter)->PrintTree(output);
		tabs --;
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
	tabs ++; printTabs(output);
	expression_->PrintTree(output);
	tabs --;
}

void BinaryExpression::PrintTree(ostream& output)
{
	output << "BinaryExpression: " << binary_operator_ << endl;
	tabs ++; printTabs(output);
	left_->PrintTree(output);
	printTabs(output);
	right_->PrintTree(output);
	tabs --;
}

void AssignmentExpression::PrintTree(ostream& output)
{
	output << "AssignmentExpression: " << assignment_operator_ << endl;
	tabs ++; printTabs(output);
	unary_expression_->PrintTree(output);
	printTabs(output);
	assignment_expression_->PrintTree(output);
	tabs --;
}


void StatementsBlock::PrintTree(ostream& output)
{
	output << "StatementsBlock:" << endl;
	for (auto iter = statements_.begin(); iter != statements_.end(); iter++)
	{
		tabs ++; printTabs(output);
		(*iter)->PrintTree(output);
		tabs --;
	}
}

void IfStatement::PrintTree(ostream& output)
{
	output << "IfStatement:" << endl;
	printStr(output, "Condition:");
	tabs ++; printTabs(output);
	condition_->PrintTree(output);
	tabs --;
	if (then_statement_ != nullptr)
	{
		printStr(output, "then:");
		tabs ++; printTabs(output);
		then_statement_->PrintTree(output);
		tabs --;
	}
	if (else_statement_ != nullptr)
	{
		printStr(output, "else:");
		tabs ++; printTabs(output);
		else_statement_->PrintTree(output);
		tabs --;
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
	tabs ++; printTabs(output);
	return_value_->PrintTree(output);
	tabs --;
}

void WhileStatement::PrintTree(ostream& output)
{
	output << "WhileStatement: " << "(has_do: " << has_do_ << ")" << endl;
	printStr(output, "Condition: ");
	tabs ++; printTabs(output);
	condition_->PrintTree(output);
	tabs --;
	printStr(output, "LoopBody: ");
	tabs ++; printTabs(output);
	body_->PrintTree(output);
	tabs --;
}

void ForStatement::PrintTree(std::ostream& output) {
	output << "ForStatement: " << endl;
	printStr(output, "Initializer: ");
	printStr(output, "Operation: ");
	tabs ++; printTabs(output);
	operation_->PrintTree(output);
	tabs --;
	printStr(output, "Condition: ");
	tabs ++; printTabs(output);
	condition_->PrintTree(output);
	tabs --;
	printStr(output, "LoopBody: ");
	tabs ++; printTabs(output);
	body_->PrintTree(output);
	tabs --;
}

void ExpressionStatement::PrintTree(ostream& output)
{
	output << "ExpressionStatement:" << endl;
	if (this->expression_ != nullptr) {
		tabs ++; printTabs(output);
		expression_->PrintTree(output);
		tabs --;
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
	tabs ++; printTabs(output);
	identifier_->PrintTree(output);
	tabs --;
	if (initializer_ != nullptr) {
		tabs ++; printTabs(output);
		initializer_->PrintTree(output);
		tabs --;
	}
}

void FunctionDeclaration::PrintTree(ostream& output)
{
	output << "FunctionDeclaration: " << endl;
	printStr(output, "ReturnType:");
//	printNode(output, &return_type_);
	printStr(output, "FunctionIdentifier:");
	tabs ++; printTabs(output);
	identifier_->PrintTree(output);
	tabs --;
	printStr(output, "FunctionArguments:");
	for (auto iter = arguments_.begin(); iter != arguments_.end(); iter++)
	{
		tabs ++; printTabs(output);
		(*iter)->PrintTree(output);
		tabs --;
	}
	printStr(output, "FunctionStatement:");
	tabs ++; printTabs(output);
	statements_->PrintTree(output);
	tabs --;
}

void FunctionCall::PrintTree(ostream& output)
{
	output << "FunctionCall:" << endl;
	printStr(output, "FunctionIdentifier:");
	tabs ++; printTabs(output);
	identifier_->PrintTree(output);
	tabs --;
	printStr(output, "FunctionArguments:");
	for (auto iter = arguments_.begin(); iter != arguments_.end(); iter ++)
	{
		tabs ++; printTabs(output);
		(*iter)->PrintTree(output);
		tabs --;
	}

}