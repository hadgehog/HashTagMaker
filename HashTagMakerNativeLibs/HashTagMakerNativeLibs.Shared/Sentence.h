#pragma once

class Word {
private:
	std::wstring hash;
	std::wstring baseWord;

public:
	Word();
	Word(const std::wstring &word);
	~Word();

	std::wstring GetBaseWord();
	void SetBaseWord(const std::wstring &word);

	std::wstring GetHashTag();
};

class Sentence{
private:
	std::vector<Word> sentence;

public:
	Sentence();
	~Sentence();

	void AddWord(Word word);
	void AddWord(std::wstring word);
	Word GetWordAt(int idx);

	std::vector<Word> GetSentence();
	void SetSentence(std::vector<std::wstring> words);

	std::wstring GetStringSentenceBase();
	std::wstring GetStringSentenceHashed();

	void Clear();
};

