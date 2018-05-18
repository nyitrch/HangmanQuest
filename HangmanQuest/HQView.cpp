#include "HQView.h"
#include <SFML/Graphics.hpp>

HQView::HQView()
{
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
	sf::Texture menu_overlay_text;
	if (!menu_overlay_text.loadFromFile("/Overlays/menu.png"))
		return -1;
	sf::Sprite menu_overlay;
	menu_overlay.setTexture(menu_overlay_text);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		window.draw(title);
		window.draw(menu_overlay);
		window.display();
	}
}
