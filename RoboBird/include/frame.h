#ifndef FRAME_H
#define FRAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
class frame
{
    friend class frameQueue;
public:
    frame();
    frame(int n);
    virtual ~frame();
    sf::RectangleShape getBk()
    {
        return background;
    }
    sf::RectangleShape* getPipes()
    {
        return Pipes;
    }
    sf::RectangleShape getFloor()
    {
        return floor;
    }
    int len()
    {
        return pipeNum;
    }
    bool getDe()
    {
        return destroyed;
    }
    sf::RectangleShape Gfloor()
    {
        return floor;
    }
    void boom()
    {
        destroyed = true;
    }
protected:

private:
    void shift(int dx);
    int type;
    int pipeNum;
    int x;
    int y;
    bool destroyed;
    sf::RectangleShape background;
    sf::RectangleShape* Pipes;
    sf::RectangleShape floor;
};

#endif // FRAME_H
