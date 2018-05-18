#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class HQView
{
private:

	enum GameState
	{
		MAIN_MENU,
		ENTER_WORD,
		GAME,
		HELP
	};

	std::vector<sf::IntRect> alpha_buttons;
	GameState game_state;

public:
	HQView();
	~HQView();

	void update();

	char getLetter(sf::Vector2i);
	int displayGame();
};

