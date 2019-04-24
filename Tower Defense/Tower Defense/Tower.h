#pragma once
#include "Entity.h"
class Tower : public Entity {
public:
	Tower();
	~Tower();
	Tower(float killValue, float hp);
	int range;
	int damage;
};