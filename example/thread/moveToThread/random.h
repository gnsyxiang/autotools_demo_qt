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
#ifndef __EXAMPLE_MOVETOTHREAD_RANDOM_H_
#define __EXAMPLE_MOVETOTHREAD_RANDOM_H_

#include <QThread>

class Random: public QObject {
    Q_OBJECT

public:
    explicit Random(QObject *parent = nullptr);
    virtual ~Random();

public:
    void working(int cnt);

signals:
    void randomNumDown(QVector<int> random_vector);
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

