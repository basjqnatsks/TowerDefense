#include "UI.h"


UI::UI() {

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

	UIup.setRadius(35.f);
	UIup.setFillColor(sf::Color::Black);
	UIup.setOutlineThickness(2.f);
	UIup.setOutlineColor(sf::Color::White);
	UIup.setPosition(37.f, 810.f);

	UIdown.setRadius(35.f);
	UIdown.setFillColor(sf::Color::Black);
	UIdown.setOutlineThickness(2.f);
	UIdown.setOutlineColor(sf::Color::White);
	UIdown.setPosition(192.f, 810.f);

	UIleft.setRadius(35.f);
	UIleft.setFillColor(sf::Color::Black);
	UIleft.setOutlineThickness(2.f);
	UIleft.setOutlineColor(sf::Color::White);
	UIleft.setPosition(347.f, 810.f);

	UIright.setRadius(35.f);
	UIright.setFillColor(sf::Color::Black);
	UIright.setOutlineThickness(2.f);
	UIright.setOutlineColor(sf::Color::White);
	UIright.setPosition(502.f, 810.f);

	font.loadFromFile("DroidSans.ttf");

	textUp.setCharacterSize(20);
	textUp.setString("Arrow Tower \n       100");
	textUp.setFont(font);
	textUp.setPosition(12.f, 890.f);
	textUp.setStyle(sf::Text::Bold);

	textDown.setCharacterSize(20);
	textDown.setString("Cannon Tower \n         120");
	textDown.setFont(font);
	textDown.setPosition(162.f, 890.f);
	textDown.setStyle(sf::Text::Bold);

	textLeft.setCharacterSize(20);
	textLeft.setString("Fire Tower \n     300");
	textLeft.setFont(font);
	textLeft.setPosition(332.f, 890.f);
	textLeft.setStyle(sf::Text::Bold);

	textRight.setCharacterSize(20);
	textRight.setString("Laser Tower \n      200");
	textRight.setFont(font);
	textRight.setPosition(480.f, 890.f);
	textRight.setStyle(sf::Text::Bold);

	pointsText.setCharacterSize(20);
	pointsText.setString("Points: ");
	pointsText.setFont(font);
	pointsText.setPosition(630.f, 820.f);
	pointsText.setStyle(sf::Text::Bold);

	EnemiesDefeated.setCharacterSize(20);
	EnemiesDefeated.setString("Enemies Defeated: ");
	EnemiesDefeated.setFont(font);
	EnemiesDefeated.setPosition(630.f, 850.f);
	EnemiesDefeated.setStyle(sf::Text::Bold);

	WaveNum.setCharacterSize(20);
	WaveNum.setString("Wave: ");
	WaveNum.setFont(font);
	WaveNum.setPosition(630.f, 880.f);
	WaveNum.setStyle(sf::Text::Bold);

	points = 1000;

	pointsPrint.setCharacterSize(20);
	pointsPrint.setFont(font);
	pointsPrint.setPosition(730.f, 820.f);
	pointsPrint.setStyle(sf::Text::Bold);

	texture1.loadFromFile("Bobcat.jpg");
	tower1.setTexture(texture1);
	tower1.setPosition(51.f, 832.f);
	tower1.setScale(0.05f, 0.05f);

	texture2.loadFromFile("Eevee.png");
	tower2.setTexture(texture2);
	tower2.setPosition(206.f, 832.f);
	tower2.setScale(0.2f, 0.2f);

	texture3.loadFromFile("Metal Gear.png");
	tower3.setTexture(texture3);
	tower3.setPosition(361.f, 832.f);
	tower3.setScale(0.02f, 0.02f);

	texture4.loadFromFile("Valkyr.png");
	tower4.setTexture(texture4);
	tower4.setPosition(516.f, 832.f);
	tower4.setScale(0.1f, 0.1f);

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

void UI::setUIupPostion() {

	UIup.setPosition(location.x - 50.f, location.y - 150.f);

}

void UI::setUIdownPosition() {

	UIdown.setPosition(location.x - 50.f, location.y + 50.f);

}

void UI::setUIleftPosition() {

	UIleft.setPosition(location.x - 150.f, location.y - 50.f);

}

void UI::setUIrightPosition() {

	UIright.setPosition(location.x + 50.f, location.y - 50.f);

}

void UI::setUIcenterPosition() {

	UIcenter.setPosition(location.x - 5.f, location.y - 5.f);

}

void UI::setUIupColor(sf::Color fillColor, sf::Color outlineColor) {

	UIup.setFillColor(fillColor);
	UIup.setOutlineColor(outlineColor);

}

void UI::setUIdownColor(sf::Color fillColor, sf::Color outlineColor) {

	UIdown.setFillColor(fillColor);
	UIdown.setOutlineColor(outlineColor);

}

void UI::setUIleftColor(sf::Color fillColor, sf::Color outlineColor) {

	UIleft.setFillColor(fillColor);
	UIleft.setOutlineColor(outlineColor);

}

void UI::setUIrightColor(sf::Color fillColor, sf::Color outlineColor) {

	UIright.setFillColor(fillColor);
	UIright.setOutlineColor(outlineColor);

}

void UI::setUIcenterColor(sf::Color fillColor, sf::Color outlineColor) {

	UIcenter.setFillColor(fillColor);
	UIcenter.setOutlineColor(outlineColor);

}

void UI::open(sf::RenderWindow &window) {

	pointsPrint.setString(std::to_string(points));

	window.draw(UIplatform);
	window.draw(UIup);
	window.draw(UIdown);
	window.draw(UIleft);
	window.draw(UIright);

	window.draw(textUp);
	window.draw(textDown);
	window.draw(textLeft);
	window.draw(textRight);
	window.draw(pointsText);
	window.draw(EnemiesDefeated);
	window.draw(WaveNum);
	window.draw(tower1);
	window.draw(tower2);
	window.draw(tower3);
	window.draw(tower4);
	window.draw(pointsPrint);

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

sf::CircleShape UI::getUIup() {

	return UIup;

}

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

void UI::resetSprite1() {

	tower1.setPosition(51.f, 832.f);

}

void UI::resetSprite2() {

	tower2.setPosition(206.f, 832.f);

}

void UI::resetSprite3() {

	tower3.setPosition(361.f, 832.f);

}

void UI::resetSprite4() {

	tower4.setPosition(516.f, 832.f);

}

void UI::buildtower1(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click1 == true) {

		click1 = false;

		//check if on path or overlapping another tower
		//use origin of sprite and size with for loop to check every pixel for intersection

		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

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

		//check if on ui platform**********************************************************

		if (intersect == false && points >= 100) {

			//build tower 1
			towerbuilt = true;

			points = points - 100;

		}
		else if (intersect == true) {

			intersect = false;

		}

		resetSprite1();
		
	}

}	

void UI::buildtower2(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click2 == true) {

		click2 = false;

		//check if on path or overlapping another tower
		//use origin of sprite and size with for loop to check every pixel for intersection

		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

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

		if (intersect == false && points >= 120) {

			//build tower 2
			towerbuilt = true;
			points = points - 120;


		}
		else if (intersect == true) {

			intersect = false;

		}

		resetSprite2();

	}

}

void UI::buildtower3(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click3 == true) {

		click3 = false;
		
		//check if on path or overlapping another tower
		//use origin of sprite and size with for loop to check every pixel for intersection

		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

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

		if (intersect == false && points >= 300) {

			//build tower 3
			towerbuilt = true;
			points = points - 300;


		}
		else if (intersect == true) {

			intersect = false;

		}

		resetSprite3();

	}

}

void UI::buildtower4(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window) {

	//"drops" sprites, builds tower if not on path
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && click4 == true) {

		click4 = false;

		//check if on path or overlapping another tower
		//use origin of sprite and size with for loop to check every pixel for intersection

		for (int i = 0; i < 5; i++) {

			if (intersect == false) {

				for (float x = rectangleArray[i].getPosition().x;
					x < rectangleArray[i].getPosition().x + rectangleArray[i].getSize().x;
					x++) {

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

		if (intersect == false && points >= 200) {

			//build tower 4
			towerbuilt = true;
			points = points - 200;

		}
		else if (intersect == true) {

			intersect = false;

		}

		resetSprite4();

	}

}

void UI::draganddrop(sf::RenderWindow &window) {

	//enables drag and drop movement of sprites
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



//will need later
//sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(mousePosition);

//comment