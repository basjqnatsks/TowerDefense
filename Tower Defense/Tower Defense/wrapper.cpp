#include "wrapper.h"
#include <SFML/Graphics.hpp>
#include "UI.h"


wrapper::wrapper() {
	//starting amount of money       1000?
	this->Currency = 1000;




}
wrapper::~wrapper() {

}


void wrapper::run_app() {


	sf::RenderWindow window(sf::VideoMode(1400, 950), "Tower Defense", sf::Style::Close);




	UI *ui = new UI;


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


	sf::RectangleShape rectangle3;
	rectangle3.setSize(sf::Vector2f(500, 50));
	rectangle3.setOutlineColor(sf::Color::Black);
	rectangle3.setOutlineThickness(0);
	rectangle3.setPosition(250, 500);
	rectangle3.setFillColor(sf::Color::Black);



	sf::RectangleShape rectangle4;
	rectangle4.setSize(sf::Vector2f(50, 250));
	rectangle4.setOutlineColor(sf::Color::Black);
	rectangle4.setOutlineThickness(0);
	rectangle4.setPosition(700, 500);
	rectangle4.setFillColor(sf::Color::Black);


	sf::RectangleShape rectangle5;
	rectangle5.setSize(sf::Vector2f(1000, 50));
	rectangle5.setOutlineColor(sf::Color::Black);
	rectangle5.setOutlineThickness(0);
	rectangle5.setPosition(750, 700);
	rectangle5.setFillColor(sf::Color::Black);

	sf::RectangleShape rectangleArray[5];
	rectangleArray[0] = rectangle;
	rectangleArray[1] = rectangle2;
	rectangleArray[2] = rectangle3;
	rectangleArray[3] = rectangle4;
	rectangleArray[4] = rectangle5;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		//checks collision, builds towers - *need to pass in build tower function*
		ui->buildtower1(rectangleArray, window);
		ui->buildtower2(rectangleArray, window);
		ui->buildtower3(rectangleArray, window);
		ui->buildtower4(rectangleArray, window);

		ui->draganddrop(window);

		window.clear();
		window.draw(background);
		window.draw(rectangle);
		window.draw(rectangle2);
		window.draw(rectangle3);
		window.draw(rectangle4);
		window.draw(rectangle5);
		ui->open(window);
		//window.draw(shape);
		window.display();



	}
	/*	
	
	








	bool click = false;
	bool intersect = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		



		UI *ui = new UI;
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			click = false;

			ui->resetSprite();

			//check if on path or overlapping another tower
			//use origin of sprite and size with for loop to check every pixel for intersection

			//for(int i = 0; i < numtowers; i++){

			//for(int x = ui->getTower1().getPosition().x; 
			//	x < ui->getTower1().getPosition.x + (ui->getTower1().getTexture()->getSize().x * ui->getTower1().getScale().x);
			//	x++){

			//for(int y = ui->getTower1().getPosition().y; 
			//	y < ui->getTower1().getPosition.y + (ui->getTower1().getTexture()->getSize().y * ui->getTower1().getScale().y);
			//	y++){

			//if( Tower[i]->getTowerX() == x && Tower[i]->getTowerY() == y){

			//intersect = true;

			//}

			//}
			//}
			//}

			//check if on path

			//if(intersect == false){

			//build tower

			//}
		}

		//
		if (click == true) {

			ui->moveSprite(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window)));

		}
		else if (ui->getTower1().getGlobalBounds().contains(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window))) && sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			click = true;




		}
		window.clear();
		ui->open(window);
		window.display();
	}*/

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