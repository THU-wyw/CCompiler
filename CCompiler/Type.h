#ifndef TYPE_H
#define TYPE_H
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>
class Expression;
class CParserException;

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

	typedef struct {
		std::unique_ptr<Expression> expression;
		std::unique_ptr<Type> type;
	} ArrayType;
	typedef struct {
		std::unique_ptr<Type> type;
	} PointerType;

public:
	static std::unique_ptr<Type> CreateBasicType(BasicType type = UNDEFINED);
	static std::unique_ptr<Type> CreateArrayType(Expression* expression, Type* type);
	static std::unique_ptr<Type> CreatePointerType(Type* type);
	void SetRootType(BasicType type);
	inline Kind get_kind() { return kind_; }
	void PrintTypeName(std::ostream& output);
private:
	Kind kind_;
	BasicType basic_type_;
	ArrayType array_type_;
	PointerType pointer_type_;
};
#endif