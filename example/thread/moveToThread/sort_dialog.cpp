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
            this, [=](QVector<int> list){
              for (QVector<int>::iterator i = list.begin(); i != list.end(); ++i) {
                ui->randomList->addItem(QString::number(*i));
              }

              t2->start();
              t3->start();
            });
    connect(m_random, &Random::randomNumDown, m_bubbleSort, &BubbleSort::working);
    connect(m_random, &Random::randomNumDown, m_quickSort, &QuickSort::working);

    connect(m_bubbleSort, &BubbleSort::finish,
            this, [=](QVector<int> list){
              for (QVector<int>::iterator i = list.begin(); i != list.end(); ++i) {
                ui->bubbleSortList->addItem(QString::number(*i));
              }
            });
    connect(m_quickSort, &QuickSort::finish,
            this, [=](QVector<int> list){
              for (QVector<int>::iterator i = list.begin(); i != list.end(); ++i) {
                  ui->quickSortList->addItem(QString::number(*i));
              }
            });

    connect(this, &SortDialog::destroy,
            this, [=](){
              t1->quit(); 
              t1->wait();
              delete t1;

              t2->quit(); 
              t2->wait();
              delete t2;

              t3->quit(); 
              t3->wait();
              delete t3; //t3->deleteLater();

              delete m_random;
              delete m_bubbleSort;
              delete m_quickSort;
            });
}

SortDialog::~SortDialog()
{
    HyLogDestroy();

    delete ui;
}

