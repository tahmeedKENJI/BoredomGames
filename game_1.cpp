#include<iostream>
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
	printMenuMessage(newMenuItems, 3);
	goto n_menu_update;

game_menu:
	printMenuMessage(newMenuItems, 3);
	goto menu_update

n_menu_update:
	char ch = getch();
	switch(ch){
		case 27:
			goto end_game;
			break;
		case '1':
			goto game_loop;
			break;
		case 'x':
			goto start_game;
			break;
		case '2':
			printCredits();
			goto new_game_menu;
			break;
		default:
	}
	goto n_menu_update;
	
game_loop:
	std::cout << "Game Loop Encountered" << std::endl;
	
end_game:
	printClosingMessage();
	return 0;
}
