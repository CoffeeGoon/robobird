
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
    int getScore()
    {
        return passed;
    }
    vector<sf::Sprite> terrain();
    virtual ~controller();
protected:

private:
    sf::Texture downpipe;
    sf::Texture uppipe;
    sf::Texture floorpipe;
    sf::Texture bk;
    sf::Texture ground;
    sf::Texture fb;
    int passed;
    bool seal;
    frameQueue assembly;
    birdy player;

};

#endif // CONTROLLER_H
