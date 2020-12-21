#ifndef STRUCTDEFINE_H
#define STRUCTDEFINE_H

#define static_test false
#define dynamic_test true

#pragma once
#pragma pack(1)

#include <QString>

typedef struct HeaderData
{
    ushort PackID;//报文类型 0xFCFE
    ushort PackType;//报文标识   录制文件的名称ID 0xFD01  当前任务显示的ID 0xFD02
    ushort SenderID;//发送方   0x0006
    ushort PackLength;//报文长度，（报头+报文）所占字节数
    uchar checkSum;//校验和，除校验和该字节外其他字节数据和
} Header;

typedef struct recLegInfo
{
    Header headerData;
    double leg1;
    double leg2;
    double leg3;
    double leg4;
    double leg5;
    double leg6;
} legInfo;

typedef struct positionComplete
{
    Header headerData;
    bool isComplete;    //1：到位；  0：未到位
} pComplete;

//#pragma pack(1)
typedef struct  sixDegreeData
{
    Header headerData;      //报文头统一定义

    bool testModel;         //1、false:静态测试  ture:动态测试
    int  postureX;          //2、车体姿态角α
    int  postureY;          //3、车体姿态角β
    int  postureZ;          //4、车体姿态角γ
    int  positionX;         //5、车体位移x
    int  positionY;         //6、车体位移y
    int  positionZ;         //7、车体位移z
    bool flag_RotX;         //8、绕X轴旋转运动标识位
    bool flag_RotY;         //9、绕Y轴旋转运动标识位
    bool flag_RotZ;         //10、绕Z轴旋转运动标识位
    bool flag_TransX;       //11、绕X轴平移运动标识位
    bool flag_TransY;       //12、绕Y轴平移运动标识位
    bool flag_TransZ;       //13、绕Z轴平移运动标识位
    int amplitude;          //14、正弦幅值
    int frequency;          //15、正弦频率
    uchar zeroToData;       //归零处理
    uchar testControlTime;  //测试控制时间标志位
    uchar testResponseTime; //测试响应时间标志位
    uchar flag_AccTest;     //加速度测试标志位,置1时表示测试加速度，正常状态为0
} SixData;
//Q_DECLARE_METATYPE(SixData)

typedef struct HeadInfo //报头
{
    ushort MsgID;                //报文标识0XFCFE
    ushort MsgType;              //报文类型0XFF04
    ushort MsgSender;            //发送方0X0010
    ushort MsgLen;               //报文长度0X0009
    uchar CheckSum;               //校验和 0
} HeadertoDriver;

typedef struct dataToDriver
{
    HeadertoDriver headerData;
    uchar tankType;//4,8,11对应三型
    uchar seatType;//2：车长；1：炮长；0：驾驶员
} sendSeatTypeInfo;



typedef struct  driverData
{
    Header headerData;      //报文头统一定义

    /*
      驾驶员报文头
    ushort PackID;//报文类型 0xFCFE
    ushort PackType;//报文标识 0xFF10
    ushort SenderID;//发送方   0x0001
    ushort PackLength;//报文长度，（报头+报文）所占字节数
    uchar checkSum;//校验和，除校验和该字节外其他字节数据和
    */

    int iHengQing;
    int iZongQing;
    int iHangXiang;

    int iAccSpeed_X ;
    int iAccSpeed_Y ;
    int iAccSpeed_Z ;

    int iAngularV_X ;
    int iAngularV_Y ;
    int iAngularV_Z;

    int iSpeed_X;
    int iSpeed_Y;
    int iSpeed_Z;

} driverData;


typedef struct  gunnerData
{
    Header headerData;      //报文头统一定义

    /*
      驾驶员报文头
    ushort PackID;//报文类型 0xFCFE
    ushort PackType;//报文标识 0xFF0F
    ushort SenderID;//发送方   0x0051
    ushort PackLength;//报文长度，（报头+报文）所占字节数
    uchar checkSum;//校验和，除校验和该字节外其他字节数据和
    */

    /*接收火控仿真软件发送的数据*/

    int iAngular_PaoTa ; // 炮塔角度
    int iAngularV_PaoTa ; //炮塔角速度

} gunnerData;



#pragma pack()



#endif // STRUCTDEFINE_H
