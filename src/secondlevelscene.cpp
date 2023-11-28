#include "secondlevelscene.h"
#include <iostream>
#include "enemies_nave.h"


SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background= new QPixmap(":/spritres/backgrounds/fondito_largo.jpg");
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave_morty.png");
    nave=new Spacecraft(10,200,400);
     timer_enemy=new QTimer();
     timer_enemy->start(4000);
     timer_move_enemy=new QTimer();
     timer_move_enemy->start(50);
     timer_asteroid=new QTimer();
     timer_asteroid->start(1000);
     col=new QTimer();
     col->start();
     connect(timer_asteroid,SIGNAL(timeout()),this,SLOT(generate_asteroid()));
    connect(timer_enemy,SIGNAL(timeout()),this,SLOT(generate_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_enemy()));

}


void SecondLevelScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);

    g->setBackgroundBrush(*brush);
    g->setScene(s);
    s->addItem(nave);
    nave->setScale(0.4);
    nave->setPixmap(*spr_nave);
    nave->setPos(nave->getX(),nave->getY());
    //scroll=s->addRect(40,30,30,30,);



}

void SecondLevelScene::movement(char key)
{
    if(key=='A'){
        if(nave->collision_left()==true){
            nave->setPos(nave->pos().x()+0,nave->pos().y());
            nave->setX(nave->getX()+0);
        }
        else{
           nave->setPos(nave->pos().x()-nave->getSpeed(),nave->pos().y());
           nave->setX(nave->getX()-nave->getSpeed());
        }

    }
    if(key=='D'){

        if(nave->collision_right()==true){
           nave->setPos(nave->pos().x()+0,nave->pos().y());
           nave->setX(nave->getX()+0);
        }
        else{
           nave->setPos(nave->pos().x()+nave->getSpeed(),nave->pos().y());
           nave->setX(nave->getX()+nave->getSpeed());
        }

}

}

void SecondLevelScene::move_enemy()
{
for(int i=0;i<enemies.size();i++){
    enemies[i]->setPos(enemies[i]->pos().x(),enemies[i]->pos().y()+enemies[i]->getSpeed());
        enemies[i]->setY(enemies[i]->getY()+enemies[i]->getSpeed());

    if(enemies[i]->getY()>700){
           s->removeItem(enemies[i]);
           delete enemies[i];
           enemies.erase(std::remove(enemies.begin(), enemies.end(), enemies[i]), enemies.end());
        }


}
}




void SecondLevelScene::generate_enemy()
{
//798


spr_enemy=new QPixmap(":/spritres/enemies/nave_enemiga.png");
enemy=new enemies_nave(rand()% 700,0);
enemy->setPixmap(*spr_enemy);
enemy->setPos(enemy->getX(),enemy->getY());
s->addItem(enemy);
enemies.push_back(enemy);


}

void SecondLevelScene::generate_asteroid()
{

spr_asteroid=new QPixmap(":/spritres/enemies/asteroide.png");
asteroid=new enemies_nave(rand()% 700,0);
asteroid->setPixmap(*spr_asteroid);
asteroid->setPos(asteroid->getX(),asteroid->getY());
s->addItem(asteroid);
asteroid->setScale(0.3);
enemies.push_back(asteroid);
}
/*
void SecondLevelScene::collision()
{

}
*/
SecondLevelScene::~SecondLevelScene()
{
    delete background;
    delete brush;
    delete g;
    delete s;
    delete nave;
    delete spr_nave;
    delete spr_enemy;
    delete enemy;
    delete timer_enemy;

}
