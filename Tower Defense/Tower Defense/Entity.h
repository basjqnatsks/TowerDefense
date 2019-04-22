#pragma once
#include "SFML/Graphics.hpp"

class Entity : public sf::RectangleShape {

public:
	Entity();
	~Entity();

	void setEntityTexture(std::string imageFile);

	//getters
	float get_x();
	float get_y();

	//setters
	void set_x_axis(float var);
	void set_y_axis(float var);

private:
	float spawnX;
	float spawnY;

	std::string imageFile;
};
