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

	UI();
	~UI();

	

	sf::Sprite getTower1();
	sf::Sprite getTower2();
	sf::Sprite getTower3();
	sf::Sprite getTower4();

	//uses mouse cursor position to set coordinates when left mouse button is used
	void setLocation(sf::RenderWindow &window);
	//void setSelectLocation(sf::Vector2f newLocation);

	//temporary functions
	sf::Vector2f getLocation();
	//sf::Vector2f getSelectLocation();

	void setUIupPostion();
	void setUIdownPosition();
	void setUIleftPosition();
	void setUIrightPosition();
	void setUIcenterPosition();
	
	
	void setUIupColor(sf::Color fillColor, sf::Color outlineColor);
	void setUIdownColor(sf::Color fillColor, sf::Color outlineColor);
	void setUIleftColor(sf::Color fillColor, sf::Color outlineColor);
	void setUIrightColor(sf::Color fillColor, sf::Color outlineColor);
	void setUIcenterColor(sf::Color fillColor, sf::Color outlineColor);
	

	virtual void open(sf::RenderWindow &window);
	sf::CircleShape getUIup();

	void moveSprite1(sf::Vector2f newlocation);
	void moveSprite2(sf::Vector2f newlocation);
	void moveSprite3(sf::Vector2f newlocation);
	void moveSprite4(sf::Vector2f newlocation);
	void resetSprite1();
	void resetSprite2();
	void resetSprite3();
	void resetSprite4();

protected:

	sf::Vector2f location;
	sf::Vector2f UIlocation;
	sf::Text textUp;
	sf::Text textDown;
	sf::Text textLeft;
	sf::Text textRight;
	sf::Text pointsText;
	sf::Text EnemiesDefeated;
	sf::Text WaveNum;
	sf::CircleShape UIup;
	sf::CircleShape UIdown;
	sf::CircleShape UIleft;
	sf::CircleShape UIright;
	sf::CircleShape UIcenter;
	sf::RectangleShape UIplatform;
	sf::Font font;
	sf::Vector2f selectLocation;
	int points;
	sf::Text pointsPrint;
	sf::Sprite tower1;
	sf::Sprite tower2;
	sf::Sprite tower3;
	sf::Sprite tower4;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;

};

//comment