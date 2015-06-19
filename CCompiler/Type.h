#ifndef TYPE_H
#define TYPE_H
#include <vector>

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
		VOID
	} BasicType;

	typedef struct ArrayType {
		int length;
		Type* type;
	} ArrayType;

	typedef struct PointerType {
		Type* pointer;
	} PointerType;

public:
	bool Equals(const Type& other) const;
	friend bool operator==(const Type& typeA, const Type& typeB);
	friend bool operator!=(const Type& typeA, const Type& typeB);
	void SetBasicType(BasicType basic_type);
	static Type* CreateBasicType(BasicType type);
	static Type* CreateArrayType(Type* type, int length);
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