#pragma once
#include "wrapper.h"
class testcases {
public:
	testcases();
	~testcases();

	void collisionDetectionTest();
	void dragAndDropTest(); 
	void printUITest(); 
private:

	sf::RectangleShape collisionRectangle;


};