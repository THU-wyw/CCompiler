#ifndef TYPE_H
#define TYPE_H
#include <vector>
class Expression;
class Type {
public:
	typedef enum {
		BASIC_TYPE,
		ARRAY_TYPE,
		POINTER_TYPE,
		//FUNCTION_TYPE
	} Kind;

	typedef enum {
		INTEGER,
		CHARACTER,
		FLOAT,
		VOID,
		UNDEFINED
	} BasicType;

	typedef struct ArrayType {
		Expression* length;
		Type* type;
	} ArrayType;

	typedef struct PointerType {
		Type* pointer;
	} PointerType;

public:
	bool Equals(const Type& other) const;
	friend bool operator==(const Type& typeA, const Type& typeB);
	friend bool operator!=(const Type& typeA, const Type& typeB);
	inline Kind get_kind() const { return this->kind_; };
	inline const BasicType* get_basic_type() const { return this->kind_ == BASIC_TYPE ? this->basic_type_ : NULL; }
	inline const ArrayType* get_array_type() const { return this->kind_ == ARRAY_TYPE ? this->array_type_ : NULL; }
	inline const PointerType* get_pointer_type() const { return this->kind_ == POINTER_TYPE ? this->pointer_type_ : NULL; }
	void set_basic_type(BasicType basic_type);
	static Type* CreateBasicType(BasicType type = UNDEFINED);
	static Type* CreateArrayType(Type* type, Expression* length);
	static Type* CreatePointerType(Type* type);

private:
	Kind kind_;

	union {
		BasicType* basic_type_;
		ArrayType* array_type_;
		PointerType* pointer_type_;
	};
	Type(BasicType* type);
	Type(ArrayType* type);
	Type(PointerType* type);
};
#endif