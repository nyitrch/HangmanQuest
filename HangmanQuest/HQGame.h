#pragma once
#include <set>
#include <string>
#include <vector>

class HQGame
{
private:

	std::string word; // The word to be guessed in Hangman.
	std::set<char> letters; // A set of all the letters in the word to be guessed.
	std::set<char> misses; // A set of guessed letters that were incorrect.
	std::set<char> hits; // A set of guessed letters that were correct.

	std::vector<std::string> wordlist; // List of words from which a single word for the Hangman game is chosen.
	std::string wordlist_filename = "../wordlists/3of6game.txt"; // Filename of wordlist.txt file.

public:
	HQGame();
	~HQGame();

	void getRandomWord(); // Fetches new word from word database.
	void guess(char); // Guess that a letter is in a word.

	size_t getWordLength() const; // Return number of letters in the word.
	size_t getNumUnique() const; // Return number of unique letters in the word.
	std::string getWord() const; // Return word.
	void setWord(std::string); // Initializes gamestate with a word from the user.

	std::set<char> getMisses(); // Returns misses.
	std::set<char> getHits(); // Returns hits.

	void loadWordlist(); // Load the wordlist from the set filename.

	std::string getWordlistFile(); // Returns the filename of the wordlist.
	void setWordlistFile(std::string filename); // Set the filename of the wordlist.
};

