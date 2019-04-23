#include "wrapper.h"
#include <math.h> 


wrapper::wrapper() {
	//starting amount of money       1000?
	this->Currency = 1000;
	this->EnemiesDefeated = 0;
	this->WaveNum = 1;

	//health
	this->health = 100;

}
wrapper::~wrapper() {

}

void wrapper::add_enemy(int type, sf::RenderWindow &win) {
	Enemy var;
	var.setSize(sf::Vector2f(35, 35));
	sf::Texture *texture = new sf::Texture;
	texture->loadFromFile("slime1.PNG");
	var.setTexture(texture);
	var.set_x_axis(0.f);
	var.set_y_axis(5.f);
	var.setPosition(0, 0);
	if (type == 1) {
		var.hp = 1;
		var.setFillColor(sf::Color(0, 255, 0));
	}
	else if (type == 2) {
		var.hp = 2;
		var.setFillColor(sf::Color(255, 0, 0));
	}
	else if (type == 3) {
		var.hp = 3;
		var.setFillColor(sf::Color(0, 0, 255));
	}
	else if (type == 4) {
		var.hp = 4;
		var.setFillColor(sf::Color(255, 0, 255));
	}
	//win.draw(var);
	//std::cout << "Inside: " << &var << "\n";
	this->enemystack.push_back(var);
}


void wrapper::add_tower(int type, float x, float y) {
	Tower var;
	var.setSize(sf::Vector2f(35, 35));

	
	
	var.set_x_axis(x);
	var.set_y_axis(y);
	var.setPosition(x, y);
	if (type == 1) {
		var.range = 400;
		var.damage = 1;
		var.setFillColor(sf::Color(255, 0, 0));
	}
	else if (type == 2) {
		var.range = 150;
		var.damage = 2;
		var.setFillColor(sf::Color(255, 255, 0));
	}
	else if (type == 3) {
		var.range = 200;
		var.damage = 3;
		var.setFillColor(sf::Color(0, 0, 255));
	}
	else if (type == 4) {
		var.range = 200;
		var.damage = 2;
		var.setFillColor(sf::Color(0, 255, 0));
	}
	//win.draw(var);
	//std::cout << "Inside: " << &var << "\n";
	this->towerstack.push_back(var);
}

void wrapper::run_app() {


	sf::RenderWindow window(sf::VideoMode(1400, 950), "Tower Defense", sf::Style::Close);




	UI *ui = new UI(this->Currency, this->EnemiesDefeated, this->WaveNum, this->health);


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



	int runtime = 0;
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

		if (ui->gettowerbuilt() == true) {

			//build tower1

			ui->settowerbuilt(false);

		}

		ui->resetSprite1();

		ui->buildtower2(rectangleArray, window);
		if (ui->gettowerbuilt() == true) {

			//build tower2

			ui->settowerbuilt(false);

		}

		ui->resetSprite2();

		ui->buildtower3(rectangleArray, window);
		if (ui->gettowerbuilt() == true) {

			//build tower3

			ui->settowerbuilt(false);

		}

		ui->resetSprite3();

		ui->buildtower4(rectangleArray, window);
		if (ui->gettowerbuilt() == true) {

			//build tower4

			ui->settowerbuilt(false);

		}

		ui->resetSprite4();

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


		//GAME HANDLER
		if (runtime % 2600 == 0 && runtime > 1) {
			this->add_enemy(4, window);

		}
		//std::cout << this->enemystack.size() << " " << runtime << "\n";
		if (runtime % 16 == 0) {
			//std::cout << this->enemystack.size() << "\n";
			for (std::vector<Enemy>::iterator iter = this->enemystack.begin(); iter != this->enemystack.end(); ++iter) {
				if ((*iter).get_x() > 255 && (*iter).get_y() < 505) {
					(*iter).set_y_axis((*iter).get_y() + 1);
				}
				if ((*iter).get_x() <= 255 && (*iter).get_x() >= 0) {
					(*iter).set_x_axis((*iter).get_x() + 1);
				}
				if ((*iter).get_y() >= 505 && (*iter).get_x() <= 705) {
					(*iter).set_x_axis((*iter).get_x() + 1);
				}
				if ((*iter).get_y() < 705 && (*iter).get_x() > 705) {
					(*iter).set_y_axis((*iter).get_y() + 1);
				}
				if ((*iter).get_y() >= 705 && (*iter).get_x() > 705) {
					(*iter).set_x_axis((*iter).get_x() + 1);
				}

				for (std::vector<Tower>::iterator iterz = this->towerstack.begin(); iterz != this->towerstack.end(); ++iterz) {
					int x2 = (*iterz).get_x() - (*iterz).get_x();
					int x1 = (*iter).get_x() - (*iter).get_x();

					int y2 = (*iterz).get_y() - (*iterz).get_y();
					int y1 = (*iter).get_y() - (*iter).get_y();
					int mag = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

					if (mag <= (*iterz).range) {
						(*iter).hp -= (*iterz).damage;
					}
				}
				if ((*iter).hp < 1) {
					this->enemystack.erase(std::remove(this->enemystack.begin(), this->enemystack.end(), (*iter)), this->enemystack.end());
				}



				//enemy got past
				//mem leak FIXED nvmd
				//std::cout << this->health << "\n";
				if ((*iter).get_x() > 1400) {
					this->health -= (int)(*iter).hp;
					if (this->health < 1) {
						return;
					}
					this->enemystack.erase(std::remove(this->enemystack.begin(), this->enemystack.end(), (*iter)), this->enemystack.end());
				}
				(*iter).setPosition((float)(*iter).get_x(), (float)(*iter).get_y());
				Enemy null = (*iter);
				window.draw(null);
			}
		}


		window.display();
		Sleep(1);
		runtime += 16;





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