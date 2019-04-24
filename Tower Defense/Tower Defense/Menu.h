#pragma once
#include "UI.h"
#include <SFML/Graphics.hpp>


class Menu : public UI {

public:

	Menu();
	~Menu();

	void open(sf::RenderWindow &window);

private:

	sf::Text text;
	sf::Text text1;
	sf::Font font;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text text5;

};