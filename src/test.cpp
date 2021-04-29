/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    test.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    28/04 2021 20:06
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        28/04 2021      create the file
 * 
 *     last modified: 28/04 2021 20:06
 */
#include "test.hpp"

#include <QDebug>

Test::Test(void)
{
    bl = new QLabel("我是标签", this);
    bl->resize(80, 30);
    bl->move(30, 20);

    bt = new QPushButton("我是按钮", this);
    bt->resize(80, 30);
    bt->move(30, 60);
}
