#include "HQGame.h"

HQGame::HQGame()
{
}

HQGame::~HQGame()
{
}

/*
Set a random word from the 3of6game word list as the word to be guessed.
*/
void HQGame::fetchNewWord()
{
	std::ifstream wordlist("../3of6game.txt");

	std::vector<std::string> words;

	if (wordlist.is_open())
	{
		std::string line;

		while (std::getline(wordlist, line)) 
		{
			// Remove non-alphabetical characters.
			int i = 0;
			for (char letter : line)
			{
				if (!std::isalpha(letter))
				{
					line.erase(i);
				}
				++i;
			}

			// Add fixed word to words.
			words.push_back(line);
		}
	}

	wordlist.close();

	// Choose a random word.
	std::srand(time(NULL));
	std::random_shuffle(words.begin(), words.end());
	word = words.front();
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

size_t HQGame::getWordLength() const
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

std::set<char> HQGame::getMisses()
{
	return misses;
}

std::set<char> HQGame::getHits()
{
	return hits;
}
