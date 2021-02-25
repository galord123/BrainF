#pragma once
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

class FileHandler
{
public:
	static std::string load(const std::string & path);
};

