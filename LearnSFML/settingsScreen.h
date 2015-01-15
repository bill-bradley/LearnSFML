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

