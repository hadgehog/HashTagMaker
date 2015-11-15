#include "pch.h"
#include "Sentence.h"

#pragma region WORD
Word::Word() {
	this->hash = L"#";
	this->baseWord = L"word";
}

Word::Word(const std::wstring & word) {
	this->hash = L"#";
	this->baseWord = word;
}

Word::~Word() {
}

std::wstring Word::GetBaseWord() {
	return this->baseWord;
}

void Word::SetBaseWord(const std::wstring &word) {
	this->baseWord = word;
}

std::wstring Word::GetHashTag() {
	auto hashTag = this->hash + this->baseWord;
	return hashTag;
}
#pragma endregion

#pragma region SENTENCE
Sentence::Sentence(){
}

Sentence::~Sentence(){
}

void Sentence::AddWord(Word word) {
	this->sentence.push_back(word);
}

void Sentence::AddWord(std::wstring word){
	Word wordObj(word);
	this->sentence.push_back(wordObj);
}

Word Sentence::GetWordAt(int idx) {
	return this->sentence[idx];
}

std::vector<Word> Sentence::GetSentence(){
	return this->sentence;
}

void Sentence::SetSentence(std::vector<std::wstring> words){	
	for (size_t i = 0; i < words.size(); i++){
		Word word(words[i]);
		this->sentence.push_back(word);
	}
}

std::wstring Sentence::GetStringSentenceBase() {
	std::wstring strSentence = L"";

	for (size_t i = 0; i < this->sentence.size(); i++){
		strSentence += this->sentence[i].GetBaseWord() + L" ";
	}

	return strSentence;
}

std::wstring Sentence::GetStringSentenceHashed() {
	std::wstring strSentence = L"";

	for (size_t i = 0; i < this->sentence.size(); i++) {
		strSentence += this->sentence[i].GetHashTag() + L" ";
	}

	return strSentence;
}

void Sentence::Clear() {
	this->sentence.clear();
}
#pragma endregion