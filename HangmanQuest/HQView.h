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
	sf::Font font;
	sf::Text empty_word;
	sf::Text guessed_word;
	GameState game_state;

public:
	HQView();
	~HQView();

	int initialize();
	void update(std::string);

	char getLetter(sf::Vector2i);
	int renderGame();
};

