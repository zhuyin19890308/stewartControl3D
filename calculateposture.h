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


namespace calPos
{

class calculatePosture : public QThread
{
    Q_OBJECT
public:
    explicit calculatePosture(QObject *parent = nullptr);
    explicit calculatePosture(uchar backwardInterval, QObject *parent = nullptr);

public slots:

    virtual void calJacoBian() = 0;

private:
    const uchar backwardInterval;//反解间隔
    friend class MainWindow;

protected:
    void run() override;

signals:

};

}

#endif // CALCULATEPOSTURE_H
