#include "HQGame.h"

enum LetterFlags
{
	IN = 1,
	NOT_IN = 2,
	INVALID = 3
};

HQGame::HQGame()
{
}

HQGame::~HQGame()
{
}

void HQGame::fetchNewWord()
{
}

/*
Guesses if a letter is in the word.

Returns:
  IN : Letter is in word.
  NOT_IN : Letter is not in word.
  INVALID : Letter has already been guessed.
*/
bool HQGame::guess(char letter)
{
	// Check if the letter has been guessed already.
	if (misses.count(letter) > 0)
	{
		return INVALID;
	}
	if (hits.count(letter) > 0)
	{
		return INVALID;
	}

	// Check if the letter is in the word.
	if (letters.count(letter) > 0)
	{
		hits.insert(letter);
		return IN;
	} else {
		misses.insert(letter);
		return NOT_IN;
	}
}

int HQGame::getWordLength() const
{
	return word.size();
}

std::string HQGame::getWord() const
{
	return word;
}

/*
Initializes the gamestate with a word given by the user.
*/
void HQGame::setWord(std::string new_word)
{
	word = new_word;

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
