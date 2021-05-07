/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    qthread_dialog.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 09:23
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 09:23
 */
#ifndef __EXAMPLE_QTHREAD_QTHREAD_DIALOG_H_
#define __EXAMPLE_QTHREAD_QTHREAD_DIALOG_H_

#include <QDialog>

#include "random_thread.h"
#include "bubble_sort_thread.h"
#include "quick_sort_thread.h"

namespace Ui {
    class Dialog;
}

class QthreadDialog : public QDialog {
    Q_OBJECT

public:
    explicit QthreadDialog(QWidget *parent = nullptr);
    virtual ~QthreadDialog();

signals:
    void setRandomNum(int cnt);
    void startSort(QVector<int> random_vector);

private slots:
    void getRandomNumFromThread(QVector<int> random_vector);
    void getRandomNumFromBubbleSortThread(QVector<int> random_vector);
    void getRandomNumFromQuickSortThread(QVector<int> random_vector);

private:
    Ui::Dialog          *ui;
    RandomThread        *random_thread;
    BubbleSortThread    *bubble_sort_thread;
    QuickSortThread     *quick_sort_thread;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

