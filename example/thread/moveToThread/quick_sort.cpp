/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    quick_sort.cpp
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

#include "quick_sort.h"

#include "hy_utils/hy_log.h"
#include "hy_hal/hy_time.h"

#define ALONE_DEBUG 1
#define LOG_CATEGORY_TAG "quick_sort"

QuickSort::QuickSort(QObject *parent) :
    QObject(parent)
{
}

QuickSort::~QuickSort()
{
}

void QuickSort::_quicksort(int left, int right)
{
    int i, j, stan, temp;
    if (left > right){
        return ;
    }
 
    stan = m_list[left];
    i = left;
    j = right;
 
    while (i != j){
        while (m_list[j] >= stan && i < j){
            j--;
        }
        while (m_list[i] <= stan && i < j) {
            i++;
        }
        if (j > i){
            temp = m_list[i];
            m_list[i] = m_list[j];
            m_list[j] = temp;
        }
    }
 
    m_list[left] = m_list[i];
    m_list[i] = stan;
 
    _quicksort(left, i - 1);
    _quicksort(i + 1, right);
 
}

void QuickSort::working(QVector<int> list)
{
    m_list = list;

    hy_uint64_t start_us = HyTimeGetCurrentTime2Us();

    _quicksort(0, m_list.size() - 1);

    hy_uint64_t interval_us = HyTimeGetTimeInterval(start_us);

    LOGD("interval_us: %lld \n", interval_us);

    emit finish(m_list);
}

