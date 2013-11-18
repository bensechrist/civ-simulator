#include <cstdio>
#include <iostream>

typedef enum colors { black = 30, red, green, yellow, blue, purple, aqua, white } consoleColors;

void colorText(char* input, consoleColors color) {
	std::cout<<"\033[0;"<<color<<"m"<<input<<"\033[0m";
}

int main(int argc, char ** argv)
{
	int select;
	consoleColors color;
	std::cin>>select;
	switch(select) {
	case 1:
		color = black;
		break;
	case 2:
		color = red;
		break;
	case 3:
		color = green;
		break;
	case 4:
		color = yellow;
		break;
	case 5:
		color = blue;
		break;
	case 6:
		color = purple;
		break;
	case 7:
		color = aqua;
		break;
	case 8:
		color = white;
		break;
	}
	colorText("Hello World", color);
	std::cout<<std::endl;

    return 0;
}
