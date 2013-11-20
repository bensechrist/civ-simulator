


class terrainCreator
{
public:
    terrainCreator(unsigned int x,unsigned int y);
    ~terrainCreator();

    void fillMap(char fillChar);

    void createLandmass();


    char* printMap();

private:
    char* m_map;                //Hold the map plus newlines on the edge
    unsigned int m_map_x;       //Hold the map's x dimension
    unsigned int m_map_y;       //Hold the map's y dimension
    char m_fillChar;            //Hold the fill character for the initial map

    char m_landChar;

};

