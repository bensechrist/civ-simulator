#include <cstdio>
#include <iostream>

typedef enum colors { black = 30, red, green, yellow, blue, purple, aqua, white } consoleColors;

void colorText(char* input, consoleColors color) {
	std::cout<<"\033[0;"<<color<<"m"<<input<<"\033[0m";
}

int main(int argc, char ** argv)
{
	int select
	consoleColors color;
	std::cin<<select;
	switch(select) {
	case 1:
		color = black;
	case 2:
		color = red;
	case 3:
		color = green;
	case 4:
		color = yellow;
	case 5:
		color = blue;
	case 6:
		color = purple;
	case 7:
		color = aqua;
	case 8:
		color = white;
	}
	colorText("Hello World", color);
	std::cout<<std::endl;

    return 0;
}
