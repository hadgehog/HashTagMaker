#include "pch.h"
#include "ParseStringHelper.h"

#include <stdio.h>
#include <string.h>

std::wstring ParseStringHelper::delimiters = L" ,.;:\n\r\t";

ParseStringHelper::ParseStringHelper() {
}

ParseStringHelper::~ParseStringHelper() {
}

std::vector<std::wstring> ParseStringHelper::ParseString(const std::wstring & inputText) {
	std::wstring inputStringCopy = inputText;
	std::vector<std::wstring> parsedString;

	int pos = inputStringCopy.find_first_of(delimiters);

	// since inputText always no empty, if pos = -1 it's one word
	if (pos == std::string::npos) {
		parsedString.push_back(inputStringCopy);
	}

	while (pos != std::string::npos) {
		std::wstring tmpWstr = inputStringCopy.substr(0, pos);

		if (tmpWstr[0] == '#') {
			tmpWstr.erase(0, 1);
		}

		parsedString.push_back(tmpWstr);

		inputStringCopy.erase(0, pos + 1);
		pos = inputStringCopy.find_first_of(delimiters);
	}

	if (!inputStringCopy.empty()) {
		parsedString.push_back(inputStringCopy);
	}

	return parsedString;
}

std::vector<std::wstring> ParseStringHelper::HashingText(std::vector<std::wstring> baseString) {
	std::vector<std::wstring> hasheddString;

	for (size_t i = 0; i < baseString.size(); i++) {
		auto hashedWord = L"#" + baseString[i];
		hasheddString.push_back(hashedWord);
	}

	return hasheddString;
}
