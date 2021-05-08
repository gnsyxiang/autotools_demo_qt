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

#include "hy_utils/hy_log.h"
#include "hy_hal/hy_time.h"

#define ALONE_DEBUG 1
#define LOG_CATEGORY_TAG "bubble_sort_thread"

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

void BubbleSortThread::_bubble_sort(QVector<int> &list)
{
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j + 1 < list.size()  - i; j++) {
            if (list[j] > list[j + 1]) {
                _swap(&list[j], &list[j + 1]);
            }
        }
    }
}

void BubbleSortThread::run()
{
    hy_uint64_t start_us = HyTimeGetCurrentTime2Us();

    _bubble_sort(m_list);

    hy_uint64_t interval_us = HyTimeGetTimeInterval(start_us);

    LOGD("interval_us: %lld \n", interval_us);

    emit finish(m_list);
}

void BubbleSortThread::recvArray(QVector<int> list)
{
    m_list = list;
}

