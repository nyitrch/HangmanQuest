#include <SFML/Graphics.hpp>
#include "HQGame.h"
#include "HQView.h"
#include "HQController.h"


int main()
{
	HQGame * hqgame = new HQGame();
	HQView * hqview = new HQView();
	HQController hqcontroller(hqgame);

	hqview->setController(&hqcontroller);

	hqview->renderGame();

	return 0;
}
