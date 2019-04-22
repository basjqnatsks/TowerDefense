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


	bool click = false;
	bool intersect = false;


	UI *ui = new UI;



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

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
		//window.draw(shape);
		window.display();



	}

	return 0;


}