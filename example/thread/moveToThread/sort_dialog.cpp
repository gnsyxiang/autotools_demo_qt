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
#include <QThread>

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

static inline void _delete_thread(QThread *thread)
{
    thread->quit();
    thread->wait();
    delete thread; //t3->deleteLater();
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

    QThread *t1 = new QThread;
    QThread *t2 = new QThread;
    QThread *t3 = new QThread;

    // 不能指定this指针，否则不能移动到线程中去
    m_random = new Random;
    m_bubbleSort = new BubbleSort;
    m_quickSort = new QuickSort;

    m_random->moveToThread(t1);
    m_bubbleSort->moveToThread(t2);
    m_quickSort->moveToThread(t3);

    connect(this, &SortDialog::setRandomNum, m_random, &Random::working);
    connect(ui->startButton, &QPushButton::clicked,
            this, [=](){
                emit setRandomNum(10 * 1000);
                t1->start();
            });

    connect(m_random, &Random::randomNumDown,
            m_bubbleSort, &BubbleSort::working);
    connect(m_random, &Random::randomNumDown,
            m_quickSort, &QuickSort::working);
    connect(m_random, &Random::randomNumDown,
            this, [=](QVector<int> list){
                _set_list_item(ui->randomList, list);

                t2->start();
                t3->start();
            });

    connect(m_bubbleSort, &BubbleSort::finish,
            this, [=](QVector<int> list){
                _set_list_item(ui->bubbleSortList, list);
            });
    connect(m_quickSort, &QuickSort::finish,
            this, [=](QVector<int> list){
                _set_list_item(ui->quickSortList, list);
            });

    connect(this, &SortDialog::destroyed,
            this, [=](){
                _delete_thread(t1);
                _delete_thread(t2);
                _delete_thread(t3);

                delete m_random;
                delete m_bubbleSort;
                delete m_quickSort;
            });
}

SortDialog::~SortDialog()
{
    HyLogDeInit();

    delete ui;
}

