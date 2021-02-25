#include "Generator.h";
#include "Tokenizer.h";
#include "FileHandler.h";


int main()
{
	std::string data = FileHandler::load("C:/files/test.bf");
	std::string output = Generator::genarate(Tokenizer::tokenize(data));
	std::cout << output;
	return 0;
}
