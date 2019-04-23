#pragma once
#include "Entity.h"
class Enemy : public Entity {
public:
	Enemy();
	~Enemy();
	//Enemy(float killValue, float hp);
	//void pathing(float stopCoords[][50]);
	//void onHit();

private:
	float killValue;
	float hp;
};