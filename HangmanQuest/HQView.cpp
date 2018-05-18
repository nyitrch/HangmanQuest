#include "HQView.h"

HQView::HQView()
{
	game_state = MAIN_MENU;
	// Create alphabet buttons.
	sf::IntRect a_button(35, 582, 43, 49);
	sf::IntRect b_button(91, 582, 43, 49);
	sf::IntRect c_button(149, 582, 43, 49);
	sf::IntRect d_button(207, 582, 43, 49);
	sf::IntRect e_button(263, 582, 43, 49);
	sf::IntRect f_button(315, 582, 43, 49);
	sf::IntRect g_button(371, 582, 43, 49);
	sf::IntRect h_button(431, 582, 43, 49);
	sf::IntRect i_button(477, 582, 43, 49);
	sf::IntRect j_button(523, 582, 43, 49);
	sf::IntRect k_button(47, 656, 43, 49);
	sf::IntRect l_button(103, 656, 43, 49);
	sf::IntRect m_button(158, 656, 43, 49);
	sf::IntRect n_button(220, 656, 43, 49);
	sf::IntRect o_button(280, 656, 43, 49);
	sf::IntRect p_button(338, 656, 43, 49);
	sf::IntRect q_button(396, 656, 43, 49);
	sf::IntRect r_button(454, 656, 43, 49);
	sf::IntRect s_button(509, 656, 43, 49);
	sf::IntRect t_button(110, 729, 43, 49);
	sf::IntRect u_button(164, 729, 43, 49);
	sf::IntRect v_button(222, 729, 43, 49);
	sf::IntRect w_button(278, 729, 55, 49);
	sf::IntRect x_button(344, 729, 43, 49);
	sf::IntRect y_button(394, 729, 43, 49);
	sf::IntRect z_button(447, 729, 43, 49);
	alpha_buttons.push_back(a_button);
	alpha_buttons.push_back(b_button);
	alpha_buttons.push_back(c_button);
	alpha_buttons.push_back(d_button);
	alpha_buttons.push_back(e_button);
	alpha_buttons.push_back(f_button);
	alpha_buttons.push_back(g_button);
	alpha_buttons.push_back(h_button);
	alpha_buttons.push_back(i_button);
	alpha_buttons.push_back(j_button);
	alpha_buttons.push_back(k_button);
	alpha_buttons.push_back(l_button);
	alpha_buttons.push_back(m_button);
	alpha_buttons.push_back(n_button);
	alpha_buttons.push_back(o_button);
	alpha_buttons.push_back(p_button);
	alpha_buttons.push_back(q_button);
	alpha_buttons.push_back(r_button);
	alpha_buttons.push_back(s_button);
	alpha_buttons.push_back(t_button);
	alpha_buttons.push_back(u_button);
	alpha_buttons.push_back(v_button);
	alpha_buttons.push_back(w_button);
	alpha_buttons.push_back(x_button);
	alpha_buttons.push_back(y_button);
	alpha_buttons.push_back(z_button);
}


HQView::~HQView()
{
}

char HQView::getLetter(sf::Vector2i position)
{
	for (size_t i = 0; i < alpha_buttons.size(); ++i)
	{
		if (alpha_buttons[i].contains(position))
			return static_cast<char>(i + 65);
	}
	return ' ';
}

/*
Renders the game screen (the current state of the game).
*/
int HQView::displayGame()
{
	// Create window.
	sf::RenderWindow window(sf::VideoMode(600, 800), "HangmanQuest", sf::Style::Close);
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

	// Create empty word to guess.
	sf::Text empty_word;
	empty_word.setFont(font);
	empty_word.setCharacterSize(56);
	empty_word.setFillColor(sf::Color::White);
	float empty_word_width = empty_word.getLocalBounds().width;
	empty_word.setPosition(300 - empty_word_width / 2, 180);

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

	// Create help overlay.
	sf::Texture help_overlay_texture;
	if (!help_overlay_texture.loadFromFile("../Overlays/help.png"))
		return -1;
	sf::Sprite help_overlay;
	help_overlay.setTexture(help_overlay_texture);

	// Create menu buttons.
	sf::IntRect enter_word_button(149, 551, 301, 105);
	sf::IntRect choose_word_button(130, 421, 340, 105);

	// Other game buttons.
	sf::IntRect back_button(29, 725, 55, 56);
	sf::IntRect help_button(518, 725, 56, 56);

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
				// Get if a button was pressed.
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);

					if (back_button.contains(position)) // return to menu.
					{
						game_state = MAIN_MENU;
						break;
					}
					if (help_button.contains(position))
					{
						game_state = HELP;
						break;
					}

					char guess = getLetter(position);
					// If there was a guess, send guess to controller.
					if (guess != ' ')
					{

					}

				}
				break;
			case HELP:
				// Check if back button was pressed.
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);
					if (back_button.contains(position))
						game_state = GAME;
				}
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
			window.draw(game_overlay);
			window.draw(help_overlay);
			break;
		}
		window.display();
	}
}
