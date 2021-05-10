/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    random.h
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
#ifndef __EXAMPLE_QRUNNABLE_RANDOM_H_
#define __EXAMPLE_QRUNNABLE_RANDOM_H_

#include <QThread>
#include <QRunnable>

class RandomRunnable: public QThread, public QRunnable {
    Q_OBJECT

public:
    explicit RandomRunnable(QObject *parent = nullptr);
    virtual ~RandomRunnable();

public:
    void run() override;

signals:
    void randomNumDown(QVector<int> random_vector);

public slots:
    void getRandomNum(int cnt);

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

