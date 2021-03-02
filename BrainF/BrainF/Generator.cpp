#include "Generator.h"

std::string Generator::genarate(const std::vector<Token>& tokens)
{
	std::stack<int> loopStack;
	
	std::string output = "#include <stdio.h>\n\nint main() {\n\tchar arr[100] = { 0 };\n\tchar* ptr = arr;\n\n";
	
	for (auto token : tokens) 
	{
		if (!loopStack.empty())
		{
			output += std::string(loopStack.size(), '\t');
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
			loopStack.push(1);
			output += "\twhile(*ptr) {\n";
			break;
		case Token::loopE:
			if (loopStack.empty()) {
				throw SyntaxError(1);
			}
			loopStack.pop();
			output += "}\n\n";
			break;
		default:
			break;
		}
	}
	if (!loopStack.empty()) {
		throw SyntaxError(1);
	}

	output += "\n\treturn 0;\n}\n";
	return output;
}
