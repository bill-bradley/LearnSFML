#include "stdafx.h"
#include "gameScreen.h"

gameScreen::gameScreen(void)
{
	movement_step = 5;
	posx = 320;
	posy = 240;

	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

int gameScreen::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;

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
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return(0);
					break;
				case sf::Keyboard::Up:
					posy -= movement_step;
					break;
				case sf::Keyboard::Down:
					posy += movement_step;
					break;
				case sf::Keyboard::Left:
					posx -= movement_step;
					break;
				case sf::Keyboard::Right:
					posx += movement_step;
					break;
				default:
					break;
				}
			}
		}

		if (posx > 630)
			posx = 630;
		if (posx < 0)
			posx = 0;
		if (posy > 470)
			posy = 470;
		if (posy < 0)
			posy = 0;

		Rectangle.setPosition({ posx, posy });

		App.clear(sf::Color(0, 0, 0, 0));
		App.draw(Rectangle);
		App.display();
	}

	return -1;
}