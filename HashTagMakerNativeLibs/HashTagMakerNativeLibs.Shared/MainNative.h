#pragma once
#include "Sentence.h"
#include "ParseStringHelper.h"

class MainNative{
private:
	std::shared_ptr<Sentence> currentText;
	std::vector<std::shared_ptr<Sentence>> favorits;

public:
	MainNative();
	~MainNative();

	void ParseInputString(const std::wstring &input);
	std::wstring GetHashtags();
	std::wstring GetBaseString();
	void ClearCurrentSentence();
};

