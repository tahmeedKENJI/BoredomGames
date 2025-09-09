#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include"game_3.h"

int main() {
	game_3::PlayerClass player1;

start_game:
	printWelcomeMessage();
	player1.addHealth(100);
	player1.showHealth();


end_game:
	return 0;
}
