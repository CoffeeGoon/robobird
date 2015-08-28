#include "controller.h"

controller::controller()
{
    passed = 0;
    player = birdy();
    if(!downpipe.loadFromFile("downPipe.png")){ cout << "pipe 1 failed " << endl; }
    if(!uppipe.loadFromFile("upPipe.png")){ cout << "pipe 2 failed " << endl; }
    if(!floorpipe.loadFromFile("floorSprite.png")){ cout << "floor failed " << endl; }
    if(!bk.loadFromFile("bg.png")){ cout << " background failed " << endl; }
   if(!fb.loadFromFile("ph.png")){ cout << " background failed " << endl; }
    assembly = frameQueue();
    seal = true;
    //ctor
}
void controller::threadTask(int button)
{
    if(button == 0)
    {
        player.update(false);
        assembly.scroll(passed, false);
        bool done = assembly.colCheck(player.getImg(), false);
        if(done)
        {
            player.setPos(100, 120);
        }
    }
    else if(button == 1)
    {
        player.update(true);
        assembly.scroll(passed, false);
        bool done = assembly.colCheck(player.getImg(), false);
        if(done)
        {
            player.setPos(100, 120);
        }
    }
    if(!seal && assembly.passed())
    {
        passed++;
    }
    seal = assembly.passed();


}

vector<sf::Sprite> controller::terrain()
{
    vector<sf::Sprite> sparse;
    frame tempA = assembly.curObs();
    frame tempB = assembly.nextObs();
    sf::Sprite tempi;
    tempi.setTexture(bk);
    tempi.setPosition( tempA.getBk().getPosition().x, tempA.getBk().getPosition().y );
    sf::Sprite tempj;
    tempj.setTexture(floorpipe);
    tempj.scale(1.2, 1);
    tempj.setPosition( tempA.getFloor().getPosition().x, tempA.getFloor().getPosition().y );
    sf::RectangleShape* ray = tempA.getPipes();
    sparse.push_back(tempi);
    sparse.push_back(tempj);
    for(int i = 0; i < tempA.len(); i++)
    {
        sf::Sprite temp;
        if(i % 2 == 0){  temp.setTexture(downpipe);  }
        else { temp.setTexture(uppipe); }
        float rex =  ray[i].getPosition().x;
        float rey = ray[i].getPosition().y;
        float cx;
        float cy;
        if(i % 2 == 0){
          if(rey + 220 > rey + ray[i].getSize().y){
            rey -= (rey + 220 - (rey + ray[i].getSize().y));
            cout << "Yowza!!" << endl;
          }
        }
        if(i % 2 == 1){
            if(rey + 220 < 460){
                    float increase = 460 - (rey + 220);
                temp.scale(1, (220 + increase)/220);
                cout << "Vhaat??" << endl;
            }
        }

        temp.setPosition( rex, rey );
        sparse.push_back(temp);

    }


   //sf::RectangleShape ray[] = tempB.getPipes
   /*
    for(int i = 0; i < tempB.len(); i++)
    {
        sf::Sprite temp;
        if(i % 2 == 0){  temp.setTexture(downpipe);  }
        else { temp.setTexture(uppipe); }
        temp.setPosition(ray[i].getPosition().x, ray[i].getPosition().y);
        sparse.push_back(temp);
    }
    */

     ray = tempB.getPipes();
     sf::Sprite tempk;
    tempk.setTexture(bk);
    tempk.setPosition(tempB.getBk().getPosition().x , tempB.getBk().getPosition().y);
    sparse.push_back(tempk);
    sf::Sprite templ;
    templ.setTexture(floorpipe);
    templ.scale(1.2, 1);
    templ.setPosition(tempB.getFloor().getPosition().x, tempB.getFloor().getPosition().y);
    sparse.push_back(templ);
    for(int i = 0; i < tempB.len(); i++)
    {
        sf::Sprite temp;
        if(i % 2 == 0){  temp.setTexture(downpipe);  }
        else { temp.setTexture(uppipe); }
        float rex = ray[i].getPosition().x;
        float rey = ray[i].getPosition().y;
        float cx;
        float cy;
        if(i % 2 == 0){
          if( rey + 220 > rey + ray[i].getSize().y ){
            rey -= (rey + 220 - (rey + ray[i].getSize().y));
            cout << "Yowza!!" << endl;
          }
        }
        if(i % 2 == 1){
            if(rey + 220 < 460){
                    float increase = 460 - (rey + 220);
                temp.scale(1, (220 + increase)/220);
                cout << "Vhaat??" << endl;
            }
        }

        temp.setPosition( rex, rey );
        sparse.push_back(temp);

    }
     sf::Sprite daBird;
     daBird.setTexture(fb);
     daBird.setPosition(player.getImg().getPosition().x, player.getImg().getPosition().y );
    sparse.push_back(daBird);
    return sparse;
}

controller::~controller()
{
    //dtor
}

