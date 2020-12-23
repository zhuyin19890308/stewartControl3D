/********************************************************************************
** 本类用于平台计算
**
** 功能包含:
** 1、平台雅可比矩阵计算
** 2、反解
** 3、洗出
** 4、正解
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/


#ifndef CALCULATEPOSTURE_H
#define CALCULATEPOSTURE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <structDefine.h>
#include <QSettings>
#include <QFile>
#include <QMessageBox>

namespace calPos
{

class calculatePosture : public QThread
{
    Q_OBJECT
public:
    platformPara stewartPara;
    QVector<float> leg;
public:
    explicit calculatePosture(QObject *parent = nullptr);
    explicit calculatePosture(uchar backwardInterval, QObject *parent = nullptr);

    //将从视景接收的数据转变为需要的类型
    template<typename T>
    QVector<T> transferRevData(driverData* data);

    template<typename T>
    QVector<T> transferRevData(gunnerData* data);

    template<typename T>
    QVector<T> transferRevData(stewartControlData* data);



public slots:

    virtual void initStewartPara(QString flag) = 0;//为各个算法初始化的平台参数，纯虚函数，所有继承类各自重写
    virtual void calJacoBian();//计算平台雅可比矩阵
    virtual void calBackWard();//反解
    virtual void calForeWard();//正解
    virtual void calWashOut(); //洗出

private:
    const uchar backwardInterval;//反解间隔
    friend class MainWindow;


protected:
    void run() override;

signals:

};

}

#endif // CALCULATEPOSTURE_H
