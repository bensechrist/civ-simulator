#include "terraincreator.h"

//Function:
//     terrainCreator (constructor)
//
//Description:
//      Initializes map creation data and creates a blank map
//
//Preconditions:
//      Config file exists (future addition)
//
//Arguments:
//      unsigned int x - longways map dimension
//      unsigned int y - heightways map dimension
//
//Postconditions:
//      Blank map is created and creaton variables initialized
//
//Returns:
//      None
//
terrainCreator::terrainCreator(unsigned int x,unsigned int y)
{
    m_map_x = x;
    m_map_y = y;
    m_map = new char[((m_map_x+1)*m_map_y)+1];
}

//Function:
//     terrainCreator (destructor)
//
//Description:
//      Deletes map allocated with 'new'
//
//Preconditions:
//      Constructor was called
//
//Arguments:
//      None
//
//Postconditions:
//      Memory free, no leaks
//
//Returns:
//      None
//
terrainCreator::~terrainCreator()
{
    delete [] m_map;
}

//Function:
//     fillMap
//
//Description:
//      Fills the map with the arguement fillChar and inserts newlines at the end iof each row.
//      Also inserts a NULL character at the end of the map array
//
//Preconditions:
//      Constructor was called, map array was created and exists
//
//Arguments:
//      char fillChar - character to fill map with
//
//Postconditions:
//      Map array is full of fill character
//
//Returns:
//      None
//
void terrainCreator::fillMap(char fillChar)
{
    unsigned int mapSize = ((m_map_x+1)*m_map_y);

    for(int i = 0; i < mapSize;i++)   //Fill map with fill character
    {
        m_map[i] = fillChar;
    }
    for(int j = m_map_x; j < mapSize; (j = j + m_map_x + 1))
    {
        m_map[j] = '\n';
    }

    m_map[mapSize] = '\0';
}

void createLandmass()
{

}

//Function:
//     printMap
//
//Description:
//      Returns pointer to map array
//
//Preconditions:
//      Constructor was called, map array was created and exists
//
//Arguments:
//      None
//
//Postconditions:
//      None
//
//Returns:
//      Pointer to map array
//
char* terrainCreator::printMap()
{
    return m_map;
}

