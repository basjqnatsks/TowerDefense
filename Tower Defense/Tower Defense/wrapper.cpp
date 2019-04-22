#include "wrapper.h"
#include <SFML/Graphics.hpp>



wrapper::wrapper() {
	//starting amount of money       1000?
	this->Currency = 1000;




}
wrapper::~wrapper() {

}


void wrapper::run_app() {


	sf::RenderWindow window(sf::VideoMode(1400, 950), "Tower Defense");


	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(250, 50));
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(0);
	rectangle.setPosition(0, 0);
	rectangle.setFillColor(sf::Color::Black);

	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(50, 500));
	rectangle2.setOutlineColor(sf::Color::Black);
	rectangle2.setOutlineThickness(0);
	rectangle2.setPosition(250, 0);
	rectangle2.setFillColor(sf::Color::Black);


	sf::RectangleShape rectangl3;
	rectangl3.setSize(sf::Vector2f(500, 50));
	rectangl3.setOutlineColor(sf::Color::Black);
	rectangl3.setOutlineThickness(0);
	rectangl3.setPosition(250, 500);
	rectangl3.setFillColor(sf::Color::Black);



	sf::RectangleShape rectangl4;
	rectangl4.setSize(sf::Vector2f(50, 250));
	rectangl4.setOutlineColor(sf::Color::Black);
	rectangl4.setOutlineThickness(0);
	rectangl4.setPosition(700, 500);
	rectangl4.setFillColor(sf::Color::Black);


	sf::RectangleShape rectangl5;
	rectangl5.setSize(sf::Vector2f(1000, 50));
	rectangl5.setOutlineColor(sf::Color::Black);
	rectangl5.setOutlineThickness(0);
	rectangl5.setPosition(750, 700);
	rectangl5.setFillColor(sf::Color::Black);



	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.

	BackgroundTexture.loadFromFile("grass.png");

	TextureSize = BackgroundTexture.getSize(); //Get size of texture.
	WindowSize = window.getSize();             //Get size of window.

	float ScaleX = (float)WindowSize.x / TextureSize.x;
	float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

	background.setTexture(BackgroundTexture);
	background.setScale(ScaleX, ScaleY);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		window.draw(background);
		window.draw(rectangle);
		window.draw(rectangle2);
		window.draw(rectangl3);
		window.draw(rectangl4);
		window.draw(rectangl5);
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