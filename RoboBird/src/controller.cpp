#include "controller.h"

controller::controller()
{
    passed = 0;
    delay = 0;
    phase = 0;
    player = birdy();
    scorched = false;
        if(!birdo.loadFromFile("plasmabird.png")){ cout << " the bird did not load" << endl; }
    if(!downpipe.loadFromFile("downPipe.png")){ cout << "pipe 1 failed " << endl; }
    if(!uppipe.loadFromFile("upPipe.png")){ cout << "pipe 2 failed " << endl; }
     if(!adownpipe.loadFromFile("SdownPipe.png")){ cout << "pipe 1 failed " << endl; }
    if(!auppipe.loadFromFile("DupPipe.png")){ cout << "pipe 2 failed " << endl; }
    if(!floorpipe.loadFromFile("floorSprite.png")){ cout << "floor failed " << endl; }
    if(!bk.loadFromFile("bg.png")){ cout << " background failed " << endl; }
   if(!fb.loadFromFile("ph.png")){ cout << " background failed " << endl; }
   if(!title.loadFromFile("titlescr.png")){ cout << " title " << endl; }
   if(!info.loadFromFile("structions.png")){ cout << " slate " << endl; }
   if(!vapI.loadFromFile("vapor1.png")){ cout << " slate " << endl; }
    if(!vapII.loadFromFile("vapor2.png")){ cout << " slate " << endl; }
    if(!vapIII.loadFromFile("vapor3.png")){ cout << " slate " << endl; }

    scorched = false;
    assembly = frameQueue();
    seal = true;
    //ctor
}
void controller::threadTask(int button)
{
    if(phase == 2){
    if(button == 0)
    {
        player.update(false);
        assembly.scroll(passed, false);
        assembly.scroll(passed, false);
        if(scorched){
            assembly.scroll(passed, false);
             assembly.scroll(passed, false);
              assembly.scroll(passed, false);
               assembly.scroll(passed, false);
               assembly.scroll(passed, false);
        }

        bool done = assembly.colCheck(player.getImg(), scorched);
        if(done)
        {
            phase = 3;
            player.setPos(100, 120);
        }

    }
    else if(button == 1)
    {
        player.update(true);
        assembly.scroll(passed, false);
         assembly.scroll(passed, false);
        if(scorched){
            assembly.scroll(passed, false);
             assembly.scroll(passed, false);
              assembly.scroll(passed, false);
               assembly.scroll(passed, false);
               assembly.scroll(passed, false);
        }

        bool done = assembly.colCheck(player.getImg(), scorched);
        if(done)
        {
            phase = 3;
            player.setPos(100, 120);
        }

    }
    if(!seal && assembly.passed())
    {    if(!scorched){
        passed++;
    }
    if(scorched){
        passed += 3;
    }
    }
    seal = assembly.passed();
    }
    if(phase == 0 && button == 1){
        phase = 1;
    }
    else if(phase == 1 && button == 1){
        phase = 2;
    }
    else if(phase == 3 && button == 1){
        phase = 0;
        passed = 0;
        delay = 0;
        scorched = false;
        //assembly.reset();
        assembly = frameQueue();
        seal = true;
    }

}



//function for returning img frames
vector<sf::Sprite> controller::terrain()
{


    vector<sf::Sprite> sparse;
    if(phase == 0){
        sf::Sprite opening;
        opening.setTexture(title);
        opening.setPosition(-40, 0);
        sparse.push_back(opening);
    }
    else if(phase == 2){
    //current focused frame
    frame tempA = assembly.curObs();
    //nextframe
    frame tempB = assembly.nextObs();

    //background
    sf::Sprite tempi;
    tempi.setTexture(bk);
    tempi.setPosition( tempA.getBk().getPosition().x, tempA.getBk().getPosition().y - 4);
    sf::Sprite tempj;
    tempj.setTexture(floorpipe);
    tempj.scale(1.2, 1);
    tempj.setPosition( tempA.getFloor().getPosition().x, tempA.getFloor().getPosition().y - 4 );
    sf::RectangleShape* ray = tempA.getPipes();
    sparse.push_back(tempi);
    sparse.push_back(tempj);
    cout << "this is the current frame!! " << tempA.ty() << endl;
    for(int i = 0; i < tempA.len(); i++)
    {
        sf::Sprite temp;
        if(!scorched){
        if(i % 2 == 0){  temp.setTexture(downpipe);  }
        else { temp.setTexture(uppipe); }
        float rex =  ray[i].getPosition().x;
        float rey = ray[i].getPosition().y;
        float cx;
        float cy;
        if(i % 2 == 0){
          if(rey + 220 > rey + ray[i].getSize().y){
            rey -= (rey + 220 - (rey + ray[i].getSize().y));

          }
        }
        if(i % 2 == 1){
            if(rey + 220 < 460){
                    float increase = 460 - (rey + 220);
                temp.scale(1, (220 + increase)/220);

            }
        }

        temp.setPosition( rex, rey );
        sparse.push_back(temp);
        }
        else{
            if(i % 2 == 0){  temp.setTexture(downpipe);  }
        else { temp.setTexture(uppipe); }
        float rex =  ray[i].getPosition().x;
        float rey = ray[i].getPosition().y;
        float cx;
        float cy;
        if(rex - 150 < player.x){
        if(i % 2 == 0){  temp.setTexture(adownpipe);  }
        else { temp.setTexture(auppipe); }
        }
        if(i % 2 == 0){
          if(rey + 220 > rey + ray[i].getSize().y){
            rey -= (rey + 220 - (rey + ray[i].getSize().y));

          }
        }
        if(i % 2 == 1){
            if(rey + 220 < 460){
                    float increase = 460 - (rey + 220);
                temp.scale(1, (220 + increase)/220);

            }
        }
        temp.setPosition( rex, rey );
        sparse.push_back(temp);
    }

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
    tempk.setPosition(tempB.getBk().getPosition().x , tempB.getBk().getPosition().y - 4);
    sparse.push_back(tempk);
    sf::Sprite templ;
    templ.setTexture(floorpipe);
    templ.scale(1.2, 1);
    templ.setPosition(tempB.getFloor().getPosition().x, tempB.getFloor().getPosition().y - 4);
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

          }
        }
        if(i % 2 == 1){
            if(rey + 220 < 460){
                    float increase = 460 - (rey + 220);
                temp.scale(1, (220 + increase)/220);

            }
        }

        temp.setPosition( rex, rey );
        sparse.push_back(temp);

    }


     sf::Sprite daBird = getFrame();
     //daBird.setTexture(fb);
     daBird.setPosition(player.getImg().getPosition().x, player.getImg().getPosition().y );
    sparse.push_back(daBird);
    if(scorched){
        int value = delay % 18;
        if(value < 8){
            sf::Sprite flam;
            flam.setTexture(vapI);
            flam.setPosition(daBird.getPosition().x + -10, daBird.getPosition().y - 17);
            sparse.push_back(flam);
        }
        if(value > 2 &&  value < 10){
            sf::Sprite flamII;
            flamII.setTexture(vapII);
            flamII.setPosition(daBird.getPosition().x + -8, daBird.getPosition().y - 41);
            sparse.push_back(flamII);
        }
        if(value > 4 && value < 12){
            sf::Sprite flamIII;
            flamIII.setTexture(vapIII);
            flamIII.setPosition(daBird.getPosition().x + -27, daBird.getPosition().y -135);
            sparse.push_back(flamIII);
        }
    }
    }
    else{
        sf::Sprite dialogue;
        dialogue.setTexture(info);
        dialogue.setPosition(-40, 0);
        sparse.push_back(dialogue);
    }
    return sparse;
}
sf::Sprite controller::getFrame(){
    delay++;
if(scorched){
        int value = (delay % 27)/3;
        sf::Sprite temp;
         temp.setTexture(player.fireball[value]);
         return temp;

}

   int value = (delay % 18)/3;
   //return player.gliding[value];

   sf::Sprite temper;
   temper.setTexture(player.gliding[value]);
   return temper;


}

controller::~controller()
{
    //dtor
}

