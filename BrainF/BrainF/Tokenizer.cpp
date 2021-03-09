#include "Tokenizer.h"

std::vector<Token> Tokenizer::tokenize(const std::string& data)
{
	std::vector<Token> tokens;
	

	for (unsigned i = 0; i < data.size(); i++)
	{
		switch (data[i])
		{
		case '+':
			tokens.push_back(Token::inc);
			break;
		case '-':
			tokens.push_back(Token::dec);
			break;
		case '>':
			tokens.push_back(Token::right);
			break;
		case '<':	
			tokens.push_back(Token::left);
			break;
		case '.':
			tokens.push_back(Token::print);
			break;
		case ',':
			tokens.push_back(Token::get);
			break;
		case '[':
			tokens.push_back(Token::loopS);
			break;
		case ']':
			tokens.push_back(Token::loopE);
			break;
		case '@':
			tokens.push_back(Token::end);
			break;
		case '$':
			tokens.push_back(Token::storageRead);
			break;
		case '!':
			tokens.push_back(Token::storageWrite);
			break;
		case '{':
			tokens.push_back(Token::leftShift);
			break;
		case '}':
			tokens.push_back(Token::rightShift);
			break;
		case '~':
			tokens.push_back(Token::bitNot);
			break;
		case '&':
			tokens.push_back(Token::bitAnd);
			break;
		case '|':
			tokens.push_back(Token::bitOr);
			break;
		case '^':
			tokens.push_back(Token::bitXor);
			break;
		}
	}

	return tokens;
}
