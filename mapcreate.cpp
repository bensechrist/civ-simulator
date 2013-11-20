#include <cstdlib>
#include <iostream>
#include "terraincreator.h"

using namespace std;

#define helpParam 0     //Indicate -h parameter was used
#define usageError 1    //Indicate the program was called incorrectly

void printHelpMessage(int coutType);

int main(int argc,char* argv[])
{
    //Constants to be read in from config file
    const char fillChar = '~';
    const char landChar = '.';
    const unsigned int agentNum = 5;
    //const double burnout = 0.5;
    const unsigned int agentMaxLife = 100;


    //



    int paramFlag = 0;  //Value to be incrementmented upon encountering a parameter flag

    if(argc > 3)    //Check for more than 3 arguments (implies a parameter flag)
    {
        if((argv[1][0] == '-')&&(argv[1][1] == 'h'))
        {
            printHelpMessage(helpParam);
            return 0;
        }
        else
        {
            printHelpMessage(usageError);
            return 1;
        }
    }
    else if(argc == 2)  //Check for 2 arguments (implies only a single parameter flag was used after the program call)
    {
        if((argv[1][0] == '-')&&(argv[1][1] == 'h'))
        {
            printHelpMessage(helpParam);
            return 0;
        }
        else
        {
            printHelpMessage(usageError);
            return 1;
        }

    }
    else if(argc != 3)  //Check for "non-vanilla" program call
    {
        printHelpMessage(usageError);
        return 1;
    }


    unsigned int xSize = atoi(argv[1 + paramFlag]);  //Read in the x-size of the map
    unsigned int ySize = atoi(argv[2 + paramFlag]);  //Read in the y-size of the map

    //cout << endl << "xSize = " << xSize;
    //cout << endl << "ySize = " << ySize;

    //char map[(xSize+1)*(ySize+1)];

    terrainCreator map(xSize, ySize);
    map.fillMap(fillChar);
    map.createFeature(agentNum, landChar, fillChar, agentMaxLife);




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
    }
    else
    {
        cerr << "Usage: mapcreate [OPTION] <integer-x-dimension> <integer-y-dimension>." << endl << endl;
        cerr << "Options:" << endl;
        cerr << "-h     display this help message" << endl;
    }
}



