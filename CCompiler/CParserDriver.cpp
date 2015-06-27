#include "CParserDriver.h"
#include <fstream>
#include "CParser.hpp"
using namespace std;
int CParserDriver::Parse(const std::string& filename) {
	filename_ = filename;
	ScanBegin();
	yy::CParser parser(*this);
	int result = parser.parse();
	ScanEnd();
	return result;
}

void CParserDriver::GenerateCode(const std::string& filename) {
	ofstream output(filename);
	program_->GenerateCode(output, 0);
}