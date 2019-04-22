#include "Entity.h"


void Entity::setEntityTexture(std::string imageFile) {
	sf::Texture texture;
	texture.loadFromFile(imageFile);
	const sf::Texture *pTexture = &texture;
	this->setTexture(pTexture);
}

//getters
float Entity::get_x() {
	return this->x;
}
float Entity::get_y() {
	return this->y;
}


//setters
void Entity::set_x_axis(float var) {
	this->x = var;
}
void Entity::set_y_axis(float var) {
	this->y = var;
}