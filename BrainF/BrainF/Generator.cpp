#include "Generator.h"

std::string Generator::genarate(const std::vector<Token>& tokens)
{
	int loops = 0;
	std::string output = "#include <stdio.h>\n\nint main() {\n\tchar arr[100] = { 0 };\n\tchar* ptr = arr;\n\n";
	for (auto token : tokens) 
	{
		if (loops > 0)
		{
			output += std::string(loops, '\t');
		}

		switch (token)
		{  
		case Token::inc:
			
			output += "\t++*ptr;\n";
			break;
		case Token::dec:
			output += "\t--*ptr;\n";
			break;
		case Token::left:
			output += "\t--ptr;\n";
			break;
		case Token::right:
			output += "\t++ptr;\n";
			break;
		case Token::print:
			output += "\tputchar(*ptr);\n";
			break;
		case Token::get:
			output += "\t*ptr = getchar();\n";
			break;
		case Token::loopS:
			loops++;
			output += "\twhile(*ptr) {\n";
			break;
		case Token::loopE:
			loops--;
			output += "}\n\n";
			break;
		default:
			break;
		}
	}

	if (loops != 0) {
		throw SyntaxError(1);
	}

	output += "\n\treturn 0;\n}\n";
	return output;
}
