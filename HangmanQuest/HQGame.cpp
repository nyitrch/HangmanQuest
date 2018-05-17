#include "HQGame.h"

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
  0 = IN : Letter is in word.
  1 = NOT_IN : Letter is not in word.
  2 = INVALID : Letter has already been guessed.
*/
int HQGame::guess(char letter)
{
	// Check if the letter has been guessed already.
	if (misses.count(letter) > 0)
	{
		return 2;
	}
	if (hits.count(letter) > 0)
	{
		return 2;
	}

	// Check if the letter is in the word.
	if (letters.count(letter) > 0)
	{
		hits.insert(letter);
		return 0;
	} else {
		misses.insert(letter);
		return 1;
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
