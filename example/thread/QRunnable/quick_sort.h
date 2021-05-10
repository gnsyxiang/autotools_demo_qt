/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    quick_sort.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    07/05 2021 10:40
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        07/05 2021      create the file
 * 
 *     last modified: 07/05 2021 10:40
 */
#ifndef __EXAMPLE_QRUNNABLE_QUICK_SORT_H_
#define __EXAMPLE_QRUNNABLE_QUICK_SORT_H_

#include <QThread>
#include <QRunnable>
#include <QVector>

class QuickSortRunnable: public QThread, public QRunnable {
    Q_OBJECT

public:
    explicit QuickSortRunnable(QObject *parent = nullptr);
    virtual ~QuickSortRunnable();

public:
    void run() override;

signals:
    void finish(QVector<int> list);

public slots:
    void recvArray(QVector<int> list);

private:
    QVector<int> m_list;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

