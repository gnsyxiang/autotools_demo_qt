/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    main.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    29/04 2021 17:40
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        29/04 2021      create the file
 * 
 *     last modified: 29/04 2021 17:40
 */
#include <QApplication>
#include <QDebug>

#include "DialogShow.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    DialogShow dialog_show;

    dialog_show.show();

    return a.exec();
}

