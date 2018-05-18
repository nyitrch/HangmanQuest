#include "HQController.h"
#include "HQGame.h"



HQController::HQController(HQGame * model) : model(model)
{
}

HQController::~HQController()
{
}

std::string HQController::getWord()
{
	return model->getWord();
}

std::set<char> HQController::getHits()
{
	return model->getHits();
}

std::set<char> HQController::getMisses()
{
	return model->getMisses();
}


void HQController::newGame()
{
	// Clear model.
	model->setWord("");
}

void HQController::guess(char letter)
{
	// Send guess to model.
	model->guess(letter);
}

void HQController::chooseForMe()
{
	// Have model choose a word.
	model->fetchNewWord();
}

void HQController::setWord(std::string word)
{
	// Set word to model.
	model->setWord(word);
}
