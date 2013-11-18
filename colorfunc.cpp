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
	while(1) {
		std::cin>>select;
		switch(select) {
		case 1:
			color = black;
			colorText("Hello World", color);
			break;
		case 2:
			color = red;
			colorText("Hello World", color);
			break;
		case 3:
			color = green;
			colorText("Hello World", color);
			break;
		case 4:
			color = yellow;
			colorText("Hello World", color);
			break;
		case 5:
			color = blue;
			colorText("Hello World", color);
			break;
		case 6:
			color = purple;
			colorText("Hello World", color);
			break;
		case 7:
			color = aqua;
			colorText("Hello World", color);
			break;
		case 8:
			color = white;
			colorText("Hello World", color);
			break;
		default:
			std::cout<<"Invalid option";
			break;
		}
		std::cout<<std::endl;
	}

    return 0;
}
