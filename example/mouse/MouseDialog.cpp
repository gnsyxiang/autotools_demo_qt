/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    MouseDialog.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    10/05 2021 18:53
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        10/05 2021      create the file
 * 
 *     last modified: 10/05 2021 18:53
 */
#include <QMouseEvent>
#include <QDebug>

#include "MouseDialog.h"
#include "mouse.ui.h"

MouseDialog::MouseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //默认是当按下鼠标按键时移动鼠标，鼠标移动事件才会产生
    //如果想不按鼠标按键，也可以获得鼠标移动事件，可以在构造函数上添加这一行
    // setMouseTracking(true);

    bool b = hasMouseTracking();  //返回鼠标跟踪状态

    qDebug() << b;
}

MouseDialog::~MouseDialog()
{
    delete ui;
}

void MouseDialog::mousePressEvent(QMouseEvent *event)
{
    // 只返回一个键--触发事件的键
    //e->button()
    qDebug() << event->button();

    // 返回的是鼠标的按键情况--返回哪些键被按下
    //e->buttons()
    qDebug() << event->buttons();
    //QFlags<Qt::MouseButton>(LeftButton|RightButton)

    if(event->buttons() & Qt::LeftButton && event->buttons() & Qt::RightButton ){   //如果按住了左键和右键
        qDebug()<<"你按下了左键和右键：";
    }

    if(event->buttons() & Qt::LeftButton && event->buttons() & Qt::MidButton ){   //如果按住了左键和中键
        qDebug()<<"你按下了左键和中键：";
    }

    switch (event->button()) {
        case Qt::LeftButton:
            ui->clickLineEdit->setText("LeftButton");
            qDebug() << "--1---haha" << event->button();
            break;
        case Qt::RightButton:
            ui->clickLineEdit->setText("RightButton");
            qDebug() << "--2---haha" << event->button();
            break;
        case Qt::MidButton:
            ui->clickLineEdit->setText("MidButton");
            qDebug() << "--3---haha" << event->button();
            break;
        default:
            ui->clickLineEdit->setText("others");
            qDebug() << "--4---haha" << event->button();
            break;
    }
}

void MouseDialog::mouseReleaseEvent(QMouseEvent *event)
{
    // qDebug() << "--5---haha" << event->button();
}

void MouseDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
    /*
       双击时的事件顺序如下:
       MouseButtonPress
       MouseButtonRelease
       MouseButtonDblClick
       MouseButtonPress
       MouseButtonRelease

       setDoubleClickInterval()    //方法可设置双击的时间间隔
       doubleClickInterval()        //方法返回双击的时间间隔
       */
    switch (event->button()) {
        case Qt::LeftButton:
            ui->clickLineEdit->setText("Double LeftButton");
            qDebug() << "--1------xixi" << event->button();
            break;
        case Qt::RightButton:
            ui->clickLineEdit->setText("Double RightButton");
            qDebug() << "--2------xixi" << event->button();
            break;
        case Qt::MidButton:
            ui->clickLineEdit->setText("Double MidButton");
            qDebug() << "--3------xixi" << event->button();
            break;
        default:
            ui->clickLineEdit->setText("Double others");
            qDebug() << "--4------xixi" << event->button();
            break;
    }
}

void MouseDialog::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pointF1, pointF2;
    QPoint point, point1, point2;
    int x, y;

    // 相对于窗口坐标
#if 1
    // 每个Qwidget都能通过pos()获取到相对自己父类窗口的位置
    pointF1 = event->windowPos();
    pointF1 = event->localPos();
    point1 = event->pos();
    x = event->pos().x();
    y = event->pos().y();
    x = event->x();
    y = event->y();

    qDebug() << "窗口坐标: " << point1 << pointF1;

    char buf[32] = {0};
    snprintf(buf, 32, "x: %d, y: %d", x, y);
    ui->pointLineEdit->setText(QString(buf));
#endif

    // 相对于屏幕坐标
#if 1
    point2 = event->globalPos();
    pointF2 = event->screenPos();
    x = event->globalX();
    y = event->globalY();

    qDebug() << "屏幕坐标: " << point2 << pointF2;
#endif

#if 1
    point=mapToGlobal(point1);      //将窗口坐标转换成屏幕坐标
    qDebug() << "窗口坐标转屏幕坐标: "<< point1 << point;

    point=mapFromGlobal(point2);   //将相对于屏幕的坐标转换成相对于窗口的坐标
    qDebug() << "屏幕坐标转窗口坐标: "<< point2 << point;
    /*
    mapToParent(QPoint) - 将窗口坐标转换成父窗口坐标。如果没有父窗口，则相当于mapToGlobal (QPoint)
    mapFromParent(QPoint) - 将父窗口坐标转换成窗口坐标。如果没有父窗口，则相当于mapFromGlobal(QPoint)
    mapTo (QWidget, QPoint) - 将窗口坐标转换成 QWidget父窗口坐标
    */
#endif

#if 1
    int t = event->timestamp();  //返回事件发生的时间。【以程序运行开始计时，以毫秒为单位】

    qDebug() << "事件发生时间: " << t << "ms"
        << t / 1000 << "s"
        << t / 1000 / 60 << "min"
        << t / 1000 / 3600 << "h";
#endif
}

void MouseDialog::wheelEvent(QWheelEvent *event)
{
    //返回屏幕上以像素为单位的滚动距离。
    //此值是在支持基于高分辨率像素的delta值的平台（如macos）上提供的。该值应直接用于在屏幕上滚动内容
    //ev->pixelDelta(); 

    QPoint point = event->angleDelta();  //返回滚轮转过的数值，单位为1/8度
    //QPoint(0,120)--向上滚     QPoint(0,-120)--向下滚

    point = point / 8;  //除以8之后单位为度
    //QPoint(0,15)

    qDebug() << point;
}

