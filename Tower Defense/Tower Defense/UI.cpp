#include "UI.h"

UI::UI() {


}

UI::UI(int &pointsz, int &EnemiesDefeatedz, int &WaveNumz, int &HPz) {
	this->points = &pointsz;
	this->EnemiesDefeated = &EnemiesDefeatedz;
	this->WaveNum = &WaveNumz;
	this->HP = &HPz;


	click1 = false;
	click2 = false;
	click3 = false;
	click4 = false;
	intersect = false;
	towerbuilt = false;

	location = sf::Vector2f(100.f, 100.f);

	UIplatform.setSize(sf::Vector2f(900.f, 150.f));
	UIplatform.setFillColor(sf::Color::Black);
	UIplatform.setOutlineThickness(10.f);
	UIplatform.setOutlineColor(sf::Color::White);
	UIplatform.setPosition(0.f, 800.f);

	UICircle1.setRadius(35.f);
	UICircle1.setFillColor(sf::Color::Black);
	UICircle1.setOutlineThickness(2.f);
	UICircle1.setOutlineColor(sf::Color::White);
	UICircle1.setPosition(37.f, 810.f);

	UICircle2.setRadius(35.f);
	UICircle2.setFillColor(sf::Color::Black);
	UICircle2.setOutlineThickness(2.f);
	UICircle2.setOutlineColor(sf::Color::White);
	UICircle2.setPosition(192.f, 810.f);

	UICircle3.setRadius(35.f);
	UICircle3.setFillColor(sf::Color::Black);
	UICircle3.setOutlineThickness(2.f);
	UICircle3.setOutlineColor(sf::Color::White);
	UICircle3.setPosition(347.f, 810.f);

	UICircle4.setRadius(35.f);
	UICircle4.setFillColor(sf::Color::Black);
	UICircle4.setOutlineThickness(2.f);
	UICircle4.setOutlineColor(sf::Color::White);
	UICircle4.setPosition(502.f, 810.f);

	font.loadFromFile("DroidSans.ttf");

	text1.setCharacterSize(20);
	text1.setString("Bobcat \n  120");
	text1.setFont(font);
	text1.setPosition(35.f, 890.f);
	text1.setStyle(sf::Text::Bold);

	text2.setCharacterSize(20);
	text2.setString("Pika \n100");
	text2.setFont(font);
	text2.setPosition(205.f, 890.f);
	text2.setStyle(sf::Text::Bold);

	text3.setCharacterSize(20);
	text3.setString("Red Panda \n     200");
	text3.setFont(font);
	text3.setPosition(332.f, 890.f);
	text3.setStyle(sf::Text::Bold);

	text4.setCharacterSize(20);
	text4.setString("Tiger \n 300");
	text4.setFont(font);
	text4.setPosition(512.f, 890.f);
	text4.setStyle(sf::Text::Bold);

	pointsText.setCharacterSize(20);
	pointsText.setString("Points: ");
	pointsText.setFont(font);
	pointsText.setPosition(630.f, 820.f);
	pointsText.setStyle(sf::Text::Bold);

	EnemiesDefeatedText.setCharacterSize(20);
	EnemiesDefeatedText.setString("Enemies Defeated: ");
	EnemiesDefeatedText.setFont(font);
	EnemiesDefeatedText.setPosition(630.f, 850.f);
	EnemiesDefeatedText.setStyle(sf::Text::Bold);

	WaveNumText.setCharacterSize(20);
	WaveNumText.setString("Wave: ");
	WaveNumText.setFont(font);
	WaveNumText.setPosition(630.f, 880.f);
	WaveNumText.setStyle(sf::Text::Bold);

	HPText.setCharacterSize(20);
	HPText.setString("HP: ");
	HPText.setFont(font);
	HPText.setPosition(630.f, 910.f);
	HPText.setStyle(sf::Text::Bold);



	pointsPrint.setCharacterSize(20);
	pointsPrint.setFont(font);
	pointsPrint.setPosition(710.f, 820.f);
	pointsPrint.setStyle(sf::Text::Bold);

	EnemiesDefeatedPrint.setCharacterSize(20);
	EnemiesDefeatedPrint.setFont(font);
	EnemiesDefeatedPrint.setPosition(830.f, 850.f);
	EnemiesDefeatedPrint.setStyle(sf::Text::Bold);

	WaveNumPrint.setCharacterSize(20);
	WaveNumPrint.setFont(font);
	WaveNumPrint.setPosition(710.f, 880.f);
	WaveNumPrint.setStyle(sf::Text::Bold);

	HPPrint.setCharacterSize(20);
	HPPrint.setFont(font);
	HPPrint.setPosition(670.f, 910.f);
	HPPrint.setStyle(sf::Text::Bold);

	texture1.loadFromFile("Bobcat.jpg");
	tower1.setTexture(texture1);
	tower1.setPosition(51.f, 832.f);
	tower1.setScale(0.05f, 0.05f);

	texture2.loadFromFile("Pika.jpg");
	tower2.setTexture(texture2);
	tower2.setPosition(202.f, 829.f);
	tower2.setScale(0.05f, 0.05f);

	texture3.loadFromFile("Red Panda.jpg");
	tower3.setTexture(texture3);
	tower3.setPosition(358.f, 832.f);
	tower3.setScale(0.06f, 0.06f);

	texture4.loadFromFile("Tiger.jpg");
	tower4.setTexture(texture4);
	tower4.setPosition(513.f, 830.f);
	tower4.setScale(0.06f, 0.07f);

}

UI::~UI() {



}



//uses mouse cursor position to set coordinates when left mouse button is used
void UI::setLocation(sf::RenderWindow &window) {

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(mousePosition);

	location = mousePositionFloat;

}

sf::Vector2f UI::getLocation() {

	return location;

}

//prints UI
void UI::open(sf::RenderWindow &window) {

	pointsPrint.setString(std::to_string(*this->points));
	EnemiesDefeatedPrint.setString(std::to_string(*EnemiesDefeated));
	WaveNumPrint.setString(std::to_string(*WaveNum));
	HPPrint.setString(std::to_string(*HP));

	window.draw(UIplatform);
	window.draw(UICircle1);
	window.draw(UICircle2);
	window.draw(UICircle3);
	window.draw(UICircle4);

	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(pointsText);
	window.draw(EnemiesDefeatedText);
	window.draw(WaveNumText);
	window.draw(HPText);
	window.draw(tower1);
	window.draw(tower2);
	window.draw(tower3);
	window.draw(tower4);
	window.draw(pointsPrint);
	window.draw(EnemiesDefeatedPrint);
	window.draw(WaveNumPrint);
	window.draw(HPPrint);

}

sf::Sprite UI::getTower1() {

	return tower1;

}

sf::Sprite UI::getTower2() {

	return tower2;

}

sf::Sprite UI::getTower3() {

	return tower3;

}

sf::Sprite UI::getTower4() {

	return tower4;

}

float UI::getTower1LocationX() {

	return tower1.getPosition().x;

}

float UI::getTower2LocationX() {

	return tower2.getPosition().x;

}

float UI::getTower3LocationX() {

	return tower3.getPosition().x;

}

float UI::getTower4LocationX() {

	return tower4.getPosition().x;

}

float UI::getTower1LocationY() {

	return tower1.getPosition().y;

}

float UI::getTower2LocationY() {

	return tower2.getPosition().y;

}

float UI::getTower3LocationY() {

	return tower3.getPosition().y;

}

float UI::getTower4LocationY() {

	return tower4.getPosition().y;

}

//enables sprite movement
void UI::moveSprite1(sf::Vector2f newlocation) {

	tower1.setPosition(newlocation.x - 15.f, newlocation.y - 10.f);

}

void UI::moveSprite2(sf::Vector2f newlocation) {

	tower2.setPosition(newlocation.x - 15.f, newlocation.y - 10.f);

}

void UI::moveSprite3(sf::Vector2f newlocation) {

	tower3.setPosition(newlocation.x - 15.f, newlocation.y - 10.f);

}

void UI::moveSprite4(sf::Vector2f newlocation) {

	tower4.setPosition(newlocation.x - 15.f, newlocation.y - 10.f);

}

//resets sprites to original position
void UI::resetSprite1() {

	tower1.setPosition(51.f, 832.f);

}

void UI::resetSprite2() {

	tower2.setPosition(202.f, 829.f);

}

void UI::resetSprite3() {

	tower3.setPosition(358.f, 832.f);

}

void UI::resetSprite4() {

	tower4.setPosition(513.f, 830.f);

}

//allows "towers" to be "built"
void UI::buildtower1(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click1 == true) {

		click1 = false;

		//check if on path
		//use position of path rectangles and check to see if path pixels contained in sprite
		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

					if (intersect == false) {

						for (float y = rectangleArray[i].getPosition().y;
							y < rectangleArray[i].getPosition().y + rectangleArray[i].getSize().y;
							y++) {

							if (tower1.getGlobalBounds().contains(x, y) && intersect == false) {

								intersect = true;

							}

						}

					}

				}

			}

		}

		//check if on ui platform
		for (float x = UIplatform.getPosition().x - 10.f;
			x < (UIplatform.getPosition().x - 10.f) + UIplatform.getSize().x + 20.f;
			x++) {

			if (intersect == false) {

				for (float y = UIplatform.getPosition().y - 10.f;
					y < (UIplatform.getPosition().y - 10.f) + UIplatform.getSize().y + 20.f;
					y++) {

					if (tower1.getGlobalBounds().contains(x, y) && intersect == false) {

						intersect = true;

					}
				}
			}
		}

		//build tower if no intersection
		if (intersect == false && *points >= 120) {

			//build tower 1
			towerbuilt = true;

			*points = *points - 120;

		}
		else if (intersect == true) {

			intersect = false;

		}
		
	}

}	

void UI::buildtower2(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click2 == true) {

		click2 = false;

		//check if on path
		//use position of path rectangles and check to see if path pixels contained in sprite
		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

					if (intersect == false) {

						for (float y = rectangleArray[i].getPosition().y;
							y < rectangleArray[i].getPosition().y + rectangleArray[i].getSize().y;
							y++) {

							if (tower2.getGlobalBounds().contains(x, y) && intersect == false) {

								intersect = true;

							}

						}

					}

				}

			}

		}

		//check if on ui platform
		for (float x = UIplatform.getPosition().x - 10.f;
			x < (UIplatform.getPosition().x - 10.f) + UIplatform.getSize().x + 20.f;
			x++) {

			if (intersect == false) {

				for (float y = UIplatform.getPosition().y - 10.f;
					y < (UIplatform.getPosition().y - 10.f) + UIplatform.getSize().y + 20.f;
					y++) {

					if (tower2.getGlobalBounds().contains(x, y) && intersect == false) {

						intersect = true;

					}

				}

			}

		}

		if (intersect == false && *points >= 100) {

			//build tower 2
			towerbuilt = true;
			*points = *points - 100;


		}
		else if (intersect == true) {

			intersect = false;

		}

	}

}

void UI::buildtower3(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click3 == true) {

		click3 = false;
		
		//check if on path
		//use position of path rectangles and check to see if path pixels contained in sprite
		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

					if (intersect == false) {

						for (float y = rectangleArray[i].getPosition().y;
							y < rectangleArray[i].getPosition().y + rectangleArray[i].getSize().y;
							y++) {

							if (tower3.getGlobalBounds().contains(x, y) && intersect == false) {

								intersect = true;

							}

						}

					}

				}

			}

		}

		//check if on ui platform
		for (float x = UIplatform.getPosition().x - 10.f;
			x < (UIplatform.getPosition().x - 10.f) + UIplatform.getSize().x + 20.f;
			x++) {

			if (intersect == false) {

				for (float y = UIplatform.getPosition().y - 10.f;
					y < (UIplatform.getPosition().y - 10.f) + UIplatform.getSize().y + 20.f;
					y++) {

					if (tower3.getGlobalBounds().contains(x, y) && intersect == false) {

						intersect = true;

					}

				}

			}

		}

		if (intersect == false && *points >= 200) {

			//build tower 3
			towerbuilt = true;
			*points = *points - 200;


		}
		else if (intersect == true) {

			intersect = false;

		}

	}

}

void UI::buildtower4(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click4 == true) {

		click4 = false;

		//check if on path
		//use position of path rectangles and check to see if path pixels contained in sprite
		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

					if (intersect == false) {

						for (float y = rectangleArray[i].getPosition().y;
							y < rectangleArray[i].getPosition().y + rectangleArray[i].getSize().y;
							y++) {

							if (tower4.getGlobalBounds().contains(x, y) && intersect == false) {

								intersect = true;

							}
						}

					}

				}

			}

		}

		//check if on ui platform
		for (float x = UIplatform.getPosition().x - 10.f;
			x < (UIplatform.getPosition().x - 10.f) + UIplatform.getSize().x + 20.f;
			x++) {

			if (intersect == false) {

				for (float y = UIplatform.getPosition().y - 10.f;
					y < (UIplatform.getPosition().y - 10.f) + UIplatform.getSize().y + 20.f;
					y++) {

					if (tower4.getGlobalBounds().contains(x, y) && intersect == false) {

						intersect = true;

					}
				}
			}
		}

		if (intersect == false && *points >= 300) {

			//build tower 4
			towerbuilt = true;
			*points = *points - 300;

		}
		else if (intersect == true) {

			intersect = false;

		}

	}

}

//enables drag and drop movement of sprites
void UI::draganddrop(sf::RenderWindow &window) {

	if (click1 == true) {

		moveSprite1(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window)));

	}
	else if (click2 == true) {

		moveSprite2(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window)));

	}
	else if (click3 == true) {

		moveSprite3(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window)));

	}
	else if (click4 == true) {

		moveSprite4(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window)));

	}
	else if (getTower1().getGlobalBounds().contains(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window))) && sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		click1 = true;

	}
	else if (getTower2().getGlobalBounds().contains(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window))) && sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		click2 = true;

	}
	else if (getTower3().getGlobalBounds().contains(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window))) && sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		click3 = true;

	}
	else if (getTower4().getGlobalBounds().contains(static_cast <sf::Vector2f> (sf::Mouse::getPosition(window))) && sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		click4 = true;

	}

}

//used for tower placement
bool UI::gettowerbuilt() {

	return towerbuilt;

}

void UI::settowerbuilt(bool value) {

	towerbuilt = value;

}