#include "CParserException.h"
#include <iostream>

CParserException::CParserException(const std::string& content) {
	this->content_ = content;
}

void CParserException::PrintException() {
	std::cerr << content_ << std::endl;
}