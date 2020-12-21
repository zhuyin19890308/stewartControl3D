#include "calculateposture.h"


calPos:: calculatePosture::calculatePosture(QObject *parent) : QThread(parent), backwardInterval(10)
{

}

calPos:: calculatePosture::calculatePosture(uchar backwardInterval, QObject *parent): QThread(parent), backwardInterval(backwardInterval)
{

}

void calPos:: calculatePosture::run()
{

}
