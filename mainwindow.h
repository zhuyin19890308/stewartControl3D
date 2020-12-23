#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conio.h"
#include <QLibrary>
#include <gts.h>
#include <QDebug>
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QDateTime>
#include <QTableWidget>
#include <QGridLayout>
#include <structDefine.h>
#include <scenemodifier.h>
#include <QLabel>
#include <QTimer>
#include <QElapsedTimer>
#include <calculateposture.h>
#include <QMessageBox>
#include <QSizePolicy>
#include <socketfactory.h>
#include <memory>


//Qt 3D功能
#include <QtGui/QScreen>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>


#include <QQuickWidget>
#include <QQuickView>

QT_BEGIN_NAMESPACE

/*可移动控件类
*/
class moveableBtn : public QPushButton
{
    Q_OBJECT
public:

    explicit moveableBtn(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);

private:
    QPoint pressPoint;

signals:
    void emitPos(QPoint*);
    void emitColor(QString);
    void emitEmergencyStop();
};




namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

public slots:

    void initMainWindow();
    bool setMode();
    void initStatusBar();

    QString formatTime(int ms);

    void initConnects(int step);
    void initLogFuction();

    FanSocket::FSocket * initNetwork();


    void set_permitted_x();
    void set_permitted_y();

    int get_permitted_x() const;  //常成员，不得修改任何类内成员
    int get_permitted_y() const;

    //日志功能
    QString getCurrentTime();
    void clearLog();
    void showLog(QString str);
    void showLog(QString locatFuc, QString str);

private slots:
    QPoint  setEmergencySwitchPos(QPoint*);
    void    setEmergencySwitchColor(QString);
    void    handleEmergencyStop();
    void    commandhandler(char* command, short error);
    int     testdll();
    void    debugView();
    void    test3D2();

signals:
    void setPermitted_x();
    void setPermitted_y();

    //日志功能
    void log(QString);
    void log(QString, QString);
    void clearLogWindow();

private:
    Ui::MainWindow * ui;
    moveableBtn * m_emergencySwitchBtn = nullptr;
    QPoint m_emergencySwitchBtnPos;

    int permitted_x_value;
    int permitted_y_value;

    //状态栏
    QLabel *platformStatusLabel;
    QLabel *incomeDataStatusLabel;
    QLabel *runTimeLable;
    QTimer *appRunTimeUpdate;
    QElapsedTimer *appRunStart;

    //用于存放3d界面的widget
    QWidget *View3DWidget = nullptr;

    bool isDebugMode = false;

    enum Mode
    {
        RegularMode,//常规模式，无三维显示
        DebugMode
    };

    FanSocket::SocketFactory socketFactory;
    FanSocket::FSocket *m_Udp = 0;

protected:
    void resizeEvent(QResizeEvent * event);
};
#endif // MAINWINDOW_H





