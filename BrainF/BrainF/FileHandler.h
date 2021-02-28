#pragma once
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

class FileHandler
{
public:
	static std::string load(const std::string & path);
	static void write(const std::string& path, const std::string& content);
};

