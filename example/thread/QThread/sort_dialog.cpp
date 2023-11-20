/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    sort_dialog.cpp
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/05 2021 19:26
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/05 2021      create the file
 * 
 *     last modified: 06/05 2021 19:26
 */
#include <QDebug>

#include <hy_log/hy_log.h>

#include <hy_utils/hy_mem.h>

#include "sort_dialog.h"
#ifdef AUTOTOOLS_COMPILE
#   include "sort_dialog.ui.h"
#else
#   include "ui_sort_dialog.h"
#endif

static inline void _set_list_item(QListWidget *list, QVector<int> &vector)
{
    for (QVector<int>::iterator i = vector.begin(); i != vector.end(); ++i) {
        list->addItem(QString::number(*i));
    }
}

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    HyLogConfig_s log_c;
    HY_MEMSET(&log_c, sizeof(HyLogConfig_s));
    log_c.port                      = 56789;
    log_c.fifo_len                  = 10 * 1024;
    log_c.config_file               = "../res/hy_log/zlog.conf";
    log_c.save_c.level              = HY_LOG_LEVEL_INFO;
    log_c.save_c.output_format      = HY_LOG_OUTFORMAT_ALL_NO_PID_ID;
    HyLogInit(&log_c);

    m_random_thread = new RandomThread;
    m_bubble_sort_thread = new BubbleSortThread;
    m_quick_sort_thread = new QuickSortThread;

    connect(this, &SortDialog::setRandomNum,
            m_random_thread, &RandomThread::getRandomNum);
    connect(ui->startButton, &QPushButton::clicked,
            this, [=](){
                emit setRandomNum(10 * 1000);
                m_random_thread->start();
            });

    connect(m_random_thread, &RandomThread::randomNumDown,
            m_bubble_sort_thread, &BubbleSortThread::recvArray);
    connect(m_random_thread, &RandomThread::randomNumDown,
            m_quick_sort_thread, &QuickSortThread::recvArray);
    connect(m_random_thread, &RandomThread::randomNumDown,
            this, [=](QVector<int> list){
                _set_list_item(ui->randomList, list);

                m_bubble_sort_thread->start();
                m_quick_sort_thread->start();
            });

    connect(m_bubble_sort_thread, &BubbleSortThread::finish,
            this, [=](QVector<int> list){
                _set_list_item(ui->bubbleSortList, list);
            });
    connect(m_quick_sort_thread, &QuickSortThread::finish,
            this, [=](QVector<int> list){
                _set_list_item(ui->quickSortList, list);
            });

    connect(this, &SortDialog::destroyed,
            this, [=](){
                delete m_random_thread;
                delete m_bubble_sort_thread;
                delete m_quick_sort_thread;
            });
}

SortDialog::~SortDialog()
{
    HyLogDeInit();

    delete ui;
}

