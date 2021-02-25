#include "FileHandler.h"

std::string FileHandler::load(const std::string& path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	
	return buffer.str();
}
