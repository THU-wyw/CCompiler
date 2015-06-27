#include "CParserDriver.h"
#include "CParser.hpp"

int CParserDriver::Parse(const std::string& filename) {
	filename_ = filename;
	ScanBegin();
	yy::CParser parser(*this);
	int result = parser.parse();
	ScanEnd();
	return result;
}

