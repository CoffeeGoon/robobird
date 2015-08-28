
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
#include "frame.h";
#include "birdy.h";
#include "frameQueue.h";
#include "controller.h";


using namespace std;

int main()
{
    sf::RenderWindow game(sf::VideoMode(400,460), "Plasma Bird");
    controller gameThread = controller();
    sf::Text pipesPassed;
    sf::Font lett;
    lett.loadFromFile("Airstream.ttf");
    pipesPassed.setFont(lett);
    pipesPassed.setColor(sf::Color(255, 255, 255));
    pipesPassed.setString("0");
    int button = 0;
    bool tap = false;
    while(game.isOpen())
    {
        sf::Event event;
        while(game.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                game.close();
            }
           if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                tap = false;
              }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&!tap)
            {
                button = 1;
                    tap = true;
            }


        }
        gameThread.threadTask(button);
         button = 0;
        game.clear();
        vector<sf::Sprite> temp = gameThread.terrain();
        for(int i = 0; i < temp.size(); i++)
        {
           // cout << "good " << i << endl;
            game.draw(temp[i]);
        }
        //added might create dangling pointers
        temp.clear();
        //****
        int progress = gameThread.getScore();
        stringstream str;
        str << progress;
        sf::RectangleShape grs(sf::Vector2f(420.0, 100.0));
        grs.setFillColor(sf::Color::Black);
        grs.setPosition(0, 410);
        game.draw(grs);
        pipesPassed.setString(str.str());
        pipesPassed.setCharacterSize(50);
        pipesPassed.setPosition(170, 405);
        game.draw(pipesPassed);
        sf::sleep(sf::milliseconds(30));
        game.display();
    }

    return 0;
}
