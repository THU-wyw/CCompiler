#include "CParserDriver.h"
#include <fstream>
#include "CParser.hpp"
#include "CParserException.h"
using namespace std;
int CParserDriver::Parse(const std::string& filename) {
	filename_ = filename;
	ScanBegin();
	yy::CParser parser(*this);
	int result;
	result = parser.parse();
	ScanEnd();
	return result;
}

void CParserDriver::GenerateCode(const std::string& filename) {
	ofstream output(filename);
	std::string class_name = filename.substr(filename.find_last_of('/') + 1, filename.find_last_of('.') - filename.find_last_of('/') - 1);
	program_->set_main_class_name_(class_name);
	try {
		program_->GenerateCode(output, 0);
		std::cout << "Generate " << class_name << ".java successfully!" << std::endl;
	} catch (CParserException& exception) {
		exception.PrintException();
	}
}