#include "HQView.h"
#include <SFML/Graphics.hpp>

HQView::HQView()
{
	game_state = MAIN_MENU;
}


HQView::~HQView()
{
}

/*
Renders the game screen (the current state of the game).
*/
int HQView::displayGame()
{
	// Create window.
	sf::RenderWindow window(sf::VideoMode(600, 800), "HangmanQuest");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	// Create background.
	sf::RectangleShape background(sf::Vector2f(600, 800));
	background.setFillColor(sf::Color(42, 212, 255, 255));

	// Create font.
	sf::Font font;
	if (!font.loadFromFile("../arlrdbd.ttf"))
		return -1;

	// Create title.
	sf::Text title;
	title.setFont(font);
	title.setString("HANGMANQUEST");
	title.setCharacterSize(56);
	title.setFillColor(sf::Color::White);
	float title_width = title.getLocalBounds().width;
	title.setPosition(300 - title_width / 2, 180);

	// Create menu overlay.
	sf::Texture menu_overlay_texture;
	if (!menu_overlay_texture.loadFromFile("../Overlays/menu.png"))
		return -1;
	sf::Sprite menu_overlay;
	menu_overlay.setTexture(menu_overlay_texture);

	// Create enter word overlay.
	sf::Texture enter_word_overlay_texture;
	if (!enter_word_overlay_texture.loadFromFile("../Overlays/enter_word.png"))
		return -1;
	sf::Sprite enter_word_overlay;
	enter_word_overlay.setTexture(enter_word_overlay_texture);

	// Create game overlay.
	sf::Texture game_overlay_texture;
	if (!game_overlay_texture.loadFromFile("../Overlays/game.png"))
		return -1;
	sf::Sprite game_overlay;
	game_overlay.setTexture(game_overlay_texture);

	// Create menu buttons.
	sf::IntRect enter_word_button(149, 551, 301, 105);
	sf::IntRect choose_word_button(130, 421, 340, 105);

	// Create enter word button.
	sf::IntRect confirm_button(189, 591, 221, 52);

	// Create enterable text.
	sf::Text entered_text;
	entered_text.setFont(font);
	entered_text.setCharacterSize(24);
	entered_text.setFillColor(sf::Color::Black);
	entered_text.setPosition(125, 440);
	std::string input;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// Event switch depending on game state.
			switch (game_state)
			{
			case MAIN_MENU:
				// Check button presses.
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);
	
					if (enter_word_button.contains(position)) // user will enter word
						game_state = ENTER_WORD;

					if (choose_word_button.contains(position)) // choose word for user.
						game_state = GAME;
						// tell controller to choose word.
				}
				break;

			case ENTER_WORD:
				// Get entered text.
				/*
				Method used taken from forum post on https://en.sfml-dev.org/forums/index.php?topic=2269.0 on May 18, 2018.
				*/
				if (event.type == sf::Event::TextEntered)
				{
					// Only take alphabetical input, and only 20 characters.
					if (event.text.unicode < 123 && event.text.unicode > 64 && input.size() < 21)
					{
						input += static_cast<char>(event.text.unicode);
						/*
						Convert to uppercase. Taken from https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase on May 18, 2018.
						*/
						std::transform(input.begin(), input.end(), input.begin(), ::toupper);
						entered_text.setString(input);
					}
					// Handle backspace.
					if (event.text.unicode == 8 && input.size() > 0)
					{
						input.pop_back();
						entered_text.setString(input);
					}
				}

				// Check confirm button press.
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);
					if (confirm_button.contains(position)) // confirm entered word.
						game_state = GAME;
						// send word to controller.
				}

				break;
			case GAME:
				break;
			case HELP:
				break;
			}

		}

		window.clear();
		window.draw(background);

		// Render switch depending on game state.
		switch (game_state)
		{
		case MAIN_MENU:
			window.draw(title);
			window.draw(menu_overlay);
			break;
		case ENTER_WORD:
			window.draw(title);
			window.draw(enter_word_overlay);
			window.draw(entered_text);
			break;
		case GAME:
			window.draw(game_overlay);
			break;
		case HELP:
			break;
		}
		window.display();
	}
}
