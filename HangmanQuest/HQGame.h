#pragma once
#include <string>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <time.h>

class HQGame
{
private:

	std::string word; // The word to be guessed in Hangman.
	std::set<char> letters; // A set of all the letters in the word to be guessed.
	std::set<char> misses; // A set of guessed letters that were incorrect.
	std::set<char> hits; // A set of guessed letters that were correct.

public:
	HQGame();
	~HQGame();

	void fetchNewWord(); // Fetches new word from 3of6game database.
	int guess(char); // Guess that a letter is in a word.

	size_t getWordLength() const; // Return number of letters in the word.
	std::string getWord() const; // Return word.
	void setWord(std::string); // Initializes gamestate with a word from the user.

	std::set<char> getMisses(); // Returns misses.
	std::set<char> getHits(); // Returns hits.
};

