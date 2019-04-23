#include "wrapper.h"
#include "test.h"
#include "UI.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <iostream>
int main() {

	wrapper app;
	app.run_app();

	std::cout << system("curl -i -H \"Accept: application/json\" -H \"Content-Type: application/json\" -X GET https://raw.githubusercontent.com/basjqnatsks/TowerDefense/master/Tower%20Defense/Menu.txt");

	return 0;


}