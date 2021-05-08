/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    quick_sort_thread.h
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
#ifndef __EXAMPLE_QTHREAD_QUICK_SORT_THREAD_H_
#define __EXAMPLE_QTHREAD_QUICK_SORT_THREAD_H_

#include <QThread>
#include <QVector>

class QuickSortThread: public QThread {
    Q_OBJECT

public:
    explicit QuickSortThread(QObject *parent = nullptr);
    virtual ~QuickSortThread();

signals:
    void finish(QVector<int> list);

public slots:
    void recvArray(QVector<int> list);

protected:
    void run() override;

private:
    void _quicksort(int left, int right);

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

