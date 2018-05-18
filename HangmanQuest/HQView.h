#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class HQController;

class HQView
{
private:
	HQController * controller;

	enum GameState
	{
		MAIN_MENU,
		ENTER_WORD,
		GAME,
		HELP,
		WIN,
		LOSE
	};

	std::vector<sf::IntRect> alpha_buttons;
	sf::Font font;
	sf::Text debug_word;
	sf::Text guessed_word;
	std::vector<sf::Text> missed_letters;
	GameState game_state;

public:
	HQView();
	~HQView();

	void setController(HQController * controller);

	int initialize();
	int update();

	void drawMisses(sf::RenderWindow * window);

	char getLetter(sf::Vector2i);
	int renderGame();


};

