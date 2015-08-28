#ifndef FRAMEQUEUE_H
#define FRAMEQUEUE_H

#include <ctime>
#include <queue>

#include "frame.h"

class frameQueue
{
public:
    frameQueue();
    void scroll(int score, bool meteo);
    bool colCheck(sf::RectangleShape birdy , bool meteo);
    frame curObs()
    {
        return current;
    }
    frame nextObs()
    {
        return cycle.front();
    }
    bool passed()
    {
        return scored;
    }
    virtual ~frameQueue();
protected:
private:
    frame current;
    bool scored;
    void shuffle(int passed);
    float xshift;
    //queue<int>::at()
    queue<frame> cycle;
};

#endif // FRAMEQUEUE_H
