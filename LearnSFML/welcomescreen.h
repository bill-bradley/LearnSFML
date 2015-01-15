#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class welcomeScreen : public cScreen
{
private:
	sf::String welcomeMessage;
public:
	welcomeScreen(void);
	virtual int Run(sf::RenderWindow &App);
};

