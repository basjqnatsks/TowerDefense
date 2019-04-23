#pragma once
#include "Entity.h"
class Tower : public Entity {
public:
	Tower();
	~Tower();
	int range;
	int damage;
};