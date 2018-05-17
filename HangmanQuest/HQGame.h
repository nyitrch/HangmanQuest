#pragma once
#include <string>
#include <set>

class HQGame
{
private:

	std::string word; // The word to be guessed in Hangman.
	std::set<char> letters; // A set of all the letters in the word.
	std::set<char> misses; // A set of guessed letters that were incorrect.
	std::set<char> hits; // A set of guessed letters that were correct.

public:
	HQGame();
	~HQGame();

	void fetchNewWord(); // Fetches new word from 3of6game database.
	int guess(char letter); // Guess that a letter is in a word.

	int getWordLength() const; // Return number of letters in the word.
	std::string getWord() const; // Return word.
	void setWord(std::string new_word); // Initializes gamestate with a word from the user.
};

