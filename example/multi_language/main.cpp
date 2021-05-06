/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    main.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 11:07
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 11:07
 */
#include <QApplication>

#include "multi_language.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    multiLanguage multi_language;
    multi_language.show();

    return a.exec();
}
