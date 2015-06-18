#include "SyntaxNode.h"
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
	sn->printTree(output);
	tabs --;
}

void printStr(ostream& output, string s)
{
	tabs ++; printTabs(output);
	output << s << endl;
	tabs --;
}

void Program::printTree(ostream& output)
{
	output << "Program" << endl;
	vector<Declaration*>::iterator iter;
	for (iter = declarations_.begin(); iter != declarations_.end(); iter++)
	{
		printNode(output, (*iter));
	}
}

void Expression::printTree(ostream& output)
{

}

void Identifier::printTree(ostream& output)
{
	output << "Identifier: " << name_ << endl;
}

void ImmediateInteger::printTree(ostream& output)
{
	output << "ImmediateInteger: " << value_ << endl;
}

void StringLiteral::printTree(ostream& output)
{
	output << "StringLiteral: " << value_ << endl;
}

void UnaryExpression::printTree(ostream& output)
{
	output << "UnaryExpression: " << unary_operator_ << endl;
	printNode(output, expression_);
}

void BinaryExpression::printTree(ostream& output)
{
	output << "BinaryExpression: " << binary_operator << endl;
	printNode(output, left_);
	printNode(output, right_);
}

void AssignmentExpression::printTree(ostream& output)
{
	output << "AssignmentExpression: " << assignment_operator << endl;
	printNode(output, unary_expression_);
	printNode(output, assignment_expression_);
}

void VariableType::printTree(ostream& output)
{
	string t;
	switch (VariableType::type)
	{
		case VOID:
			t = "void";
			break;
		case INT:
			t = "int";
			break;
		case FLOAT:
			t = "float";
			break;
		case CHAR:
			t = "char";
			break;
		default:
			t = "wrong type";
			break;
	}
	output << "VariableType: " << t;
	if (pointer > 0) output << " pointer:" << pointer;
	if (array.size() > 0) output << " array:" << array.size();
	output << endl;

}

void Statement::printTree(ostream& output)
{
	
}

void StatementsBlock::printTree(ostream& output)
{
	output << "StatementsBlock:" << endl;
	vector<Statement*>::iterator iter;
	for (iter = statements_.begin(); iter != statements_.end(); iter++)
	{
		printNode(output, *iter);
	}
}

void IfStatement::printTree(ostream& output)
{
	output << "IfStatement:" << endl;
	printStr(output, "Condition:");
	printNode(output, condition_);
	if (then_statements_ != NULL)
	{
		printStr(output, "then:");
		printNode(output, then_statements_);
	}
	if (else_statements_ != NULL)
	{
		printStr(output, "else:");
		printNode(output, else_statements_);
	}
}

void JumpStatement::printTree(ostream& output)
{
	string s;
	switch(JumpStatement::type)
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

void ReturnStatement::printTree(ostream& output)
{
	output << "ReturnStatement: " << endl;
	printNode(output, return_value_);
}

void WhileStatement::printTree(ostream& output)
{
	output << "WhileStatement: " << "(has_do: " << has_do_ << ")" << endl;
	printStr(output, "Condition: ");
	printNode(output, condition_);
	printStr(output, "LoopBody: ");
	printNode(output, body_);
}

void ExpressionStatement::printTree(ostream& output)
{
	output << "ExpressionStatement:" << endl;
	printNode(output, expression_);
}

void Declaration::printTree(ostream& output)
{
	
}

void VariableDeclaration::printTree(ostream& output)
{
	output << "VariableDeclaration: " << endl;
	printNode(output, &vt);
	printNode(output, identifier);
	if (initializer != NULL) printNode(output, initializer);
}

void FunctionDeclaration::printTree(ostream& output)
{
	output << "FunctionDeclaration: " << endl;
	printStr(output, "ReturnType:");
	printNode(output, &return_type_);
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

void FunctionCall::printTree(ostream& output)
{
	output << "FunctionCall:" << endl;
	printStr(output, "FunctionIdentifier:");
	printNode(output, identifier_);
	printStr(output, "FunctionArguments:");
	vector<Identifier*>::iterator iter;
	for (iter = arguments_->begin(); iter != arguments_->end(); iter ++)
	{
		printNode(output, *iter);
	}

}
