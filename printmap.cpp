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
int player1Color, player2Color;
char landChar, mountainChar, forestChar, oceanChar, riverChar;
int landColor, mountainColor, forestColor, oceanColor, riverColor;
int landBGColor, mountainBGColor, forestBGColor, oceanBGColor, riverBGColor;
char soundEnable;

void colorText(char input) {
	if (input == landChar) {
		attron(COLOR_PAIR(50));
		addch(input);
		attroff(COLOR_PAIR(50));
	} else if (input == mountainChar) {
		attron(COLOR_PAIR(51));
		addch(input);
		attroff(COLOR_PAIR(51));
	} else if (input == forestChar) {
		attron(COLOR_PAIR(52));
		addch(input);
		attroff(COLOR_PAIR(52));
	} else if (input == oceanChar) {
		attron(COLOR_PAIR(53));
		addch(input);
		attroff(COLOR_PAIR(53));
	} else if (input == riverChar) {
		attron(COLOR_PAIR(54));
		addch(input);
		attroff(COLOR_PAIR(54));
	} else {
		cout<<"?";
	}
}

void colorObject(char input, int color, char BGChar) {
	if (BGChar == mountainChar) {
		color += 10;
	} else if (BGChar == forestChar) {
		color += 20;
	} else if (BGChar == oceanChar) {
		color += 30;
	} else if (BGChar == riverChar) {
		color += 40;
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
    
	if (config.fail() || actionList.fail()) {
		cerr << "printmap: failed to open map, actionlist, or config file"<<endl;
	}
	
	string configParams[18] = {
		"player1_color",
		"player2_color",
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
		"river_BG_color",
        "sound_enable"
    };
	
	for (int i = 0; i < 18;i++) {
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
                    tempStream >> player1Color;
                    break;
                case 1:
                    tempStream >> player2Color;
                    break;
                case 2:
                    tempStream >> landChar;
                    break;
                case 3:
                    tempStream >> landColor;
                    break;
                case 4:
                    tempStream >> landBGColor;
                    break;
                case 5:
                    tempStream >> mountainChar;
                    break;
                case 6:
                    tempStream >> mountainColor;
                    break;
                case 7:
                    tempStream >> mountainBGColor;
                    break;
                case 8:
                    tempStream >> forestChar;
                    break;
                case 9:
                    tempStream >> forestColor;
                    break;
                case 10:
                    tempStream >> forestBGColor;
                    break;
                case 11:
                    tempStream >> oceanChar;
                    break;
                case 12:
                    tempStream >> oceanColor;
                    break;
                case 13:
                    tempStream >> oceanBGColor;
                    break;
                case 14:
                    tempStream >> riverChar;
                    break;
                case 15:
                    tempStream >> riverColor;
                    break;
                case 16:
                    tempStream >> riverBGColor;
                    break;
                case 17:
                    tempStream >> soundEnable;
                    break;
                default:
                    cerr << "MapCreate: Error: Something went wrong while parsing.";
            }
        } else i--;
    }
  	
  	init_pair(0, COLOR_BLACK, landBGColor);
    init_pair(1, COLOR_RED, landBGColor);
    init_pair(2, COLOR_GREEN, landBGColor);
    init_pair(3, COLOR_YELLOW, landBGColor);
    init_pair(4, COLOR_BLUE, landBGColor);
    init_pair(5, COLOR_MAGENTA, landBGColor);
    init_pair(6, COLOR_CYAN, landBGColor);
    init_pair(7, COLOR_WHITE, landBGColor);
    
    init_pair(10, COLOR_BLACK, mountainBGColor);
    init_pair(11, COLOR_RED, mountainBGColor);
    init_pair(12, COLOR_GREEN, mountainBGColor);
    init_pair(13, COLOR_YELLOW, mountainBGColor);
    init_pair(14, COLOR_BLUE, mountainBGColor);
    init_pair(15, COLOR_MAGENTA, mountainBGColor);
    init_pair(16, COLOR_CYAN, mountainBGColor);
    init_pair(17, COLOR_WHITE, mountainBGColor);
    
    init_pair(20, COLOR_BLACK, forestBGColor);
    init_pair(21, COLOR_RED, forestBGColor);
    init_pair(22, COLOR_GREEN, forestBGColor);
    init_pair(23, COLOR_YELLOW, forestBGColor);
    init_pair(24, COLOR_BLUE, forestBGColor);
    init_pair(25, COLOR_MAGENTA, forestBGColor);
    init_pair(26, COLOR_CYAN, forestBGColor);
    init_pair(27, COLOR_WHITE, forestBGColor);
    
    init_pair(30, COLOR_BLACK, oceanBGColor);
    init_pair(31, COLOR_RED, oceanBGColor);
    init_pair(32, COLOR_GREEN, oceanBGColor);
    init_pair(33, COLOR_YELLOW, oceanBGColor);
    init_pair(34, COLOR_BLUE, oceanBGColor);
    init_pair(35, COLOR_MAGENTA, oceanBGColor);
    init_pair(36, COLOR_CYAN, oceanBGColor);
    init_pair(37, COLOR_WHITE, oceanBGColor);
    
    init_pair(40, COLOR_BLACK, riverBGColor);
    init_pair(41, COLOR_RED, riverBGColor);
    init_pair(42, COLOR_GREEN, riverBGColor);
    init_pair(43, COLOR_YELLOW, riverBGColor);
    init_pair(44, COLOR_BLUE, riverBGColor);
    init_pair(45, COLOR_MAGENTA, riverBGColor);
    init_pair(46, COLOR_CYAN, riverBGColor);
    init_pair(47, COLOR_WHITE, riverBGColor);
    
    init_pair(50, landColor, landBGColor);
  	init_pair(51, mountainColor, mountainBGColor);
  	init_pair(52, forestColor, forestBGColor);
  	init_pair(53, oceanColor, oceanBGColor);
  	init_pair(54, riverColor, riverBGColor);
  	
  	init_pair(100, COLOR_BLACK, COLOR_WHITE);
  	init_pair(101, COLOR_RED, COLOR_WHITE);
  	init_pair(102, COLOR_GREEN, COLOR_WHITE);
  	init_pair(103, COLOR_YELLOW, COLOR_WHITE);
  	init_pair(104, COLOR_BLUE, COLOR_WHITE);
  	init_pair(105, COLOR_MAGENTA, COLOR_WHITE);
  	init_pair(106, COLOR_CYAN, COLOR_WHITE);
  	init_pair(107, COLOR_WHITE, COLOR_BLACK);
    
    char city_roadLayer[500][500];
    char unitLayer[500][500];
    int colorCity_Road[500][500];
    int colorUnits[500][500];
    int numCitiesP1 = 0;
    int numCitiesP2 = 0;
    int numRoadsP1 = 0;
    int numRoadsP2 = 0;
    int numUnitsP1 = 0;
    int numUnitsP2 = 0;
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
                    if (city_roadLayer[x][y] == 'R') {
                        if (colorCity_Road[x][y] == player1Color) {
                            numRoadsP1--;
                            numRoadsP2++;
                        } else if (colorCity_Road[x][y] == player2Color) {
                            numRoadsP2--;
                            numRoadsP1++;
                        }
                    } else if (city_roadLayer[x][y] == 'C') {
                        if (colorCity_Road[x][y] == player1Color) {
                            numCitiesP1--;
                            numCitiesP2++;
                        } else if (colorCity_Road[x][y] == player2Color) {
                            numCitiesP2--;
                            numCitiesP1++;
                        }
                    }
                    colorCity_Road[x][y] = color;
                } else if (layer == 2) {
                    if (colorUnits[x][y] == player1Color) {
                        numUnitsP1--;
                        numUnitsP2++;
                    } else if (colorUnits[x][y] == player2Color) {
                        numUnitsP2--;
                        numUnitsP1++;
                    }
                    colorUnits[x][y] = color;
                } else {
                    cerr<<"printmap: error in coloring"<<endl;
                }
                break;
            case 'C':
                linestream >> layer >> x >> y >> color >> object;
                if (layer == 1) {
                    if (object == "city") {
                        city_roadLayer[x][y] = 'C';
                        if (color == player1Color)
                            numCitiesP1++;
                        else if (color == player2Color)
                            numCitiesP2++;
                    } else if (object == "road") {
                        city_roadLayer[x][y] = 'R';
                        if (color == player1Color)
                            numRoadsP1++;
                        else if (color == player2Color)
                            numRoadsP2++;
                    }
                    colorCity_Road[x][y] = color;
                } else if (layer == 2) {
                    unitLayer[x][y] = 'U';
                    colorUnits[x][y] = color;
                    if (color == player1Color)
                        numUnitsP1++;
                    else if (color == player2Color)
                        numUnitsP2++;
                } else {
                    cerr<<"printmap: error in creating"<<endl;
                }
                break;
            case 'D':
                linestream >> layer >> x >> y;
                if (layer == 1) {
                    if (city_roadLayer[x][y] == 'R') {
                        if (colorCity_Road[x][y] == player1Color) numRoadsP1--;
                        else if (colorCity_Road[x][y] == player2Color) numRoadsP2--;
                    } else if (city_roadLayer[x][y] == 'C') {
                        if (colorCity_Road[x][y] == player1Color) numCitiesP1--;
                        else if (colorCity_Road[x][y] == player2Color) numCitiesP2--;
                    }
                    city_roadLayer[x][y] = 'Q';
                    colorCity_Road[x][y] = 0;
                } else if (layer == 2) {
                    if (colorUnits[x][y] == player1Color) numUnitsP1--;
                    else if (colorUnits[x][y] == player2Color) numUnitsP2--;
                    unitLayer[x][y] = 'Q';
                    colorUnits[x][y] = 0;
                } else {
                    cerr<<"printmap: error in destroying"<<endl;
                }
                if (soundEnable == 'Y' || soundEnable == 'y') beep();
                break;
            default:
                ifstream mapBase("./map");
                if (!mapBase.is_open()) {
                    cerr<<"printmap: map not opening"<<endl;
                    break;
                }
                
                move(0,0);
                attron(COLOR_PAIR(player1Color+100));
                addstr("Player 1 Cities: ");
                addch((int)(numCitiesP1/100) + '0');
                addch((int)((numCitiesP1%100)/10) + '0');
                addch(((numCitiesP1%100)%10) + '0');
                addstr(" Roads: ");
                addch((int)(numRoadsP1/100) + '0');
                addch((int)((numRoadsP1%100)/10) + '0');
                addch(((numRoadsP1%100)%10) + '0');
                addstr(" Units: ");
                addch((int)(numUnitsP1/100) + '0');
                addch((int)((numUnitsP1%100)/10) + '0');
                addch(((numUnitsP1%100)%10) + '0');
                attroff(COLOR_PAIR(player1Color+100));
                
                attron(COLOR_PAIR(player2Color+100));
                addstr("  Player 2 Cities: ");
                addch((int)(numCitiesP2/100) + '0');
                addch((int)((numCitiesP2%100)/10) + '0');
                addch(((numCitiesP2%100)%10) + '0');
                addstr(" Roads: ");
                addch((int)(numRoadsP2/100) + '0');
                addch((int)((numRoadsP2%100)/10) + '0');
                addch(((numRoadsP2%100)%10) + '0');
                addstr(" Units: ");
                addch((int)(numUnitsP2/100) + '0');
                addch((int)((numUnitsP2%100)/10) + '0');
                addch(((numUnitsP2%100)%10) + '0');
                addch('\n');
                attroff(COLOR_PAIR(player2Color+100));
                
                y = 0;
                while(1) {
                    getline(mapBase, line);
                    x = 0;
                    if(mapBase.eof()) break;
                    stringstream linestream(line);
                    char temp;
                    while (linestream >> temp) {
                        move(y+1,x);
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
    
    endwin();
    
    cout<<"Player 1 [Cities: "<<numCitiesP1<<"][Roads: "<<numRoadsP1<<"][Units: "<<
    numUnitsP1<<"]"<<endl<<"Player 2 [Cities: "<<numCitiesP2<<"][Roads: "<<
    numRoadsP2<<"][Units: "<<numUnitsP2<<"]"<<endl;
    
    return 0;
}
