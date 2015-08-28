#include "birdy.h"

birdy::birdy()
{
    //ctor\


    x = 100;
    vy = 0;
    y = 120;
    ay = 0;
    picture = sf::RectangleShape(sf::Vector2f(25, 25));
    picture.setPosition(x, y);
    picture.setFillColor(sf::Color::Red);
}
void birdy::setPos(double dx, double dy)
{
    y = dy;
    x = dx;
    picture.setPosition(x, y);

}

void birdy::update(bool jerk)
{
    y += vy;

    if(ay <= 2.8 && !jerk)
    {
        ay += .54;
    }
    if(jerk && ay > -2.8)
    {
        ay -= 6.5;
    }

    if(vy < 4 &&  ay >= 0)
    {
        vy += ay;

    }

    if(ay <= 0 && vy > -4)
    {
        vy += ay;
        if(vy - 2 > 0){ vy -= 2;}
    }

    if(meteo) {}

    picture.setPosition(x, y);

}

birdy::~birdy()
{
    //dtor
}
