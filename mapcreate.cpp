#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "terraincreator.h"

using namespace std;

#define helpParam 0     //Indicate -h parameter was used
#define usageError 1    //Indicate the program was called incorrectly

void printHelpMessage(int coutType);
void parseConfig(char* forestChar, char* oceanChar,char* landChar,char* mountainChar,int* landFrequency,int* landAgentNum,int* mountainFrequency,int* mountainAgentNum);


int main(int argc,char* argv[])
{
    //Constants to be read in from config file
/*
    const char oceanChar = '~';
    const char landChar = 'W';
    const char mountainChar = '^';


    const unsigned int landFrequency = 5000;
    const unsigned int landAgentNum = 45;

    const unsigned int mountainFrequency = 10000;
    const unsigned int mountainAgentNum = 500;


    const unsigned int snakePattern = 0;
    const unsigned int densePattern = 1;

    //

*/

    bool readFromStdin = false;



    unsigned int paramFlag = 0;  //Value to be incrementmented upon encountering a parameter flag


    if(argc > 3)    //Check for more than 3 arguments (implies a parameter flag)
    {
        for(int i = 0; i < argc; i++)
        {
            if((argv[i][0] == '-'))
            {
                switch(argv[i][1])
                {
                case 'h':
                    printHelpMessage(helpParam);
                    paramFlag++;
                    return 0;
                    break;
                case 'i':
                    readFromStdin = true;
                    paramFlag++;
                    break;
                default:
                    printHelpMessage(usageError);
                    return 1;
                    break;
                }

            }
            else break;
        }
    }


        char oceanChar;
        char landChar;
        char mountainChar;
        char forestChar;
        int landFrequency;
        int landAgentNum;
        int mountainFrequency;
        int mountainAgentNum;

        if(readFromStdin)
        {
            cin >> oceanChar;
            cin >> landChar;
            cin >> mountainChar;
            cin >> landFrequency;
            cin >> landAgentNum;
            cin >> mountainFrequency;
            cin >> mountainAgentNum;
        }
        else
        {
            parseConfig(&forestChar,&oceanChar,&landChar,&mountainChar,&landFrequency,&landAgentNum,&mountainFrequency,&mountainAgentNum);
        }



    //ifstream configFile(argv[1]);
    unsigned int xSize = atoi(argv[1 + paramFlag]);  //Read in the x-size of the map
    unsigned int ySize = atoi(argv[2 + paramFlag]);  //Read in the y-size of the map

    //cout << endl << "xSize = " << xSize;
    //cout << endl << "ySize = " << ySize;

    //char map[(xSize+1)*(ySize+1)];

    terrainCreator map(xSize, ySize);
    map.fillMap(oceanChar);
    map.createFeature(landAgentNum, landChar, oceanChar, landFrequency);
    map.smoothFeature(landChar, oceanChar);
    map.smoothFeature(landChar, oceanChar);
    map.createFeature(mountainAgentNum,  mountainChar, landChar, mountainFrequency);
    map.smoothFeature(mountainChar, landChar);
    map.createFeature(mountainAgentNum,  forestChar, landChar, mountainFrequency);
    map.smoothFeature(forestChar, landChar);


    cout << map.printMap();


}

//Function:
//      printHelpMessage
//
//Description:
//      Prints a help message on program parameter errors or -h parameter used
//
//Preconditions:
//      Understanding by user of what output stream they want to print to
//
//Arguments:
//      int coutType - flag differntiating between std error and std out for the help message
//
//Postconditions:
//      Help message is printed to the screen
//
//Returns:
//      None
//
void printHelpMessage(int coutType)
{
    if(coutType == 0)
    {
        cout << "Usage: mapcreate [OPTION] <integer-x-dimension> <integer-y-dimension>." << endl << endl;
        cout << "Options:" << endl;
        cout << "-h     display this help message" << endl;
        cout << "-i     read config from stdin" << endl;
    }
    else
    {
        cerr << "Usage: mapcreate [OPTION] <integer-x-dimension> <integer-y-dimension>." << endl << endl;
        cerr << "Options:" << endl;
        cerr << "-h     display this help message" << endl;
        cerr << "-i     read config from stdin" << endl;
    }
}


//Function:
//      parseConfig
//
//Description:
//      Parses input data from the config file
//
//Preconditions:
//      config file exists
//
//Arguments:
//      char* oceanChar,char* landChar,char* mountainChar,int* landFrequency,int* landAgentNum,int* mountainFrequency,int* mountainAgentNum
//
//Postconditions:
//
//
//Returns:
//
//
void parseConfig(char* forestChar, char* oceanChar,char* landChar,char* mountainChar,int* landFrequency,int* landAgentNum,int* mountainFrequency,int* mountainAgentNum)
{
    ifstream configFile ("/home/alex/ece2524/project/civ-simulator/config");

    if(configFile.fail())
    {
        cerr << "MapCreate: Error: Can't find config file.";
    }


    const int numParams = 9;
    string configParams[numParams] =
    {
        "plains_character",
        "mountain_character",
        "forest_character",
        "ocean_character",
        "river_character",
        "landFrequency",
        "landAgentNum",
        "mountainFrequency",
        "mountainAgentNum"
    };

    string line;
    int lineLocation;
    int lineEnd;


    for(int i = 0; i < numParams;i++)
    {
        if(configFile.eof()) break;

        getline(configFile, line);

        lineLocation = line.find(configParams[i]);

        if(lineLocation >= 0)
        {
            lineLocation = line.find_first_of(39);   //look for apostrophe
            lineEnd = line.find_last_of(39);
            istringstream tempStream(line.substr(lineLocation+1, lineEnd-lineLocation-1));
            switch(i)
            {
                case 0:
                    tempStream >> (*landChar);
                    break;
                case 1:
                    tempStream >> (*mountainChar);
                    break;
                case 2:
                    tempStream >> (*forestChar);
                    break;
                case 3:
                    tempStream >> (*oceanChar);
                    break;
                case 4:
                    //river
                    break;
                case 5:
                    tempStream >> (*landFrequency);
                    break;
                case 6:
                    tempStream >> (*landAgentNum);
                    break;
                case 7:
                    tempStream >> (*mountainFrequency);
                    break;
                case 8:
                    tempStream >> (*mountainAgentNum);
                    break;
                default:
                    cerr << "MapCreate: Error: Something went wrong while parsing.";

            }
        }
        else i--;
    }

}


