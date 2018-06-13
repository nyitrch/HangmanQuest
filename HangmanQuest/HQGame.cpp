#include "HQGame.h"
#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <time.h>



HQGame::HQGame()
{
}

HQGame::~HQGame()
{
}

/*
Load the wordlist into a vector from the file located at wordlist_filename.
*/
void HQGame::loadWordlist()
{
	// Empty the old wordlist.
	wordlist.clear();

	std::ifstream istream(wordlist_filename);

	if (istream.is_open())
	{
		std::string line;

		while (std::getline(istream, line))
		{
			// Remove non-alphabetical characters.
			int i = 0; // index of current character in line.
			for (char letter : line)
			{
				if (!std::isalpha(letter)) { line.erase(i); }
			}
			++i;

			/*
			Convert to lowercase. Taken from https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase on May 18, 2018.
			*/
			std::transform(line.begin(), line.end(), line.begin(), ::tolower);

			// Add lowercase, alphabetical only word to wordlist.
			wordlist.push_back(line);
		}		
	}

	istream.close();
}

/*
Set a random word from the 3of6game word list as the word to be guessed.
*/
void HQGame::getRandomWord()
{
	if (wordlist.empty())
	{
		loadWordlist();
	}

	// Choose a random word.
	std::srand(static_cast<unsigned int>(time(NULL)));
	std::random_shuffle(wordlist.begin(), wordlist.end());
	setWord(wordlist.front());
}

/*
Guesses if a letter is in the word and adjusts hits and misses accordingly.
*/
void HQGame::guess(char letter)
{
	// Ensure guess is in lowercase.
	letter = tolower(letter);

	// Reject non-alphabetical characters.
	if (!std::isalpha(letter))
	{
		return; // Not valid guess.
		// TODO: should error or do something more substantial here, but functionally its fine
		// to do nothing when the guess is not valid as it is also not a correct guess.
	}

	// Check if the letter has been guessed already.
	if (misses.count(letter) > 0 || hits.count(letter) > 0)
	{
		return; // Letter has already been guessed.
	}

	// Check if the letter is in the word.
	if (letters.count(letter) > 0)
	{
		hits.insert(letter); // Correct guess.
		return;
	} else {
		misses.insert(letter); // Incorrect guess.
		return;
	}
}

size_t HQGame::getWordLength() const
{
	return word.size();
}

size_t HQGame::getNumUnique() const
{
	return letters.size();
}

std::string HQGame::getWord() const
{
	return word;
}

/*
Initializes the gamestate with a word.
*/
void HQGame::setWord(std::string new_word)
{
	word = new_word;

	/*
	Convert to lowercase. Taken from https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase on May 18, 2018.
	*/
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);

	// Reset letters, misses, and hits.
	letters.clear();
	misses.clear();
	hits.clear();

	// Initialize letters.
	for (char letter : word)
	{
		letters.insert(letter);
	}
}

std::set<char> HQGame::getMisses()
{
	return misses;
}

std::set<char> HQGame::getHits()
{
	return hits;
}

std::string HQGame::getWordlistFile()
{
	return wordlist_filename;
}

void HQGame::setWordlistFile(std::string filename)
{
	wordlist_filename = filename;
}


