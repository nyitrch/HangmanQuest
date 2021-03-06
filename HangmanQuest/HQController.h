#pragma once
#include <string>
#include <set>
#include "GameState.h"

class HQGame;
class HQView;

class HQController
{
private:
	HQGame * model; // The game model.
	HQView * view; // The SFML view. What the user sees/interacts with.
public:
	HQController(HQGame * model, HQView * view);
	~HQController();

	// Model -> View methods.
	std::string getWord(); // Get word from model.
	size_t getWordLength(); // Get word length from model.
	size_t getNumUnique(); // Get number of unique letters in word from model.
	std::set<char> getHits(); // Get # of hits from model.
	std::set<char> getMisses(); // Get # of misses from model.
	GameState getGameState(); // Get the current game state from the model.

	// View -> Model methods
	void guess(char); // Guess with a char from the view.
	void chooseForMe(); // Command from the view to choose a random word.
	void setWord(std::string); // Command from the view to set a specific word.
};

