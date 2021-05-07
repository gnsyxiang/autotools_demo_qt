/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    quick_sort_thread.cpp
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
#include <QDebug>

#include "quick_sort_thread.h"

QuickSortThread::QuickSortThread(QObject *parent) :
    QThread(parent)
{
}

QuickSortThread::~QuickSortThread()
{
}

void QuickSortThread::_quicksort(int left, int right)
{
    int i, j, stan, temp;
    if (left > right){
        return ;
    }
 
    stan = m_random_vector[left];
    i = left;
    j = right;
 
    while (i != j){
        while (m_random_vector[j] >= stan && i < j){
            j--;
        }
        while (m_random_vector[i] <= stan && i < j) {
            i++;
        }
        if (j > i){
            temp = m_random_vector[i];
            m_random_vector[i] = m_random_vector[j];
            m_random_vector[j] = temp;
        }
    }
 
    m_random_vector[left] = m_random_vector[i];
    m_random_vector[i] = stan;
 
    _quicksort(left, i - 1);
    _quicksort(i + 1, right);
 
}

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

void QuickSortThread::run()
{
    long long start_us = _getStartTimeUs();
    _quicksort(0, m_random_vector.size() - 1);
    long long interval_us = _getIntervalFromStartTimeUs(start_us);

    qDebug() << interval_us / 1000.0 << "ms";

    emit quickSortOver(m_random_vector);
}

void QuickSortThread::getNumFromMainThread(QVector<int> random_vector)
{
    m_random_vector = random_vector;
}

