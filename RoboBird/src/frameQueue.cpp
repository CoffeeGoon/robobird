#include <iostream>
#include "frameQueue.h"

frameQueue::frameQueue()
{
    xshift = 0;
    current = frame(1);
    current.shift(0);
    // cycle.push_back(tokA);
    frame tokB(2);
    tokB.shift(600);
    cycle.push(tokB);
    frame tokC(3);
    cycle.push(tokC);
    frame tokD(2);
    cycle.push(tokD);
    frame tokE(2);
    cycle.push(tokE);
    frame tokF(1);
    cycle.push(tokF);
    frame tokG(1);
    cycle.push(tokG);
    frame tokH(1);
    cycle.push(tokH);
    frame tokI(1);
    cycle.push(tokI);
    frame tokJ(3);
    cycle.push(tokJ);
    scored = false;
    //ctor
}

frameQueue::~frameQueue()
{
    //dtor
}

bool frameQueue::colCheck(sf::RectangleShape birdy, bool meteo)
{
    if(!meteo)
    {
        for(int i = 0; i < current.pipeNum; i++)
        {
            sf::Vector2f player = birdy.getPosition();
            sf::Vector2f obstacle = current.Pipes[i].getPosition();
            if(player.x + 12.5 >= obstacle.x && player.x + 12.5 <= obstacle.x + 60 && player.y - 5 > obstacle.y && player.y + 5 < (obstacle.y + current.Pipes[i].getSize().y))
            {
                return true;
            }
            if(current.pipeNum == 2 && !scored && player.x >= obstacle.x + 90)
            {
                scored = true;
            }
        }

    }
    else
    {
        sf::Vector2f player = birdy.getPosition();

        for(int i = 0; i < current.pipeNum; i++)
        {
              sf::Vector2f obstacle = current.Pipes[i].getPosition();
            if(current.pipeNum == 2 && !scored && player.x >= obstacle.x + 90)
            {
                scored = true;
            }
        }
    }
    if(birdy.getPosition().y > 370){
        return true;
    }
    return false;
}
//constant frame x coordinate shifting function
void frameQueue::scroll( int score, bool meteo)
{
    if(xshift > -600)
    {
        xshift--;
        current.background.move(-1, 0);
        current.floor.move(-1, 0);
        for(int i = 0; i < current.pipeNum; i++)
        {
            current.Pipes[i].move(-1, 0);
        }
        cycle.front().background.move(-1, 0);
        cycle.front().floor.move(-1, 0);
        for(int i = 0; i < cycle.front().pipeNum; i++)
        {
            cycle.front().Pipes[i].move(-1, 0);
        }
        //change scenerey
        if(meteo) {}
    }
    else
    {

        shuffle(score);

    }



}

void frameQueue::shuffle(int passed)
{

    if(passed < 100)
    {
        srand(time(0));
        xshift = 0;
        int value = rand() % 3 + 1;
       cout << "this is the new frame " << value << "this is the size of the queue " << cycle.size() <<  endl;
        frame temp(value);
        current = cycle.front();
        cycle.pop();
        scored = false;
        int relx = (current.background.getPosition().x) + 600;
        cycle.front().shift(relx);
        cycle.push(temp);
    }

}
