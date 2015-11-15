#pragma once
#include "Sentence.h"

class ParseStringHelper{
private:
	static std::wstring delimiters;

public:
	ParseStringHelper();
	~ParseStringHelper();

	static std::vector<std::wstring> ParseString(const std::wstring &inputText);
	static std::vector<std::wstring> HashingText(std::vector<std::wstring> baseString);
};

