#include <SFML/Graphics.hpp>
#ifndef CSCREEN_HEADER
#define CSCREEN_HEADER

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};

#endif