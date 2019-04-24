#include "test.h"

testcases::testcases() {

	collisionRectangle.setSize(sf::Vector2f(500, 300));
	collisionRectangle.setOutlineColor(sf::Color::Blue);
	collisionRectangle.setOutlineThickness(0);
	collisionRectangle.setPosition(250, 250);
	collisionRectangle.setFillColor(sf::Color::Blue);

}

testcases::~testcases() {



}

void testcases::printUITest() {
	sf::RenderWindow window(sf::VideoMode(1000, 950), "Print UI Test", sf::Style::Close);

	int points = 1000;
	int enemiesDefeated = 0;
	int Wave = 0;
	int hp = 100;

	UI *ui = new UI(points, enemiesDefeated, Wave, hp);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

		window.close();

	}
}
//Tests dragging and dropping sprite 1
void testcases::dragAndDropTest() {
	sf::RenderWindow window(sf::VideoMode(1000, 950), "Drag and Drop Test", sf::Style::Close);

	int points = 1000; 
	int enemiesDefeated = 0; 
	int Wave = 0;
	int hp = 100; 

	UI *ui = new UI(points, enemiesDefeated, Wave, hp);

	sf::RectangleShape rectArray[1];
	rectArray[0] = collisionRectangle;
	while (window.isOpen()) {
		sf::Event event; 
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close(); 
			}
		}

		ui->buildtower1(rectArray, window);

		if (ui->gettowerbuilt() == true) {

			//build tower1
			ui->settowerbuilt(false);

		}

		ui->resetSprite1();
		ui->draganddrop(window);
		window.clear();
		window.draw(collisionRectangle);
		ui->open(window);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			window.close();

		}
	}
}

//tests sprite 1 (Bobcat) for collision with blue rectangle 
//(Do not try to move other sprites, they are not set up for movement or collision in this test and will hug your mouse until you close the program)
void testcases::collisionDetectionTest() {

	sf::RenderWindow window(sf::VideoMode(1000, 950), "Tower Defense Collision Test", sf::Style::Close);

	int points = 1000;
	int enemiesDefeated = 0;
	int Wave = 0;
	int HP = 100;

	UI *ui = new UI(points, enemiesDefeated, Wave, HP);

	sf::RectangleShape rectArray[1];
	rectArray[0] = collisionRectangle;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		//if collision is detected with sprite 1 (Bobcat) points do not decrease,
		//if collision is not detected then points decrease by 120
		ui->buildtower1(rectArray, window);

		if (ui->gettowerbuilt() == true) {

			//build tower1
			ui->settowerbuilt(false);

		}

		ui->resetSprite1();

		ui->draganddrop(window);

		window.clear();
		window.draw(collisionRectangle);
		ui->open(window);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			window.close();

		}

	}

}