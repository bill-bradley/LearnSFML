#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Screens.h"

int main()
{
	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 2;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), SCREEN_TITLE);

	App.setMouseCursorVisible(false);

	//Screens preparations
	settingsScreen ss;
	Screens.push_back(&ss);
	gameScreen gs;
	Screens.push_back(&gs);
	welcomeScreen ws;
	Screens.push_back(&ws);

	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}