/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    bubble_sort.cpp
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
#include <QThread>

#include <hy_log/hy_log.h>

#include <hy_utils/hy_sort.h>

#include "bubble_sort.h"

BubbleSortRunnable::BubbleSortRunnable(QObject *parent) :
    QThread(parent),
    QRunnable()
{
    setAutoDelete(true);
}

BubbleSortRunnable::~BubbleSortRunnable()
{
}

static hy_s32_t _swap_int_cb(void *src, void *dst)
{
    hy_s32_t  *a = (hy_s32_t *)src;
    hy_s32_t  *b = (hy_s32_t *)dst;

    return *a - *b;
}

void BubbleSortRunnable::run()
{
    LOGD("thread id: %p \n", QThread::currentThreadId());

    HySortBubble(m_list.data(), m_list.size(), sizeof(m_list[0]),  _swap_int_cb);

    emit finish(m_list);
}

void BubbleSortRunnable::recvArray(QVector<int> list)
{
    m_list = list;
}

