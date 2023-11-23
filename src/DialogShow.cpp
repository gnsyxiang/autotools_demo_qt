/**
 * 
 * Copyright (C), 2010-2011,江西科萌科技控股有限公司
 * 
 * @file    dialog_show.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    23/11 2023 11:43
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        23/11 2023      create the file
 * 
 *     last modified: 23/11 2023 11:43
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
