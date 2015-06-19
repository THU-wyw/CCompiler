#include "Type.h"

using namespace std;

Type* Type::CreateBasicType(BasicType type) {
	return new Type(new BasicType(type));
}

Type* Type::CreateArrayType(Type* type, int length) {
	ArrayType* array_type = new ArrayType();
	array_type->length = length;
	array_type->type = type;
	return new Type(array_type);
}

Type* Type::CreatePointerType(Type* type) {
	PointerType* pointer_type = new PointerType();
	pointer_type->pointer = type;
	return new Type(pointer_type);
}

Type::Type(BasicType* type) {
	this->kind_ = BASIC_TYPE;
	this->basic_type_ = type;
}

Type::Type(ArrayType* type) {
	this->kind_ = ARRAY_TYPE;
	this->array_type_ = type;
}

Type::Type(PointerType* type) {
	this->kind_ = POINTER_TYPE;
	this->pointer_type_ = type;
}

bool Type::Equals(const Type& other) const {
	if (this->kind_ != other.kind_) {
		return false;
	}

	switch (this->kind_) {
	case BASIC_TYPE:
		return this->basic_type_ == other.basic_type_;
		break;
	case ARRAY_TYPE:
		return (this->array_type_->length == other.array_type_->length) &&
			(this->array_type_->type == other.array_type_->type);
		break;
	case POINTER_TYPE:
		return this->pointer_type_->pointer == other.pointer_type_->pointer;
		break;
	//case FUNCTION_TYPE:
	//	if (this->function_type_->return_type != other.function_type_->return_type) {
	//		return false;
	//	}
	//	if (this->function_type_->param_types.size() != other.function_type_->param_types.size()) {
	//		return false;
	//	}
	//	for (int i = 0; i < this->function_type_->param_types.size(); i++) {
	//		if (this->function_type_->param_types[i] != other.function_type_->param_types[i]) {
	//			return false;
	//		}
	//	}
	//	return true;
	//	break;
	default:
		return false;
		break;
	}
}

bool operator==(const Type& typeA, const Type& typeB) {
	return typeA.Equals(typeB);
}

bool operator!=(const Type& typeA, const Type& typeB) {
	return !typeA.Equals(typeB);
}

void Type::SetBasicType(BasicType basic_type) {
	switch (this->kind_)
	{
	case BASIC_TYPE:
		*(this->basic_type_) = basic_type;
		break;
	case ARRAY_TYPE:
		this->array_type_->type->SetBasicType(basic_type);
		break;
	case POINTER_TYPE:
		this->pointer_type_->pointer->SetBasicType(basic_type);
		break;
	default:
		break;
	}
}