#include "Generator.h"

std::string Generator::genarate(const std::vector<Token>& tokens)
{
	std::stack<int> loopStack;
	Token last = Token::get;
	int sameCounter = 0;	
	unsigned i = 0;
	std::string output = "#include <stdio.h>\n#include <stdlib.h>\n#include <inttypes.h>\n\nchar* getString(uint8_t* data) {\n\tint size = (*data);\n\tchar* str = (char*)calloc(size + 1, sizeof(uint8_t));\n\n\tfor (int i = 0; i < size; i++) {\n\t\tstr[i] = *(data + i + 1);\n\t}\n\n\treturn str;\n}\n\nint main() {\n\tuint8_t arr[100] = { 0 };\n\tuint8_t* ptr = arr;\n\tuint8_t storage = '\\0';\n\tFILE *fptr = NULL;\n\n";
	
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
			output += "\texit(0);\n";
			break;

		case Token::storageRead:
			output += "\tstorage = *ptr;\n";
			break;

		case Token::storageWrite:
			output += "\t*ptr = storage;\n";
			break;

		case Token::leftShift:
			output += "\t*ptr = *ptr << 1;\n";
			break;

		case Token::rightShift:
			output += "\t*ptr = *ptr >> 1;\n";
			break;

		case Token::bitAnd:
			output += "\t*ptr = (*ptr) & storage;\n";
			break;

		case Token::bitNot:
			output += "\t*ptr = ~(*ptr);\n";
			break;

		case Token::bitOr:
			output += "\t*ptr = (*ptr) | storage;\n";
			break;

		case Token::bitXor:
			output += "\t*ptr = (*ptr) ^ storage;\n";
			break;

		case Token::fileOpenClose:
			output += "\tif (fptr == NULL) {\n\t\tfptr = fopen(getString(ptr),\"a+\");\n\t\tfseek(fptr, 0, SEEK_SET); \n\t}\n\telse {\n\tfclose(fptr);\n\t}\n";
			break;

		case Token::fileRead:
			output += "\tfwrite(ptr, sizeof(uint8_t), 1, fptr);\n";
			break;

		case Token::fileWrite:
			output += "\tfread(ptr, sizeof(uint8_t), 1, fptr);\n";
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
