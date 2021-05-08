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

#include "sort_dialog.h"
#include "sort_dialog.ui.h"

#include "hy_utils/hy_log.h"

#define ALONE_DEBUG 1
#define LOG_CATEGORY_TAG "sort_dialog"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    HyLogCreate(HY_LOG_LEVEL_INFO, 512);

    m_random_thread = new RandomThread(this);
    m_bubble_sort_thread = new BubbleSortThread(this);
    m_quick_sort_thread = new QuickSortThread(this);

    connect(this, &SortDialog::setRandomNum, m_random_thread, &RandomThread::getRandomNum);
    connect(ui->startButton, &QPushButton::clicked,
            this, [=](){
                emit setRandomNum(10 * 1000);
                m_random_thread->start();
            });

    connect(m_random_thread, &RandomThread::randomNumDown,
            this, [=](QVector<int> list){
              for (QVector<int>::iterator i = list.begin(); i != list.end(); ++i) {
                ui->randomList->addItem(QString::number(*i));
              }

              m_bubble_sort_thread->start();
              m_quick_sort_thread->start();
            });
    connect(m_random_thread, &RandomThread::randomNumDown, m_bubble_sort_thread, &BubbleSortThread::recvArray);
    connect(m_random_thread, &RandomThread::randomNumDown, m_quick_sort_thread, &QuickSortThread::recvArray);

    connect(m_bubble_sort_thread, &BubbleSortThread::finish,
            this, [=](QVector<int> list){
              for (QVector<int>::iterator i = list.begin(); i != list.end(); ++i) {
                ui->bubbleSortList->addItem(QString::number(*i));
              }
            });
    connect(m_quick_sort_thread, &QuickSortThread::finish,
            this, [=](QVector<int> list){
              for (QVector<int>::iterator i = list.begin(); i != list.end(); ++i) {
                  ui->quickSortList->addItem(QString::number(*i));
              }
            });
}

SortDialog::~SortDialog()
{
    HyLogDestroy();

    delete ui;
}

