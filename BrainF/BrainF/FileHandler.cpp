#include "FileHandler.h"

std::string FileHandler::load(const std::string& path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	
	return buffer.str();
}

void FileHandler::write(const std::string& path, const std::string& content)
{
	std::ofstream myfile;
	myfile.open(path);
	myfile << content;
	myfile.close();
}
