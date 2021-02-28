#pragma once
#include <exception>
#include <iostream>

class SyntaxError : std::exception
{

public:
	SyntaxError (int type) {
		_type = type;
	}

	const char* what() const throw()
	{
		switch (_type)
		{
		case 0:
			return "SyntaxError: out of range!";
			break;
		case 1:
			return "SyntaxError: missing ]";
			break;
		default:
			break;
		}
		
	}

private:
	int _type;
};