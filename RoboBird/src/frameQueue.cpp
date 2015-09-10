#include <iostream>
#include "frameQueue.h"

frameQueue::frameQueue()
{
    xshift = 0;
    pattern = 32334234243423;
    double bitsy = pattern/(pow(10.0,14.0));
    //18 predefined
    int val = 0;
    while(val < 14){
     bitsy*=10;
    int esti = (int)(floor(bitsy));
    cout << esti - 1 << endl;

     cout << "this is bitsy " << bitsy << endl;
     cout << "this is etsi " << esti << endl;
      if (esti > 4){
       exit(-1);
    }
    egress.push_back(esti - 1);
    bitsy -= esti;
    val++;
    }
    current = frame(0);
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
    cout << " all good with q construct" << endl;
    scored = false;
    //ctor
}
void frameQueue::reset(){

  for(int i = 0; i < cycle.size(); i++){
    cycle.pop();
  }
 current = frame(0);
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
    cout << "reset cycle new size.." << cycle.size() << endl;
    scored = false;
xshift = 0;


}
frameQueue::~frameQueue()
{
    //dtor
}

bool frameQueue::colCheck(sf::RectangleShape birdy, bool meteo)
{
    if(!meteo)
    {
         bool midway = false;
        for(int i = 0; i < current.pipeNum; i++)
        {
            sf::Vector2f player = birdy.getPosition();
            sf::Vector2f obstacle = current.Pipes[i].getPosition();
            // +12.5
            if(player.x + 38 >= obstacle.x  && player.x + 20 <= obstacle.x + 60 && ( (player.y + 15 > obstacle.y && player.y + 18 < (obstacle.y + current.Pipes[i].getSize().y)) || (player.y - 5 < - 60)) )
            {
                return true;
            }
            if( !scored && player.x >= obstacle.x + 90 && player.x <= obstacle.x + 100)
            {
                scored = true;
                midway = true;
            }

        }
        if(!midway){
            scored = false;
        }
        for(int i = 0; i < 2; i++){
         sf::Vector2f playerg = birdy.getPosition();
            sf::Vector2f obstacleg = cycle.front().Pipes[i].getPosition();
            // +12.5
            if(playerg.x + 38 >= obstacleg.x  && playerg.x + 20 <= obstacleg.x + 60 && ( (playerg.y + 15 > obstacleg.y && playerg.y + 18 < (obstacleg.y + cycle.front().Pipes[i].getSize().y)) || (playerg.y - 5 < - 60)) )
            {
                return true;
            }
        }

    }
    else
    {
        sf::Vector2f player = birdy.getPosition();
            bool midway = false;
        for(int i = 0; i < current.pipeNum; i++)
        {
              sf::Vector2f obstacle = current.Pipes[i].getPosition();
            if( !scored && player.x >= obstacle.x + 90 && player.x <= obstacle.x + 100 )
            {
                scored = true;
                midway = true;
            }

        }
        if(!midway){
            scored = false;
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
        //srand(time(0));
        xshift = 0;
        //int value = rand() % 3 + 1;
        int value  = egress.at(passed % 14);
        if(value > 3 || value < 1){
            cout << passed % 18 << " location in egress is " << value << " error";
            exit(-1);
        }
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
