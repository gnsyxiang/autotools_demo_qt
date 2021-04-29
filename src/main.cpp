#if 0
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include <QTextCodec>
#include <QTranslator>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QTextCodec *gbk = QTextCodec::codecForName("GB2312"); 
    QTextCodec::setCodecForLocale(gbk);

    QTranslator translator;
    // translator.load("res/tr-demo_EN");
    translator.load("res/tr-demo_zh_CN");
    a.installTranslator(&translator);

    QMainWindow main_window;
    main_window.resize(320, 240);
    main_window.move(400, 400);
    main_window.setWindowTitle(QMainWindow::tr("title"));

    QPushButton *btn = new QPushButton(QPushButton::tr("I'm a button"), &main_window);
    btn->resize(140, 20);
    btn->move(30, 30);

    QLabel *label = new QLabel(QLabel::tr("I'm a label"), &main_window);
    label->resize(140, 20);
    label->move(30, 100);

    main_window.show();

    return a.exec();
}
#else
#include <QApplication>
#include <QDebug>

#include "test.hpp"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    qDebug("-------0");
    Test test;

    test.resize(320, 240);
    test.move(400, 400);
    test.show();

    return a.exec();
}

#endif
