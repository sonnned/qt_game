#ifndef FIRSTLEVELSCENE_H
#define FIRSTLEVELSCENE_H

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "playerscore.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QImage>
#include <QBrush>
#include <QPixmap>

class FirstLevelScene: public QObject
{
public:
    FirstLevelScene();
    ~FirstLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movePlayer();
    void noMovePlayer();
    void modifyPositionDir(int pos);
    int getXPlayerPos();
    int getYPlayerPos();
    void clearScene();
    void generateBullet(int x, int y);
    void startLevel();
    int getDeadEnemies() const;
    void setUpLevel();
    void setDeadEnemies(int newDeadEnemies);
    int getPlayerLife();
    void setPlayerLife(int life);
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    Player *p;
    QTimer *enemyTimer;
    PlayerScore *pScoreEnemies;
    PlayerScore *pScoreLife;
    PlayerScore *pCurrentBullets;
    int amountOfEnemies = 0;
    int deadEnemies = 0;
    const std::string background = ":/spritres/backgrounds/level_1_background.jpg";
    QGraphicsPixmapItem *backgroundItem;
    std::vector<std::string> playerSprites = {":/spritres/characters/Rick.png", ":/spritres/enemies/Dragonfly.png", ":/spritres/enemies/Twig.png", ":/spritres/enemies/car/Projectile.png"};
    int amountOfBullets = 0;
    QTimer *bulletTimer;
    int enemyVel = 10;
    void setBackground();
private slots:
    void generateEnemy();
    void amountOfEnemiesDecrement();
    void shootBullet();
};

#endif // FIRSTLEVELSCENE_H
