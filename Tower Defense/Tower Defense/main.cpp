#include "wrapper.h"
#include "test.h"
#include "UI.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main() {
	wrapper app;
	app.run_app();
	sf::RenderWindow window(sf::VideoMode(1400, 800), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);





	return 0;


}