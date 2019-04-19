#include "map.h"



//getters
double ** map::get_location_Backend() {
	return *this->Location_BackEnd;
}


//setters
void map::set_location_backend(double var[800][800]) {
	this->Location_BackEnd = var;
}