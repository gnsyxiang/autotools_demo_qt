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

#include <hy_log/hy_log.h>

#include <hy_utils/hy_sort.h>

#include "quick_sort_thread.h"

QuickSortThread::QuickSortThread(QObject *parent) :
    QThread(parent)
{
}

QuickSortThread::~QuickSortThread()
{
}

static hy_s32_t _swap_int_cb(void *src, void *dst)
{
    hy_s32_t  *a = (hy_s32_t *)src;
    hy_s32_t  *b = (hy_s32_t *)dst;

    return *a - *b;
}

void QuickSortThread::run()
{
    HySortQuick(m_list.data(), 0, m_list.size(), sizeof(m_list[0]),  _swap_int_cb);

    emit finish(m_list);
}

void QuickSortThread::recvArray(QVector<int> list)
{
    m_list = list;
}

