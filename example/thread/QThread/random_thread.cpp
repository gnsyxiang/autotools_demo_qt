/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    random_thread.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 19:30
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 19:30
 */
#include <QDebug>

#include "random_thread.h"

RandomThread::RandomThread(QObject *parent) :
    QThread(parent)
{
}

RandomThread::~RandomThread()
{
}

#if 1
#include <QRandomGenerator>

static void _getRandomNum(int cnt, QVector<int> &random_vector)
{
    for (int i = 0; i < cnt; ++i) {
        int rand = QRandomGenerator::global()->bounded(cnt);
        random_vector.push_back(rand);
    }
}
#else
#include <QTime>

static void _getRandomNum(int cnt, QVector<int> &random_vector)
{
    QTime time;
    time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000);

    for (int i = 0; i < cnt; ++i) {
        int rand = qrand() % cnt;
        random_vector.push_back(rand);
    }
}
#endif

void RandomThread::run()
{
    QVector<int> random_vector;
    _getRandomNum(m_cnt, random_vector);

    emit randomNumDown(random_vector);
}

void RandomThread::getRandomNum(int cnt)
{
    m_cnt = cnt;
}
