#ifndef CPARSER_DRIVER_H
#define CPARSER_DRIVER_H
#include <string>
class Program;

class CParserDriver {
public:
	CParserDriver() {}
	~CParserDriver() {}
	inline void set_program(Program* program) { this->program_ = program; }
	inline Program* get_program(void) { return program_; }
	void ScanBegin();
	void ScanEnd();
	int Parse(const std::string& filename);
private:
	Program* program_;
	std::string filename_;
};
#endif