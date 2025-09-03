#include<iostream>
#include<cstdlib>
#include"dependencies.h"

int main() {
	const char* newMenuItems[] = {
		"Reboot game -> press x",
		"Start game -> press 1",
		"Credits -> press 2",
		"Quit game -> press Esc",
	}; 

start_game:
	printWelcomeMessage();

new_game_menu:
	printMenuMessage(newMenuItems, 4);
	goto n_menu_update;

game_menu:
	printMenuMessage(newMenuItems, 4);
	//goto menu_update;

n_menu_update:
	char ch = getch();
	switch(ch){
		case 'x':
			goto reboot_game;
			break;
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

reboot_game:
	printGameRebootMessage();
	sleep(2);
	goto start_game;
	
game_loop:
	printGameLoopMessage();
	sleep(2);
	std::system("python3 ./games/game_1.py");
	sleep(2);
	goto start_game; // Requires condition for game menus

credit_roll:
	printCredits();
	sleep(2);
	goto start_game;

end_game:
	printClosingMessage();
	return 0;
}
