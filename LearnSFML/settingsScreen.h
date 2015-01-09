#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class settingsScreen : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	settingsScreen(void);
	virtual int Run(sf::RenderWindow &App);
};

settingsScreen::settingsScreen(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int settingsScreen::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	int alpha = 0;
	int selectedVideoMode = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	sf::Text Menu4;

	int menu = 0;

	if (!Font.loadFromFile("verdanab.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return(-1);
	}

	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Play");
	Menu1.setPosition({ 280.f, 160.f });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280.f, 220.f });

	Menu3.setFont(Font);
	Menu3.setCharacterSize(20);
	Menu3.setString("Continue");
	Menu3.setPosition({ 280.f, 160.f });

	Menu4.setFont(Font);
	Menu4.setCharacterSize(20);
	sf::String stVideoMode = std::to_string(modes[selectedVideoMode].width) + "x" + std::to_string(modes[selectedVideoMode].height) + " - " + std::to_string(modes[selectedVideoMode].bitsPerPixel) + " bpp";
	Menu4.setString(stVideoMode);
	Menu4.setPosition({ 280.f, 280.f });

	if (playing)
	{
		alpha = alpha_max;
	}

	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}

			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu--;
					if (menu < 0)
						menu = 0;
					break;
				case sf::Keyboard::Down:
					menu++;
					if (menu > 2)
						menu = 2;
					break;
				case sf::Keyboard::Left:
					if (menu == 2)
					{
						selectedVideoMode--;
						if (selectedVideoMode < 0)
							selectedVideoMode = 0;
						sf::String stVideoMode = std::to_string(modes[selectedVideoMode].width) + "x" + std::to_string(modes[selectedVideoMode].height) + " - " + std::to_string(modes[selectedVideoMode].bitsPerPixel) + " bpp";
						Menu4.setString(stVideoMode);
					}
					break;
				case sf::Keyboard::Right:
					if (menu == 2)
					{
						selectedVideoMode++;
						if (selectedVideoMode > modes.size())
							selectedVideoMode = modes.size();
						sf::String stVideoMode = std::to_string(modes[selectedVideoMode].width) + "x" + std::to_string(modes[selectedVideoMode].height) + " - " + std::to_string(modes[selectedVideoMode].bitsPerPixel) + " bpp";
						Menu4.setString(stVideoMode);
					}
					break;
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						playing = true;
						return (1);
					}
					else if (menu == 2)
					{
						App.close();
						App.create(modes[selectedVideoMode], SCREEN_TITLE, sf::Style::Fullscreen);
						return (1);
					}
					else
					{
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}
		
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha < alpha_max)
		{
			alpha++;
		}

//		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));

		if (menu == 0)
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
			Menu4.setColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 2)
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
			Menu4.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
			Menu4.setColor(sf::Color(255, 255, 255, 255));
		}

		App.clear();

	//	App.draw(Sprite);

		if (alpha == alpha_max)
		{
			if (playing)
			{
				App.draw(Menu3);
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
			App.draw(Menu4);
		}
		App.display();
	}

	return(-1);
}