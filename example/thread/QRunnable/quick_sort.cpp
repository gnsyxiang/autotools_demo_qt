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
#include <QThread>

#include "quick_sort.h"

#include "hy_hal/hy_time.h"

#include "hy_utils/hy_sort.h"
#include "hy_utils/hy_log.h"

#define ALONE_DEBUG 1
#define LOG_CATEGORY_TAG "quick_sort"

QuickSortRunnable::QuickSortRunnable(QObject *parent) :
    QThread(parent),
    QRunnable()
{
    setAutoDelete(true);
}

QuickSortRunnable::~QuickSortRunnable()
{
}

static hy_int32_t _swap_int_cb(void *src, void *dst)
{
    hy_int32_t  *a = (hy_int32_t *)src;
    hy_int32_t  *b = (hy_int32_t *)dst;

    return *a - *b;
}

void QuickSortRunnable::run()
{
    LOGD("thread id: %p \n", QThread::currentThreadId());

    hy_uint64_t start_us = HyTimeGetCurrentTime2Us();

    HySortQuick(m_list.data(), 0, m_list.size(), sizeof(m_list[0]),  _swap_int_cb);

    hy_uint64_t interval_us = HyTimeGetTimeInterval(start_us);

    LOGD("interval_us: %lld \n", interval_us);

    emit finish(m_list);
}

void QuickSortRunnable::recvArray(QVector<int> list)
{
    m_list = list;
}

