/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    main.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    10/05 2021 19:05
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        10/05 2021      create the file
 * 
 *     last modified: 10/05 2021 19:05
 */
#include <QApplication>

#include "MouseDialog.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    MouseDialog mouse_dialog;
    mouse_dialog.show();

    return a.exec();
}
