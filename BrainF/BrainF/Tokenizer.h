#pragma once
#include <vector>
#include <iostream>

enum class Token {
	inc, // +
	dec, // -
	right, // >
	left, // <
	print, // .
	get, // ,
	loopS, // [
	loopE, // ]
	end, // @
	storageRead, // $
	storageWrite, // !
	leftShift, // {
	rightShift, // }
	bitNot, // ~
	bitXor, // ^
	bitAnd, // &
	bitOr // |
};

class Tokenizer
{
public:
	static std::vector<Token> tokenize(const std::string & data);
private:
	
};
