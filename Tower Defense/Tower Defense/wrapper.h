#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include <vector>
#include "Enemy.h"
#include "Tower.h"
#include <Windows.h>




class wrapper {
public:
	wrapper();
	~wrapper();


	void run_app();
	void add_enemy(int type, sf::RenderWindow &win);

	//getters
	int get_currency();
	int get_numoftowers();
	void add_tower(int type, float x, float y);

	//setters
	void set_currency(int var);
	void set_Numberoftowers(int var);


private:
	//money
	int Currency;
	//health
	int health;
	int EnemiesDefeated;
	int WaveNum;

	//all enemies struct
	std::vector<Enemy> enemystack;

	//towers
	std::vector<Tower> towerstack;



	//should we have a maximum number of towers???
	int Numberoftowers;

};