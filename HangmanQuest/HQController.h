#pragma once
#include <string>
#include <set>

class HQGame;
class HQView;

class HQController
{
private:
	HQGame * model;
	HQView * view;
public:
	HQController(HQGame * model, HQView * view);
	~HQController();

	// Model -> View methods.
	std::string getWord();
	size_t getWordLength();
	std::set<char> getHits();
	std::set<char> getMisses();

	// View -> Model methods
	void newGame();
	void guess(char);
	void chooseForMe();
	void setWord(std::string);
};

