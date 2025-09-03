#include<iostream>
#include"dependencies.h"

int main() {
	char* newMenuItems[] = {
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
			goto start_game;
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
			break;
	}
	goto n_menu_update;
	
game_loop:
	printGameLoopMessage();
	sleep(1);
	goto start_game; // Requires condition for game menus

credit_roll:
	printCredits();
	sleep(1);
	goto start_game;

end_game:
	printClosingMessage();
	return 0;
}
