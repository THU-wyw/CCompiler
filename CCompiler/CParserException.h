#ifndef CPARSER_EXCEPTION_H
#define CPARSER_EXCEPTION_H
#include <exception>
#include <string>

class CParserException : public std::exception{
public:
	explicit CParserException(const std::string& content);
	void PrintException();
private:
	std::string content_;
};
#endif