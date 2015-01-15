#include "stdafx.h"
#include "welcomescreen.h"

welcomeScreen::welcomeScreen(void)
{
	welcomeMessage = "Junkyard Escape\nPress any key to start!";
}

int welcomeScreen::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;

	sf::Font Font;
	sf::Text textWelcomeMessage;

	if (!Font.loadFromFile("verdanab.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return(-1);
	}

	textWelcomeMessage.setFont(Font);
	textWelcomeMessage.setCharacterSize(20);
	textWelcomeMessage.setString(welcomeMessage);
	textWelcomeMessage.setPosition({ 180.f, 160.f });
	textWelcomeMessage.setColor((sf::Color(255, 0, 255, 255)));



	while (Running)
	{
		while (App.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}

			if (Event.type == sf::Event::KeyPressed)
			{
				return (1);
			}
		}

		App.clear(sf::Color(0, 0, 0, 0));
		App.draw(textWelcomeMessage);
		App.display();
	}

	return -1;
}