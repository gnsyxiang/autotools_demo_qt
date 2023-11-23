/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    dialog_show.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    23/11 2023 11:40
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        23/11 2023      create the file
 * 
 *     last modified: 23/11 2023 11:40
 */
#ifndef __AUTOTOOLS_DEMO_QT_INCLUDE_DIALOG_SHOW_H_
#define __AUTOTOOLS_DEMO_QT_INCLUDE_DIALOG_SHOW_H_

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

