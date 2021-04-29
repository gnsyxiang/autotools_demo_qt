/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    DialogShow.cpp
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
#include "DialogShow.h"

#include "DialogShow.ui.h"

DialogShow::DialogShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShow)
{
    ui->setupUi(this);
}

DialogShow::~DialogShow()
{
    delete ui;
}
