/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    bubble_sort_thread.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    07/05 2021 09:39
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        07/05 2021      create the file
 * 
 *     last modified: 07/05 2021 09:39
 */
#include <QDebug>

#include "bubble_sort_thread.h"

BubbleSortThread::BubbleSortThread(QObject *parent) :
    QThread(parent)
{
}

BubbleSortThread::~BubbleSortThread()
{
}

void BubbleSortThread::_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSortThread::_bubble_sort(QVector<int> &random_vector)
{
    for (int i = 0; i < random_vector.size(); i++) {
        for (int j = 0; j + 1 < random_vector.size()  - i; j++) {
            if (random_vector[j] > random_vector[j + 1]) {
                _swap(&random_vector[j], &random_vector[j + 1]);
            }
        }
    }
}

// #include <QDebug>
//
// struct timeval tpstart,tpend;
// float timeuse;
//
// gettimeofday(&tpstart,NULL);
//
//
// gettimeofday(&tpend,NULL);
// timeuse=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;
 
#if 1
#include <sys/time.h>

static long long _getStartTimeUs(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);

    return (time.tv_sec * 1000 * 1000 + time.tv_usec);
}

static long long _getIntervalFromStartTimeUs(long long start_us)
{
    struct timeval time;
    gettimeofday(&time, NULL);

    return (time.tv_sec * 1000 * 1000 + time.tv_usec - start_us);
}
#endif

void BubbleSortThread::run()
{
    long long start_us = _getStartTimeUs();
    _bubble_sort(m_random_vector);
    long long interval_us = _getIntervalFromStartTimeUs(start_us);

    qDebug() << interval_us / 1000.0 << "ms";

    emit bubbleSortOver(m_random_vector);
}

void BubbleSortThread::getNumFromMainThread(QVector<int> random_vector)
{
    m_random_vector = random_vector;
}

