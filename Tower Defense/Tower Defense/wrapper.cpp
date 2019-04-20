#include "wrapper.h"
#include <SFML/Graphics.hpp>



wrapper::wrapper() {
	//starting amount of money       1000?
	this->Currency = 1000;




}
wrapper::~wrapper() {

}


void wrapper::run_app() {


	sf::RenderWindow window(sf::VideoMode(800, 800), "Tower Defense");


	sf::CircleShape shape(200.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

//getters
int wrapper::get_currency() {
	return this->Currency;
}
int wrapper::get_numoftowers() {
	return this->Numberoftowers;

}


//setters
void wrapper::set_currency(int var) {
	this->Currency = var;
}
void wrapper::set_Numberoftowers(int var) {
	this->Numberoftowers = var;
}