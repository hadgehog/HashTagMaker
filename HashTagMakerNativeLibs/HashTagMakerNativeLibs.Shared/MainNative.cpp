#include "pch.h"
#include "MainNative.h"

///// static list of delimiters

MainNative::MainNative(){
	this->currentText = std::make_shared<Sentence>();
}

MainNative::~MainNative(){
	this->currentText = nullptr;
}

void MainNative::ParseInputString(const std::wstring &input) {
	if (!input.empty()) {
		auto wordsStr = ParseStringHelper::ParseString(input);
		this->currentText->SetSentence(wordsStr);
	}
}

std::wstring MainNative::GetHashtags() {
	if (!this->currentText->GetSentence().empty()) {
		return this->currentText->GetStringSentenceHashed();
	}

	return L" ";
}

std::wstring MainNative::GetBaseString() {
	if (!this->currentText->GetSentence().empty()) {
		return this->currentText->GetStringSentenceBase();
	}

	return L" ";
}

void MainNative::ClearCurrentSentence() {
	this->currentText->Clear();
}