/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    HyQtDemo.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    23/11 2023 14:10
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        23/11 2023      create the file
 * 
 *     last modified: 23/11 2023 14:10
 */
#include <QApplication>
#include <QDebug>
#include <QFile>

#include "DialogShow.h"

#define UTILS_QSS_PATH "./res/qss/"
#define UTILS_IMG_PATH "./res/img/"

#include "DialogShow.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QFile file(UTILS_QSS_PATH"demo.qss");
    if (file.open(QFile::ReadOnly)) {
        qDebug() << "use qss file";
        QString styleSheet = QLatin1String(file.readAll());
        a.setStyleSheet(styleSheet);
        file.close();
    }

    DialogShow dialog_show;
    dialog_show.show();

    return a.exec();
}

