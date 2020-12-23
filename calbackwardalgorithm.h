#ifndef CALBACKWARDALGORITHM_H
#define CALBACKWARDALGORITHM_H

#include "calculateposture.h"


using namespace calPos;

class calBackwardAlgorithm : public calculatePosture
{
public:
    //calBackwardAlgorithm();

    //flag为"defualt"时，表示为默认平台参数
    calBackwardAlgorithm(QString flag);

    void initStewartPara(QString flag) override;
    void calBackWard() override;

    void run() override;

private:

    //平台航姿
    float gama1, alpha1, beta1;
    float x1, y1, z1;


};

#endif // CALBACKWARDALGORITHM_H
