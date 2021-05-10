/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    bubble_sort.h
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
#ifndef __EXAMPLE_QTHREAD_BUBBLE_SORT_H_
#define __EXAMPLE_QTHREAD_BUBBLE_SORT_H_

#include <QThread>
#include <QRunnable>
#include <QVector>

class BubbleSortRunnable: public QThread, public QRunnable {
    Q_OBJECT

public:
    explicit BubbleSortRunnable(QObject *parent = nullptr);
    virtual ~BubbleSortRunnable();

signals:
    void finish(QVector<int> list);

public slots:
    void recvArray(QVector<int> list);

protected:
    void run() override;

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

