#include "Menu.h"

Menu::Menu() {

	font.loadFromFile("DroidSans.ttf");

	text.setFont(font);
	text.setCharacterSize(35);
	text.setString("Rules:");
	text.setStyle(sf::Text::Underlined);
	text.setPosition(100.f, 130.f);

	text1.setFont(font);
	text1.setCharacterSize(30);
	text1.setString("This is a tower defense game. \nPlace animals (drag and drop) to ward off the vicious slimes. \nTowers cost a specific amount of points to build \nand cannot be placed on the enemies' path. \nIf slimes reach the end of the path you will lose HP. \nIf your HP reaches 0 you die.");
	text1.setPosition(100.f, 180.f);

	text2.setFont(font);
	text2.setCharacterSize(35);
	text2.setString("Towers:");
	text2.setStyle(sf::Text::Underlined);
	text2.setPosition(100.f, 420.f);

	text3.setFont(font);
	text3.setCharacterSize(30);
	text3.setString("Bobcat                               Red Panda\nDamage: Lowest               Damage: Medium\nRange: High                       Range: Medium\nCost: 120                           Cost: 200\n\nPika                                    Tiger\nDamage: Low                     Damage: High\nRange: Low                        Range: Medium\nCost: 100                           Cost: 300");
	text3.setPosition(100.f, 470.f);

	text4.setFont(font);
	text4.setCharacterSize(40);
	text4.setString("Animal Tower Defense: Ultimate Enhanced Edition");
	text4.setPosition(50.f, 50.f);

	text5.setFont(font);
	text5.setCharacterSize(35);
	text5.setString("Press Enter to begin game.");
	text5.setPosition(275.f, 850.f);

}

Menu::~Menu() {



}

void Menu::open(sf::RenderWindow &window) {

	
	window.draw(text);
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);

}