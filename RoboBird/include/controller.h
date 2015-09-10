
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "frame.h"
#include "frameQueue.h"
#include "birdy.h"

class controller
{
public:
    controller();
    void threadTask(int button);
    void activate(bool zoom){ scorched = zoom;}
    int getPhase(){ return phase;}
    int getScore()
    {
        return passed;
    }
    vector<sf::Sprite> terrain();
    virtual ~controller();
protected:

private:
    sf::Sprite getFrame();
    sf::Texture downpipe;
    sf::Texture uppipe;
    sf::Texture auppipe;
    sf::Texture adownpipe;
    sf::Texture floorpipe;
    sf::Texture bk;
    sf::Texture birdo;
    sf::Texture ground;
    sf::Texture fb;
    sf::Texture title;
    sf::Texture info;
    sf::Texture vapI;
    sf::Texture vapII;
    sf::Texture vapIII;
    int passed;
    int phase;
    int delay;
    bool seal;
    bool scorched;
    frameQueue assembly;
    birdy player;

};

#endif // CONTROLLER_H
