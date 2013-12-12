#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <curses.h>
using namespace std;

// Global Variables
char landChar, mountainChar, forestChar, oceanChar, riverChar;
int landColor, mountainColor, forestColor, oceanColor, riverColor;
int landBGColor, mountainBGColor, forestBGColor, oceanBGColor, riverBGColor;

void colorText(char input) {	
	if (input == landChar) {
		attron(COLOR_PAIR(20));
		addch(input);
		attroff(COLOR_PAIR(20));
	} else if (input == mountainChar) {
		attron(COLOR_PAIR(21));
		addch(input);
		attroff(COLOR_PAIR(21));
	} else if (input == forestChar) {
		attron(COLOR_PAIR(22));
		addch(input);
		attroff(COLOR_PAIR(22));
	} else if (input == oceanChar) {
		attron(COLOR_PAIR(23));
		addch(input);
		attroff(COLOR_PAIR(23));
	} else if (input == riverChar) {
		attron(COLOR_PAIR(24));
		addch(input);
		attroff(COLOR_PAIR(24));
	} else {
		cout<<"?";
	}
}

void colorObject(char input, int color, char BGChar) {
	if (BGChar == landChar) {
		init_pair(0, COLOR_BLACK, landBGColor);
		init_pair(1, COLOR_RED, landBGColor);
		init_pair(2, COLOR_GREEN, landBGColor);
		init_pair(3, COLOR_YELLOW, landBGColor);
		init_pair(4, COLOR_BLUE, landBGColor);
		init_pair(5, COLOR_MAGENTA, landBGColor);
		init_pair(6, COLOR_CYAN, landBGColor);
		init_pair(7, COLOR_WHITE, landBGColor);
	} else if (BGChar == mountainChar) {
		init_pair(0, COLOR_BLACK, mountainBGColor);
		init_pair(1, COLOR_RED, mountainBGColor);
		init_pair(2, COLOR_GREEN, mountainBGColor);
		init_pair(3, COLOR_YELLOW, mountainBGColor);
		init_pair(4, COLOR_BLUE, mountainBGColor);
		init_pair(5, COLOR_MAGENTA, mountainBGColor);
		init_pair(6, COLOR_CYAN, mountainBGColor);
		init_pair(7, COLOR_WHITE, mountainBGColor);
	} else if (BGChar == forestChar) {
		init_pair(0, COLOR_BLACK, forestBGColor);
		init_pair(1, COLOR_RED, forestBGColor);
		init_pair(2, COLOR_GREEN, forestBGColor);
		init_pair(3, COLOR_YELLOW, forestBGColor);
		init_pair(4, COLOR_BLUE, forestBGColor);
		init_pair(5, COLOR_MAGENTA, forestBGColor);
		init_pair(6, COLOR_CYAN, forestBGColor);
		init_pair(7, COLOR_WHITE, forestBGColor);
	} else if (BGChar == oceanChar) {
		init_pair(0, COLOR_BLACK, oceanBGColor);
		init_pair(1, COLOR_RED, oceanBGColor);
		init_pair(2, COLOR_GREEN, oceanBGColor);
		init_pair(3, COLOR_YELLOW, oceanBGColor);
		init_pair(4, COLOR_BLUE, oceanBGColor);
		init_pair(5, COLOR_MAGENTA, oceanBGColor);
		init_pair(6, COLOR_CYAN, oceanBGColor);
		init_pair(7, COLOR_WHITE, oceanBGColor);
	} else if (BGChar == riverChar) {
		init_pair(0, COLOR_BLACK, riverBGColor);
		init_pair(1, COLOR_RED, riverBGColor);
		init_pair(2, COLOR_GREEN, riverBGColor);
		init_pair(3, COLOR_YELLOW, riverBGColor);
		init_pair(4, COLOR_BLUE, riverBGColor);
		init_pair(5, COLOR_MAGENTA, riverBGColor);
		init_pair(6, COLOR_CYAN, riverBGColor);
		init_pair(7, COLOR_WHITE, riverBGColor);
	}
	attron(COLOR_PAIR(color));
	addch(input | A_BOLD);
	attroff(COLOR_PAIR(color));
}

int main(int argc, char **) {
	ifstream config("./config");
	ifstream actionList("./action_list.txt");

	initscr();
	
	start_color();			/* Start color 			*/
	
	init_pair(1, COLOR_RED, COLOR_BLACK);

	if (config.fail() || actionList.fail()) {
		cerr << "printmap: failed to open map, actionlist, or config file"<<endl;
	}
	
	string configParams[15] = {
    "plains_character",
		"plains_color",
		"plains_BG_color",
    "mountain_character",
		"mountain_color",
		"mountain_BG_color",
    "forest_character",
		"forest_color",
		"forest_BG_color",
    "ocean_character",
		"ocean_color",
		"ocean_BG_color",
    "river_character",
		"river_color",
		"river_BG_color"
  };
	
	for (int i = 0; i < 15;i++) {
    if(config.eof()) break;

		string line;
    getline(config, line);
		
		int lineLocation;
		int lineEnd;

    lineLocation = line.find(configParams[i]);

    if(lineLocation >= 0) {
				lineLocation = line.find_first_of(39);   //look for apostrophe
				lineEnd = line.find_last_of(39);
				istringstream tempStream(line.substr(lineLocation+1, lineEnd-lineLocation-1));
				switch(i) {
            case 0:
            	tempStream >> landChar;
              break;
						case 1:
							tempStream >> landColor;
              break;
						case 2:
							tempStream >> landBGColor;
							break;
            case 3:
              tempStream >> mountainChar;
              break;
						case 4:
							tempStream >> mountainColor;
              break;
						case 5:
							tempStream >> mountainBGColor;
							break;
						case 6:
							tempStream >> forestChar;
							break;
						case 7:
							tempStream >> forestColor;
							break;
						case 8:
							tempStream >> forestBGColor;
							break;
						case 9:
							tempStream >> oceanChar;
							break;
						case 10:
							tempStream >> oceanColor;
							break;
						case 11:
							tempStream >> oceanBGColor;
							break;
						case 12:
							tempStream >> riverChar;
							break;
						case 13:
							tempStream >> riverColor;
							break;
						case 14:
							tempStream >> riverBGColor;
							break;
            default:
              cerr << "MapCreate: Error: Something went wrong while parsing.";
            }
        } else i--;
    }
    
  	init_pair(20, landColor, landBGColor);
  	init_pair(21, mountainColor, mountainBGColor);
  	init_pair(22, forestColor, forestBGColor);
  	init_pair(23, oceanColor, oceanBGColor);
  	init_pair(24, riverColor, riverBGColor);

		char city_roadLayer[500][500];
		char unitLayer[500][500];
		int colorCity_Road[500][500];
		int colorUnits[500][500];
		string line;
		int num_of_turns = 1;
		while(1) {
			getline(actionList, line);
			if (actionList.eof()) break;
			stringstream linestream(line);
			char action;
			int turn, layer, x, y, newX, newY, color;
			string object;
			linestream >> action;
			switch (action) {
				case 'M':
					linestream >> x >> y >> newX >> newY;
					unitLayer[newX][newY] = unitLayer[x][y];
					unitLayer[x][y] = 'Q';
					colorUnits[newX][newY] = colorUnits[x][y];
					colorUnits[x][y] = 0;
					break;
				case 'L':
					linestream >> layer >> x >> y >> color;
					if (layer == 1) {
						colorCity_Road[x][y] = color;
					} else if (layer == 2) {
						colorUnits[x][y] = color;
					} else {
						cerr<<"printmap: error in coloring"<<endl;
					}
					break;
				case 'C':
					linestream >> layer >> x >> y >> color >> object;
					if (layer == 1) {
						if (object == "city")
							city_roadLayer[x][y] = 'C';
						else if (object == "road")
							city_roadLayer[x][y] = 'R';
						colorCity_Road[x][y] = color;
					} else if (layer == 2) {
						unitLayer[x][y] = 'U';
						colorUnits[x][y] = color;
					} else {
						cerr<<"printmap: error in creating"<<endl;
					}
					break;
				case 'D':
					linestream >> layer >> x >> y;
					if (layer == 1) {
						city_roadLayer[x][y] = 'Q';
						colorCity_Road[x][y] = 0;
					} else if (layer == 2) {
						unitLayer[x][y] = 'Q';
						colorUnits[x][y] = 0;
					} else {
						cerr<<"printmap: error in destroying"<<endl;
					}
					break;
				default:
					ifstream mapBase("./map");
					if (!mapBase.is_open()) {
						cerr<<"printmap: map not opening"<<endl;
						break;
					}

					y = 0;
					while(1) {
						getline(mapBase, line);
						x = 0;
						if(mapBase.eof()) break;
						stringstream linestream(line);
						char temp;
						while (linestream >> temp) {
							move(x,y);
							if (unitLayer[x][y] && (unitLayer[x][y] != 'Q')) {
								colorObject(unitLayer[x][y], colorUnits[x][y], temp);
								refresh();
							} else if (city_roadLayer[x][y] && (city_roadLayer[x][y] != 'Q')) {
								colorObject(city_roadLayer[x][y], colorCity_Road[x][y], temp);
								refresh();
							} else {
								colorText(temp);
								refresh();
							}
							x++;
						}
						y++;
					}
					mapBase.close();
					usleep(2000000);
					break;
			}
		}

		return 0;
}
