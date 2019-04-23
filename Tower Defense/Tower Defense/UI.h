#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

//UPDATE: Scrapping dynamic UI. Prints to screen but can't 
//get it to go away without clearing screen.
//Tried resetting fill color to transparent to no avail.
//Will implement static display instead.

class UI {

public:

	UI(int &pointsz, int &EnemiesDefeatedz, int &WaveNumz, int &HPz);
	~UI();

	

	sf::Sprite getTower1();
	sf::Sprite getTower2();
	sf::Sprite getTower3();
	sf::Sprite getTower4();

	float getTower1LocationX();
	float getTower2LocationX();
	float getTower3LocationX();
	float getTower4LocationX();
	float getTower1LocationY();
	float getTower2LocationY();
	float getTower3LocationY();
	float getTower4LocationY();

	bool gettowerbuilt();
	void settowerbuilt(bool value);

	//uses mouse cursor position to set coordinates when left mouse button is used
	void setLocation(sf::RenderWindow &window);

	//temporary functions
	sf::Vector2f getLocation();

	//used functions
	virtual void open(sf::RenderWindow &window);

	void moveSprite1(sf::Vector2f newlocation);
	void moveSprite2(sf::Vector2f newlocation);
	void moveSprite3(sf::Vector2f newlocation);
	void moveSprite4(sf::Vector2f newlocation);
	void resetSprite1();
	void resetSprite2();
	void resetSprite3();
	void resetSprite4();
	void buildtower1(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window);
	void buildtower2(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window);
	void buildtower3(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window);
	void buildtower4(sf::RectangleShape rectangleArray[5], sf::RenderWindow &window);
	void draganddrop(sf::RenderWindow &window);

protected:

	sf::Vector2f location;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text pointsText;
	sf::Text EnemiesDefeatedText;
	sf::Text WaveNumText;
	sf::Text HPText;
	int *points;
	sf::Text pointsPrint;
	int *EnemiesDefeated;
	sf::Text EnemiesDefeatedPrint;
	int *WaveNum;
	sf::Text WaveNumPrint;
	int *HP;
	sf::Text HPPrint;
	sf::CircleShape UICircle1;
	sf::CircleShape UICircle2;
	sf::CircleShape UICircle3;
	sf::CircleShape UICircle4;
	sf::RectangleShape UIplatform;
	sf::Font font;
	sf::Sprite tower1;
	sf::Sprite tower2;
	sf::Sprite tower3;
	sf::Sprite tower4;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	bool click1;
	bool click2;
	bool click3;
	bool click4;
	bool intersect;
	bool towerbuilt;

};