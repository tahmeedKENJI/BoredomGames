#include<iostream>
#include<termios.h>
#include<unistd.h>

void printWelcomeMessage() {
	std::cout <<  R"(
/////////////////////////////////////////////////////////////////////////////////////////////////////////

██████╗░░█████╗░██████╗░███████╗██████╗░░█████╗░███╗░░░███╗  ░██████╗░░█████╗░███╗░░░███╗███████╗░██████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗████╗░████║  ██╔════╝░██╔══██╗████╗░████║██╔════╝██╔════╝
██████╦╝██║░░██║██████╔╝█████╗░░██║░░██║██║░░██║██╔████╔██║  ██║░░██╗░███████║██╔████╔██║█████╗░░╚█████╗░
██╔══██╗██║░░██║██╔══██╗██╔══╝░░██║░░██║██║░░██║██║╚██╔╝██║  ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░░╚═══██╗
██████╦╝╚█████╔╝██║░░██║███████╗██████╔╝╚█████╔╝██║░╚═╝░██║  ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗██████╔╝
╚═════╝░░╚════╝░╚═╝░░╚═╝╚══════╝╚═════╝░░╚════╝░╚═╝░░░░░╚═╝  ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝╚═════╝░

/////////////////////////////////////////////////////////////////////////////////////////////////////////
	)" << std::endl;
	std::cout << "Welcome to boredom games" << std::endl;                                                                                     
    std::cout << "Here we play; A text-based game to keep you entertained" << std::endl;
}

char getch() {
     char buf = 0;
     termios old = {};
     if (tcgetattr(STDIN_FILENO, &old) < 0) perror("tcsetattr()");
     termios new_term = old;
     new_term.c_lflag &= ~(ICANON | ECHO);
     if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) < 0) perror("tcsetattr ICANON");
     if (read(STDIN_FILENO, &buf, 1) < 0) perror("read()");
     if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0) perror("tcsetattr ~ICANON");
     return buf;
 }

void printClosingMessage() {
	std::cout << "Closing games" << std::endl;
	std::cout <<  R"(
/////////////////////////////////////////////////////////////////////////////////////////////////////////

████████╗██╗░░██╗███████╗  ███████╗███╗░░██╗██████╗░
╚══██╔══╝██║░░██║██╔════╝  ██╔════╝████╗░██║██╔══██╗
░░░██║░░░███████║█████╗░░  █████╗░░██╔██╗██║██║░░██║
░░░██║░░░██╔══██║██╔══╝░░  ██╔══╝░░██║╚████║██║░░██║
░░░██║░░░██║░░██║███████╗  ███████╗██║░╚███║██████╔╝
░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚══════╝╚═╝░░╚══╝╚═════╝░

/////////////////////////////////////////////////////////////////////////////////////////////////////////
	)" << std::endl;
}

void printMenuMessage(char* menuItems[], int numOfItems) {
	std::cout << R"(
GAME MENU
	)" << std::endl;
	for (int i = 0; i < numOfItems; i++){
		std::cout  << menuItems[i] << std::endl; 
	}
}

void printCredits() {
	std::cout << R"(
CREDITS
	)" << std::endl;
	std::cout << "Tahmeed" << std::endl;
}

void printGameLoopMessage() {
	std::cout << R"(
GAME LOOP
	)" << std::endl;
	std::cout << "Debug: Game loop encountered" << std::endl;
}
