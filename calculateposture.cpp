#include "calculateposture.h"

calculatePosture::calculatePosture(QObject *parent) : QThread(parent), backwardInterval(10)
{

}

calculatePosture::calculatePosture(uchar backwardInterval, QObject *parent): QThread(parent), backwardInterval(backwardInterval)
{

}

void calculatePosture::run()
{

}
