#include "Generator.h"

std::string Generator::genarate(const std::vector<Token>& tokens)
{
	std::stack<int> loopStack;
	Token last = Token::get;
	int sameCounter = 0;	
	unsigned i = 0;
	std::string output = "#include <stdio.h>\n\nint main() {\n\tchar arr[100] = { 0 };\n\tchar* ptr = arr;\n\n";
	
	for (auto token : tokens) 
	{
		
		if (!loopStack.empty() && sameCounter == 0)
		{
			output += std::string(loopStack.size(), '\t');
		}
		
		switch (token)
		{  
		case Token::inc:
			
			sameCounter++;
			if (i + 1 != tokens.size() && tokens[i + 1] != token && sameCounter != 1) {
				output += "\t*ptr += ";
				output += std::to_string(sameCounter);
				output += "; \n";
				sameCounter = 0;
			}
			else if (i + 1 != tokens.size() && tokens[i + 1] == token) {

			}
			else if (sameCounter == 1) {

				output += "\t++*ptr;\n";
				sameCounter = 0;
			}
				
			break;
		case Token::dec:
			if (last == token || sameCounter == 0)
			{
				sameCounter++;
				if (i + 1 != tokens.size() && tokens[i + 1] != token && sameCounter != 1) {
					output += "\t*ptr -= ";
					output += std::to_string(sameCounter);
					output += "; \n";
					sameCounter = 0;
				}
				else if (i + 1 != tokens.size() && tokens[i + 1] == token) {

				}
				else if (sameCounter == 1) {

					output += "\t--*ptr;\n";
					sameCounter = 0;
				}

			}
			else {
				output += "\t--*ptr;\n";
			}
			
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
		case Token::end:
			output += "\texit();\n";
			break;
		default:
			break;
		}
		last = token;
		i++;
	}
	if (!loopStack.empty()) {
		throw SyntaxError(1);
	}

	output += "\n\treturn 0;\n}\n";
	return output;
}
