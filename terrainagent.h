


class terrainAgent
{
public:
    terrainAgent(unsigned int x,unsigned int y);
    ~terrainAgent();

    void fillMap();

    char* printMap();

private:
    char* m_map;                //Hold the map plus newlines on the edge
    unsigned int m_map_x;       //Hold the map's x dimension
    unsigned int m_map_y;       //Hold the map's y dimension
    char m_fillChar;            //Hold the fill character for the initial map
};

