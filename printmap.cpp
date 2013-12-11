#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// Global Variables
char landChar, mountainChar, forestChar, oceanChar, riverChar;
int landColor, mountainColor, forestColor, oceanColor, riverColor;
int landBGColor, mountainBGColor, forestBGColor, oceanBGColor, riverBGColor;

void colorText(char input) {	
	if (input == landChar) {
		cout<<"\033[0;"<<landColor<<";"<<landBGColor<<"m"<<input<<"\033[0m";
	} else if (input == mountainChar) {
		cout<<"\033[0;"<<mountainColor<<";"<<mountainBGColor<<"m"<<input<<"\033[0m";
	} else if (input == forestChar) {
		cout<<"\033[0;"<<forestColor<<";"<<forestBGColor<<"m"<<input<<"\033[0m";
	} else if (input == oceanChar) {
		cout<<"\033[0;"<<oceanColor<<";"<<oceanBGColor<<"m"<<input<<"\033[0m";
	} else if (input == riverChar) {
		cout<<"\033[0;"<<riverColor<<";"<<riverBGColor<<"m"<<input<<"\033[0m";
	} else {
		cout<<"?";
	}
}

void colorObject(char input, int color) {
	cout<<"\033[0;"<<color<<"m"<<input<<"\033[0m";
}

int main(int argc, char ** argv) {
	ifstream mapBase("./map");
	ifstream config("./config");
	ifstream actionList("./action_list.txt");
	
	if (config.fail() || mapBase.fail() || actionList.fail()) {
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

        if(lineLocation >= 0)
        {
            lineLocation = line.find_first_of(39);   //look for apostrophe
            lineEnd = line.find_last_of(39);
            istringstream tempStream(line.substr(lineLocation+1, lineEnd-lineLocation-1));
            switch(i)
            {
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
				cout<<num_of_turns++<<endl;

				mapBase.clear();
				
				y = 0;
				while(1) {
					getline(mapBase, line);
					x = 0;
					y++;
					if(mapBase.eof()) break;
					stringstream linestream(line);
					char temp;
					while (linestream >> temp) {
						x++;
						if (unitLayer[x][y] && (unitLayer[x][y] != 'Q')) {
							colorObject(unitLayer[x][y], colorUnits[x][y]);
						} else if (city_roadLayer[x][y] && (city_roadLayer[x][y] != 'Q')) {
							colorObject(city_roadLayer[x][y], colorCity_Road[x][y]);
						} else {
							colorText(temp);
						}
					}
					cout<<endl;
				}
				break;
		}
	}
	
	return 0;
}
