#include "terrainagent.h"

terrainAgent::terrainAgent(unsigned int x,unsigned int y)
{
    m_map_x = x;
    m_map_y = y;
    m_map = new char[((m_map_x+1)*m_map_y)+1];
    m_fillChar = '~';
}

terrainAgent::~terrainAgent()
{
    delete [] m_map;
}

void terrainAgent::fillMap()
{
    unsigned int mapSize = ((m_map_x+1)*m_map_y);

    for(int i = 0; i < mapSize;i++)   //Fill map with fill character
    {
        m_map[i] = m_fillChar;
    }
    for(int j = m_map_x; j < mapSize; (j = j + m_map_x + 1))
    {
        m_map[j] = '\n';
    }

    m_map[mapSize] = '\0';
}

char* terrainAgent::printMap()
{
    return m_map;
}
