#ifndef CPARSER_DRIVER_H
#define CPARSER_DRIVER_H
#include <string>
#include <memory>
class Program;

class CParserDriver {
public:
	CParserDriver() {}
	~CParserDriver() {}
	inline void set_program(Program* program) { this->program_ = std::unique_ptr<Program>(program); }
	void GenerateCode(const std::string& filename);
	void ScanBegin();
	void ScanEnd();
	int Parse(const std::string& filename);
private:
	std::unique_ptr<Program> program_;
	std::string filename_;
};
#endif