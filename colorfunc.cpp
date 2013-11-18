#include <cstdio>
#include <string>
#include <iostream>

typedef enum colors { black = 30, red, green, yellow, blue, purple, aqua, white, grayBG = 40, redBG, greenBG, yellowBG, blueBG, purpleBG, aquaBG, whiteBG } consoleColors;

void colorText(std::string input, int color, int bg) {
	std::cout<<"\033[0;"<<color<<";"<<bg<<"m"<<input<<"\033[0m";
}

int main(int argc, char ** argv)
{

	for (int i=30; i<38; i++) {
		for (int j=40; j<48; j++) {
			colorText("Hello World", i, j);
			std::cout<<std::endl;
		}
	}

	int select;
	consoleColors color;
	consoleColors bgColor;
	/*while(1) {
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
	}*/

    return 0;
}
