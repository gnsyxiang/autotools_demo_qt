/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    random_thread.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 19:10
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 19:10
 */
#ifndef __EXAMPLE_QTHREAD_RANDOM_THREAD_H_
#define __EXAMPLE_QTHREAD_RANDOM_THREAD_H_

#include <QThread>

class RandomThread: public QThread {
    Q_OBJECT

public:
    explicit RandomThread(QObject *parent = nullptr);
    virtual ~RandomThread();

signals:
    void randomNumDown(QVector<int> random_vector);

public slots:
    void getRandomNum(int cnt);

public:

protected:
    void run() override;

private:
    int m_cnt;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

