/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    test.hpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    28/04 2021 20:01
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        28/04 2021      create the file
 * 
 *     last modified: 28/04 2021 20:01
 */
#ifndef __TEST_HPP_
#define __TEST_HPP_

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class Test: public QMainWindow {
    Q_OBJECT

public:
    Test();

private:
    QLabel *bl;
    QMainWindow *mw;
};

#endif

