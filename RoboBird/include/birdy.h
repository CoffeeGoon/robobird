#ifndef BIRDY_H
#define BIRDY_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
class birdy
{
friend class controller;
public:
    birdy();
    virtual ~birdy();
    void update(bool jerk);
    void activate()
    {
        meteo = true;
    }
    bool getPow()
    {
        return meteo;
    }
    void setPos(double x, double y);

    sf::RectangleShape getImg()
    {
        return picture;
    }
protected:
private:
    sf::Texture* gliding;
    sf::Texture* fireball;
    bool meteo;
    double ay;
    double x;
    double vy;
    double y;
    sf::RectangleShape picture;

};

#endif // BIRDY_H
