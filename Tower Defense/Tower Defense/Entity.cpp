#include "Entity.h"

Entity::Entity() {



}

Entity::~Entity() {



}

void Entity::setEntityTexture(std::string imageFile) {
	sf::Texture texture;
	texture.loadFromFile(imageFile);
	const sf::Texture *pTexture = &texture;
	this->setTexture(pTexture);
}

//getters
float Entity::get_x() {
	return this->spawnX;
}
float Entity::get_y() {
	return this->spawnY;
}


//setters
void Entity::set_x_axis(float var) {
	this->spawnX = var;
}
void Entity::set_y_axis(float var) {
	this->spawnY = var;
}