#include "frame.h"

frame::frame()
{
    //ctor
}
frame::frame(int n)
{
    destroyed = false;
    x = -5400;
    y = 0;

    //textures






//frame 400x400
    background = sf::RectangleShape(sf::Vector2f(600, 360));
   // background.setFillColor(sf::Color::Blue);
    //background.setTexture(&bk);
    //background.setTextureRect( sf::IntRect(10,10, 600, 515) );
    background.setPosition(x, y);
    floor = sf::RectangleShape( sf::Vector2f(600, 40) );
    //floor.setTexture( &floorpipe );
    //floor.setTextureRect( sf::IntRect(10,10, 600,112) );
    //floor.setFillColor( sf::Color::White );
    floor.setPosition( x, 360 );

    /*
    types of pipes
    0: no pipe
    1: mid pipe
    2: high pipe
    3: low pipe
    */

switch(n)
    {
        case 1:
            Pipes = new sf::RectangleShape[2];
            Pipes[0] = sf::RectangleShape(sf::Vector2f(60, 130));
            Pipes[1] = sf::RectangleShape(sf::Vector2f(60, 180));
            Pipes[0].setPosition(300, 0);
            Pipes[1].setPosition(300, 220);
           // Pipes[0].setFillColor(sf::Color::Green);
            //Pipes[1].setFillColor(sf::Color::Green);
            pipeNum = 2;
            break;
        case 2:
            Pipes = new sf::RectangleShape[2];
            Pipes[0] = sf::RectangleShape( sf::Vector2f(60, 70) );
            Pipes[1] = sf::RectangleShape( sf::Vector2f(60, 240) );
            Pipes[0].setPosition(300, 0);
            Pipes[1].setPosition(300, 160);
           // Pipes[0].setFillColor(sf::Color::Green);
            //Pipes[1].setFillColor(sf::Color::Green);
            pipeNum = 2;
            break;
        case 3:
            Pipes = new sf::RectangleShape[2];
            Pipes[0] = sf::RectangleShape(sf::Vector2f(60, 190));
            Pipes[1] = sf::RectangleShape(sf::Vector2f(60, 120));
            Pipes[0].setPosition(300, 0);
            Pipes[1].setPosition(300 , 280);
            //Pipes[0].setFillColor(sf::Color::Green);
            //Pipes[1].setFillColor(sf::Color::Green);

            pipeNum = 2;
            break;
Default:
            type = 0;
            pipeNum = 0;
            break;
        };





}
void frame::shift(int dx)
{
    x = dx;
    background.setPosition(dx, 0);
    floor.setPosition(dx, 360);
    for(int i = 0; i < pipeNum; i++)
    {
        sf::Vector2f pos = Pipes[i].getPosition();
        Pipes[i].setPosition(pos.x + dx, pos.y);
    }
}

frame::~frame()
{
    //dtor
}
