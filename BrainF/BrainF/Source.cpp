#include "Generator.h";
#include "Tokenizer.h";
#include "FileHandler.h";
#include "Exceptions.h";


int main(int argc, char** argv)
{
	std::string data;
	if (argc == 1) {
		std::string name = "";
		std::cout << "enter file path:" << std::endl;
		std::cin >> name;
		data = FileHandler::load(name);
	}
	else {
		data = FileHandler::load(argv[1]);
	}
	
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
