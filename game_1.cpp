#include<iostream>
#include<termios.h>
#include<unistd.h>
#include"dependencies.h"

int main() {
start_game:
	std::cout << "Welcome to boredom games" << std::endl;
	std::cout << "Here we play; A text-based game to keep you entertained" << std::endl;
	goto game_loop;

game_loop:
	char ch = getch();
	if (ch == 27) {
		goto end_game;	
	}
	
end_game:
	std::cout << "Closing game" << std::endl;
	return 0;
}
