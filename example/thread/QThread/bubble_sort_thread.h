/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    bubble_sort_thread.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    07/05 2021 09:38
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        07/05 2021      create the file
 * 
 *     last modified: 07/05 2021 09:38
 */
#ifndef __EXAMPLE_QTHREAD_BUBBLE_SORT_THREAD_H_
#define __EXAMPLE_QTHREAD_BUBBLE_SORT_THREAD_H_

#include <QThread>
#include <QVector>

class BubbleSortThread: public QThread {
    Q_OBJECT

public:
    explicit BubbleSortThread(QObject *parent = nullptr);
    virtual ~BubbleSortThread();

signals:
    void bubbleSortOver(QVector<int> random_vector);

public slots:
    void getNumFromMainThread(QVector<int> random_vector);

protected:
    void run() override;

private:
    void _swap(int *a, int *b);
    void _bubble_sort(QVector<int> &random_vector);

private:
    QVector<int> m_random_vector;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

