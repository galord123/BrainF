#include "Generator.h";
#include "Tokenizer.h";
#include "FileHandler.h";
#include "Exceptions.h";


int main()
{
	std::string data = FileHandler::load("C:/files/test.bf");
	try 
	{
		std::string output = Generator::genarate(Tokenizer::tokenize(data));
		std::cout << output;
	}
	catch (const SyntaxError e) {
		std::cout << e.what();
	}
	
	return 0;
}
