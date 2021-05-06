/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    multi_language.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 10:55
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 10:55
 */
#ifndef __EXAMPLE_MULTI_LANGUAGE_MY_DIALOG_H_
#define __EXAMPLE_MULTI_LANGUAGE_MY_DIALOG_H_

#include <QDialog>
#include <QTranslator>

namespace Ui {
    class Dialog;
}

class multiLanguage : public QDialog {
    Q_OBJECT

public:
    explicit multiLanguage(QWidget *parent = 0);
    ~multiLanguage();

private slots:
    void on_comboBox_activated(const QString &str);
    void changeEvent(QEvent *e);

private:
    Ui::Dialog *ui;
    QTranslator tran;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

