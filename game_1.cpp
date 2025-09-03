#include<iostream>
#include"dependencies.h"

int main() {
start_game:
	printWelcomeMessage();
	goto game_loop;

game_loop:
	char ch = getch();
	if (ch == 27) {
		goto end_game;	
	}
	goto game_loop;
	
end_game:
	printClosingMessage();
	return 0;
}
