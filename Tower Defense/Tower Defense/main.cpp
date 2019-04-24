#include "wrapper.h"
#include "test.h"
#include "UI.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <iostream>

int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 950), "Tower Defense Rules", sf::Style::Close);
	
	Menu menu;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear();
		menu.open(window);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

			window.close();

		}

	}


	wrapper app;
	app.run_app();

	//bonus network impletmentation - not
	std::cout << system("curl -i -H \"Accept: application/json\" -H \"Content-Type: application/json\" -X GET https://raw.githubusercontent.com/basjqnatsks/TowerDefense/master/Tower%20Defense/Menu.txt");

	return 0;


}