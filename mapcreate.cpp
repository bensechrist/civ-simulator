#include <cstdlib>
#include <iostream>

using namespace std;

#define helpParam 0     //Indicate -h parameter was used
#define usageError 1    //Indicate the program was called incorrectly

void printHelpMessage(int coutType);


int main(int argc,char* argv[])
{

    if(argc > 3)
    {
        if((argv[1][0] == '-')&&(argv[1][1] == 'h'))
        {
            printHelpMessage(helpParam);
            return 0;
        }
    }
    else if(argc == 2)
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
    else if(argc != 3)
    {
        printHelpMessage(usageError);
        return 1;
    }






}

//  Function:
//      printHelpMessage
//
//  Description:
//      Prints a help message on program parameter errors or -h parameter used
//
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
