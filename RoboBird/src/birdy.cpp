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
    gliding = new sf::Texture[6];
    int elm = 0;
    for(int i = 0; i < 2; i++){
     for(int j = 0; j < 3; j++){
        sf::Texture temp;
       if(!temp.loadFromFile("plasmabird.png", sf::IntRect(j * 80, i * 71, 80, 71 ))){
        cout << "VWHHHATTT!!!" << endl;
        exit(-1);
       }

       gliding[elm] = temp;
       elm++;
     }
    }
    //427
    elm = 0;
    fireball = new sf::Texture[9];
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < 4; i++){
            sf::Texture temp;
            temp.loadFromFile("plasmabolt.png", sf::IntRect(i * 100, k * 75, 100, 75 ) );
        fireball[elm] = temp;
         elm++;
        }
    }
    sf::Texture remain;
    remain.loadFromFile("plasmabolt.png", sf::IntRect(0, 150, 100, 75 ));
    fireball[8] = remain;
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
