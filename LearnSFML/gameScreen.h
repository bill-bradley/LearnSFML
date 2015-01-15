#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class gameScreen : public cScreen
{
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	gameScreen(void);
	virtual int Run(sf::RenderWindow &App);
};

