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

	void moveSprite(sf::RenderWindow &window);

	sf::Sprite getTower1();

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
	void moveSprite(sf::Vector2f newlocation);
	void moveSprite();
	void resetSprite();

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
	sf::Texture texture;

};

//comment