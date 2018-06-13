#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class HQController;

class HQView
{
private:
	HQController * controller; // Communicates between game model.

	enum ViewState // States used to help with detecting button presses, and what should be displayed.
	{
		MAIN_MENU,
		ENTER_WORD,
		GAME,
		HELP,
		WIN,
		LOSE
	};

	std::vector<sf::IntRect> alpha_buttons; // Vector of buttons (locations) for the keyboard.
	sf::Font font; // Standard font for the game.
	sf::Text guessed_word; // Text object that represents the word to guess.
	std::vector<sf::Text> missed_letters; // X marks that appear on wrong guesses.
	ViewState view_state; // Current game state.

public:
	HQView();
	~HQView();

	void setController(HQController * controller);

	int initialize(); // Initialize the view.
	int update(); // Update the view from the model.

	void drawMisses(sf::RenderWindow * window); // Draw the X marks that appear on wrong guesses and the hangman.

	char getLetter(sf::Vector2i); // From a position, get which letter was pressed on the keyboard if any.
	int renderGame(); // Render the game and handle button presses/clicks.


};

