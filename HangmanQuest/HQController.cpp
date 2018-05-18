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
	view->update();
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
	model->fetchNewWord();
	view->update();
}

void HQController::setWord(std::string word)
{
	// Set word to model.
	model->setWord(word);
	view->update();
}