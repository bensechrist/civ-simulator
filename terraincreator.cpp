#include "terraincreator.h"


using namespace std;

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

//Function:
//     createLandmass
//
//Description:
//      Generates random starting locations for multiple terrain creator agents
//
//Preconditions:
//      Constructor was called, map array was created and exists
//      Filling the map array with mapFill is required
//
//Arguments:
//      unsigned int agentNum - Number of randomly positioned agents, increases likelyhood of higher number of continents
//      char featureChar - Character which represents the feature being applied
//
//Postconditions:
//      Map is filled with
//
//Returns:
//      None
//

void terrainCreator::createFeature(unsigned int agentNum, char featureChar, char subChar, unsigned int agentMaxLife)
{
    m_featureChar = featureChar;
    m_subChar = subChar;
    //m_burnoutCoef = burnout;
    m_agentMaxLife = agentMaxLife;
    //m_pattern = (algType)pattern;


    srand(time(NULL));//Initialize random seed

    unsigned int rand_location;

    for(int i = 0; i < agentNum; i++)
    {

        do
        {
            rand_location = rand() % ((m_map_x+1)*(m_map_y));   //Generate random map location
        }
        while( /*( (rand_location % m_map_x) == 0 ) ||*/ ( m_map[rand_location] != m_subChar ) );                //Retry if encountering an edge (newline location)

        terrainAgent(rand_location, (rand() % m_agentMaxLife));

    }

}

//Function:
//     smoothFeature
//
//Description:
//
//
//Preconditions:
//
//
//Arguments:
//
//
//Postconditions:
//
//
//Returns:
//      None
//
void terrainCreator::smoothFeature(char featureChar, char subChar)
{
    m_subChar = subChar;

    int weight = 0;

    for(int i = 0;i < ((m_map_x+1)*m_map_y);i++)
    {
        if(!isValidSubcharLocation(m_map[i])) continue;

        if( isValidMapLocation( i+1 ) )//look at east
        {
            if(m_map[i+1] == featureChar)
            {
                weight++;
            }
        }

        if( isValidMapLocation( i-m_map_x-1 ) )//look at north
        {
            if(m_map[i-m_map_x-1] == featureChar)
            {
                weight++;
            }
        }

        if( isValidMapLocation( i-1 ) )//look at west
        {
            if(m_map[i-1] == featureChar)
            {
                weight++;
            }
        }

        if( isValidMapLocation( i+m_map_x+1 ) )//look at south
        {
            if(m_map[i+m_map_x+1] == featureChar)
            {
                weight++;
            }
        }

        if(((rand() % 5) + 1) < weight)
        {
            m_map[i] == featureChar;
        }


    }
}

//Function:
//     terrainAgent
//
//Description:
//      Recursive algorithm to make "somewhat" random and hopefully realistic landmasses
//
//Preconditions:
//      Constructor was called, map array was created and exists.
//      Filling the map array with mapFill is required.
//      Calling createFeature before calling this function is required.
//      Argument location must not be an edge (newline) or end (NULL) of the map array
//      Argument location should be occupied by a character equivalent to m_subChar
//
//Arguments:
//      unsigned int location - starting location on map array
//
//Postconditions:
//      m_featureChar character will be added to the map over top of m_subChar in select locations
//
//Returns:
//      None
//

void terrainCreator::terrainAgent(unsigned int location, unsigned int life)
{

    //cout << endl << "life = " << life;

    if(life <= 0)return;

    //cerr << endl << "location = " << location;

    m_map[location] = m_featureChar;


    unsigned int compass[4] =
    {
        (location + 1),
        (location - m_map_x - 1),
        (location - 1),
        (location + m_map_x + 1)
    };

    int randDirection;
    int counter = 0;

    randDirection = rand() % 4;

    while( 1 )
    {
        if( isValidMapLocation(compass[randDirection]) )
        {
            if(isValidSubcharLocation(randDirection))
            {
                break;
            }
        }
        counter++;
        randDirection = rand() % 4;
        if(counter > 25) return;
    }

    terrainAgent(compass[randDirection], (--life));
}



//Function:
//     isValidMapLocation
//
//Description:
//      Checks to see if parameter location is on the map (not outside the array or on an endline or NULL)
//
//Preconditions:
//      Constructor was called, map array was created and exists.
//
//Arguments:
//      unsigned int location - map array location to check validity
//
//Postconditions:
//      None
//
//Returns:
//      Boolean indicating whether the parameter location is a valid map array location
//
bool terrainCreator::isValidMapLocation(int location)
{
    if(location < 0) return false;
    if(location >= ((m_map_x + 1)*(m_map_y)) - 1) return false;
    if(m_map[location] == '\n')return false;

    //cout << "char at location = " << m_map[location];

    return true;
}

//Function:
//      isValidSubcharLocation
//
//Description:
//      Checks to see iff parameter location is what is stored in subChar
//
//Preconditions:
//      Constructor was called, map array was created and exists.
//      Location must be a valid map array index.
//
//Arguments:
//      unsigned int location - map array location to check validity
//
//Postconditions:
//
//
//Returns:
//
//
bool terrainCreator::isValidSubcharLocation(int location)
{
    if(m_map[location] == m_subChar) return true;
    else return false;
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


//Function:
//
//
//Description:
//
//
//Preconditions:
//
//
//Arguments:
//
//
//Postconditions:
//
//
//Returns:
//
//

