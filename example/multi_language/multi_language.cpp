/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    multi_language.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 11:02
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 11:02
 */
#include "multi_language.h"

#include <QApplication>
#include <QString>
#include <QDebug>

#include "multi_language.ui.h"

multiLanguage::multiLanguage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

multiLanguage::~multiLanguage()
{
    delete ui;
}

void multiLanguage::on_comboBox_activated(const QString &str)
{
    QString language_qm[] = {
        "./multi_language_en_US",
        "./multi_language_zh_CN"
    };

    tran.load(language_qm[ui->comboBox->currentIndex()]);
    QApplication::installTranslator(&tran);
}

// 调用installTranslator后，
// 系统会给窗体发送信号将产生了changeEvent槽产生event
void multiLanguage::changeEvent(QEvent *e)
{
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}
