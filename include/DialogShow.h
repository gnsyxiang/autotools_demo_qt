/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    DialogShow.h
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
#ifndef __AUTOTOOLS_DEMO_QT_INCLUDE_DIALOGSHOW_H_
#define __AUTOTOOLS_DEMO_QT_INCLUDE_DIALOGSHOW_H_

#include <QtWidgets/QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
    class DialogShow;
}

class DialogShow: public QDialog
{
    Q_OBJECT

public:
    explicit DialogShow(QWidget *parent = 0);
    ~DialogShow();

private:
    Ui::DialogShow *ui;
};

#endif

