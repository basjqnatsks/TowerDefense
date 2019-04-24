#pragma once
#include"Entity.h"
#include <iostream>
class Enemy : public Entity {
public:
	Enemy();
	~Enemy();
	int killValue;
	int hp;
	int dead;
	bool operator==(const Enemy &in) const {
		return (this == &in);
	}
};