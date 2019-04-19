#include "Entity.h"



//getters
double Entity::get_x() {
	return this->x;
}
double Entity::get_y() {
	return this->y;
}


//setters
void Entity::set_x_axis(double var) {
	this->x = var;
}
void Entity::set_y_axis(double var) {
	this->y = var;
}