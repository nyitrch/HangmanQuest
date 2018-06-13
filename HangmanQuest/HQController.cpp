#include "HQController.h"
#include "HQGame.h"
#include "HQView.h"


HQController::HQController(HQGame * model, HQView * view) : model(model), view(view)
{
}

HQController::~HQController()
{
}

std::string HQController::getWord()
{
	return model->getWord();
}

size_t HQController::getWordLength()
{
	return model->getWordLength();
}

size_t HQController::getNumUnique()
{
	return model->getNumUnique();
}

std::set<char> HQController::getHits()
{
	return model->getHits();
}

std::set<char> HQController::getMisses()
{
	return model->getMisses();
}

int HQController::getGameState()
{
	return model->getGameState();
}

void HQController::guess(char letter)
{
	// Send guess to model.
	model->guess(letter);
	view->update();
}

void HQController::chooseForMe()
{
	// Have model choose a word.
	model->getRandomWord();
	view->update();
}

void HQController::setWord(std::string word)
{
	// Set word to model.
	model->setWord(word);
	view->update();
}
