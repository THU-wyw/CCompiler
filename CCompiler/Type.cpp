#include "Type.h"
#include "SyntaxNode.h"
#include "CParserException.h"
using namespace std;

unique_ptr<Type> Type::CreateBasicType(BasicType type /* = UNDEFINED */) {
	unique_ptr<Type> new_type(new Type());
	new_type->kind_ = BASIC_TYPE;
	new_type->basic_type_ = type;
	return new_type;
}

unique_ptr<Type> Type::CreateArrayType(Expression* expression, Type* type) {
	unique_ptr<Type> new_type(new Type());
	new_type->kind_ = ARRAY_TYPE;
	new_type->array_type_.expression = unique_ptr<Expression>(expression);
	new_type->array_type_.type = unique_ptr<Type>(type);
	return new_type;
}

unique_ptr<Type> Type::CreatePointerType(Type* type) {
	unique_ptr<Type> new_type(new Type());
	new_type->kind_ = POINTER_TYPE;
	new_type->pointer_type_.type = unique_ptr<Type>(type);
	return new_type;
}

void Type::SetRootType(BasicType type) {
	switch (this->kind_)
	{
	case BASIC_TYPE:
		this->basic_type_ = type;
		break;
	case ARRAY_TYPE:
		array_type_.type->SetRootType(type);
		break;
	case POINTER_TYPE:
		pointer_type_.type->SetRootType(type);
		break;
	default:
		break;
	}
}

void Type::PrintTypeName(ostream& output) {
	if (this->kind_ == POINTER_TYPE) {
		throw CParserException("Pointer is not supported in JAVA.");
	}
	if (this->kind_ == BASIC_TYPE) {
		switch (this->basic_type_)
		{
		case INTEGER:
			output << "int";
			break;
		case CHARACTER:
			output << "byte";
			break;
		case FLOAT:
			output << "float";
			break;
		case VOID:
			output << "void";
			break;
		default:
			throw CParserException("Unsupported type.");
			break;
		}
		return;
	}
	this->array_type_.type->PrintTypeName(output);
	output << "[]";
}; 

void Type::PrintArrayInitializer(std::ostream& output) {
	if (this->kind_ == POINTER_TYPE) {
		throw CParserException("Pointer is not supported in JAVA.");
	}
	if (this->kind_ == BASIC_TYPE) {
		switch (this->basic_type_)
		{
		case INTEGER:
			output << "int";
			break;
		case CHARACTER:
			output << "byte";
			break;
		case FLOAT:
			output << "float";
			break;
		default:
			throw CParserException("Unsupported type.");
			break;
		}
		return;
	}
	output << "new ";
	this->array_type_.type->PrintArrayInitializer(output);
	output << "[";
	this->array_type_.expression->GenerateCode(output, -1);
	output << "]";
}