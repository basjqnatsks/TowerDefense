#pragma once
#include"Entity.h"
#include <iostream>
class Enemy : public Entity {
public:
	Enemy();
	~Enemy();
	Enemy(float killValue, float hp);
	void pathing(float stopCoords[][50]);
	void onHit();
	float killValue;
	int hp;
	bool operator==(const Enemy &in) const {
		return (this == &in);
	}
};