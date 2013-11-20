


class terrainCreator
{
public:
    terrainCreator(unsigned int x,unsigned int y);
    ~terrainCreator();

    void fillMap(char fillChar);

    void createFeature(unsigned int agentNum, char featureChar, char subChar, unsigned int agentMaxLife, int pattern);
    void terrainAgent(unsigned int location, unsigned int life);
    bool isValidMapLocation(int location);
    bool isValidSubcharLocation(int location);

    char* printMap();

private:


    char* m_map;                //Hold the map plus newlines on the edge
    unsigned int m_map_x;       //Hold the map's x dimension
    unsigned int m_map_y;       //Hold the map's y dimension
    char m_fillChar;            //Hold the fill character for the initial map

    char m_featureChar;         //Hold current character being placed
    char m_subChar;             //Hold current character with which to replace with featureChar
    //double m_burnoutCoef;       //Hold current burnout coeffecient for any Agents created
    unsigned int m_agentMaxLife;
    enum algType{snake, dense} m_pattern;

};

