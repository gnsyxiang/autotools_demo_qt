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
#include <QThreadPool>

#include "sort_dialog.h"
#include "ui_sort_dialog.h"

#include "hy_utils/hy_log.h"

#define ALONE_DEBUG 1
#define LOG_CATEGORY_TAG "sort_dialog"

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

    HyLogCreate(HY_LOG_LEVEL_INFO, 512);

    connect(ui->startButton, &QPushButton::clicked,
            this, &SortDialog::handle_start_clicked);

    LOGD("thread id: %p \n", QThread::currentThreadId());
}

SortDialog::~SortDialog()
{
    HyLogDestroy();

    delete ui;
}

void SortDialog::handle_start_clicked(void)
{
    m_random_runnable = new RandomRunnable;
    m_bubble_sort_runnable = new BubbleSortRunnable;
    m_quick_sort_runnable = new QuickSortRunnable;

    connect(this, &SortDialog::setRandomNum,
            m_random_runnable, &RandomRunnable::getRandomNum);

    emit setRandomNum(10 * 1000);
    QThreadPool::globalInstance()->start(m_random_runnable);

    connect(m_random_runnable, &RandomRunnable::randomNumDown,
            m_bubble_sort_runnable, &BubbleSortRunnable::recvArray);
    connect(m_random_runnable, &RandomRunnable::randomNumDown,
            m_quick_sort_runnable, &QuickSortRunnable::recvArray);
    connect(m_random_runnable, &RandomRunnable::randomNumDown,
            this, [=](QVector<int> list){
                _set_list_item(ui->randomList, list);

                QThreadPool::globalInstance()->start(m_bubble_sort_runnable);
                QThreadPool::globalInstance()->start(m_quick_sort_runnable);
            });

    connect(m_bubble_sort_runnable, &BubbleSortRunnable::finish,
            this, [=](QVector<int> list){
                _set_list_item(ui->bubbleSortList, list);
            });
    connect(m_quick_sort_runnable, &QuickSortRunnable::finish,
            this, [=](QVector<int> list){
                _set_list_item(ui->quickSortList, list);
            });
}

