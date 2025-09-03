#include<iostream>
#include<termios.h>
#include<unistd.h>

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

