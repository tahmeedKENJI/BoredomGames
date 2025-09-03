#include<iostream>
#include<cstdlib>
#include"dependencies.h"

int main() {
	const char* newMenuItems[] = {
		"Start game -> press 1",
		"Credits -> press 2",
		"Quit game -> press Esc",
	}; 

	std::cout << "Press any key to start" << std::endl;
	std::cin.get();

start_game:
	printWelcomeMessage();

new_game_menu:
	printMenuMessage(newMenuItems, 3);
	goto n_menu_update;

n_menu_update:
	char ch = getch();
	switch(ch){
		case '1':
			goto game_loop;
			break;
		case '2':
			goto credit_roll;
			break;
		case 27:
			goto end_game;
			break;
		default:
			goto n_menu_update;
			break;
	}
	goto n_menu_update;

game_loop:
	printGameLoopMessage();
	sleep(2);
	std::cout << "\033c" << std::endl;
	std::system("python3 ./games/game_1.py");
	std::cout << "Press any key to exit" << std::endl;
	std::cin.get();
	goto start_game;

credit_roll:
	printCredits();
	sleep(2);
	std::cout << "Press any key to exit" << std::endl;
	std::cin.get();
	goto start_game;

end_game:
	printClosingMessage();
	return 0;
}
