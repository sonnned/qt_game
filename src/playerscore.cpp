#include "playerscore.h"

PlayerScore::PlayerScore(QString text, int limit, int beg, int x, int y)
{
    this->beg = beg;
    initialBeg = beg;
    this->text = text;
    this->limit = limit;
    QFontDatabase::addApplicationFont(":/fonts/m5x7.ttf");
    QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
    setPlainText(scoreText);
    setDefaultTextColor(Qt::black);
    setFont(QFont("m5x7", 20));
    setPos(x, y);
}

void PlayerScore::increaseCurrentDeadEnemies()
{
    if (initialBeg == 0) {
        beg++;
        QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
        setPlainText(scoreText);
    }
}

void PlayerScore::decreaseCurrentPlayerLife()
{
    if (initialBeg > 0) {
        beg -= 5;
        QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
        setPlainText(scoreText);
    }
}