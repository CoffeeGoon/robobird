
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
    sf::Text intro;
    sf::Text gameover;
    sf::Text pipesPassed;
    sf::Font lett;
    lett.loadFromFile("Airstream.ttf");
    pipesPassed.setFont(lett);
    gameover.setFont(lett);
    intro.setFont(lett);
    gameover.setColor(sf::Color(0,0,0));
    intro.setColor(sf::Color(0,0,0));
    gameover.setString("  Game Over!   \n \n \n  Try Again?");
    intro.setString("  In Plasma Bird the rules are the same as\n  Flappy bird, avoid the pipes and ground \n  by pressing space. There is one exception \n   By pressing enter when the meter is full \n   scorch mode is activated giving \n  Plasma bird  limited invulnerability.");

    pipesPassed.setColor(sf::Color(255, 255, 255));
    pipesPassed.setString("0");
    int button = 0;
    int cooldown = 200;
    //value countdown until burst can be activated...
    int powerup = 0;
    bool burst = false;
    sf::Sprite segment;
    sf::Texture bars;
    bars.loadFromFile("PBarA.png");
    sf::Sprite segmentB;
    sf::Texture barsB;
    barsB.loadFromFile("PBarB.png");
    segmentB.setTexture(barsB);
    segment.setTexture(bars);
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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && powerup >= 900){
                   powerup = 0;
                   burst = true;

            }
        }
        gameThread.threadTask(button);
         button = 0;
        game.clear();
        if(gameThread.getPhase() == 2){
        if(burst){
            cooldown--;
            if(cooldown <= 0){
                cooldown = 200;
                burst = false;
            }
        }
        gameThread.activate(burst);
        }
        vector<sf::Sprite> temp = gameThread.terrain();
        for(int i = 0; i < temp.size(); i++)
        {
           // cout << "good " << i << endl;
            game.draw(temp[i]);
        }
        //added might create dangling pointers
        temp.clear();
        //****
        if(gameThread.getPhase() == 2){
        int progress = gameThread.getScore()/3;
        stringstream str;
        str << progress;
        sf::RectangleShape grs(sf::Vector2f(420.0, 100.0));
        grs.setFillColor(sf::Color::Black);
        grs.setPosition(0, 410);
        game.draw(grs);

            if(powerup < 900){
                powerup++;
            }

        for(int i = 0; i < powerup/30; i++){
            if(powerup/30 % 2 == 0){
                segment.setPosition(i * 17, 5);
                game.draw(segment);
            }
            else{
              segmentB.setPosition(i * 17, 5);
              game.draw(segmentB);
            }

            if(i + 1 >= powerup/30){
                cout << i << endl;
            }
        }

        pipesPassed.setString(str.str());
        pipesPassed.setCharacterSize(50);
        pipesPassed.setPosition(170, 405);
        game.draw(pipesPassed);
        }
        if(gameThread.getPhase() == 1){
             intro.setCharacterSize(20);
            intro.setPosition(38, 200);
            game.draw(intro);
        }
        if(gameThread.getPhase() == 3){
            gameover.setCharacterSize(25);
            gameover.setPosition(114, 220);
            powerup = 0;
            game.draw(gameover);
        }
        sf::sleep(sf::milliseconds(22));
        game.display();
    }

    return 0;
}
