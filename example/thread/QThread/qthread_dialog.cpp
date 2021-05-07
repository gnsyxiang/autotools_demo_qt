/**
 *
 * Release under GPLv-3.0.
 * 
 * @file    qthread_dialog.cpp
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

#include "qthread_dialog.h"
#include "qthread_dialog.ui.h"

QthreadDialog::QthreadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    random_thread = new RandomThread();
    bubble_sort_thread = new BubbleSortThread();
    quick_sort_thread = new QuickSortThread();

    connect(this, &QthreadDialog::setRandomNum, random_thread, &RandomThread::getRandomNum);
    connect(random_thread, &RandomThread::randomNumDown, this, &QthreadDialog::getRandomNumFromThread);

    connect(this, &QthreadDialog::startSort, bubble_sort_thread, &BubbleSortThread::getNumFromMainThread);
    connect(bubble_sort_thread, &BubbleSortThread::bubbleSortOver, this, &QthreadDialog::getRandomNumFromBubbleSortThread);

    connect(this, &QthreadDialog::startSort, quick_sort_thread, &QuickSortThread::getNumFromMainThread);
    connect(quick_sort_thread, &QuickSortThread::quickSortOver, this, &QthreadDialog::getRandomNumFromQuickSortThread);

    connect(ui->startButton, &QPushButton::clicked,
            this, [=](){
                emit setRandomNum(10 * 1000);
                random_thread->start();
            });
}

QthreadDialog::~QthreadDialog()
{
    delete ui;
}

void QthreadDialog::getRandomNumFromThread(QVector<int> random_vector)
{
    for (QVector<int>::iterator i = random_vector.begin(); i != random_vector.end(); ++i) {
        ui->randomList->addItem(QString::number(*i));
    }
    emit startSort(random_vector);
    bubble_sort_thread->start();
    quick_sort_thread->start();
}

void QthreadDialog::getRandomNumFromBubbleSortThread(QVector<int> random_vector)
{
    for (QVector<int>::iterator i = random_vector.begin(); i != random_vector.end(); ++i) {
        ui->bubbleSortList->addItem(QString::number(*i));
    }
}

void QthreadDialog::getRandomNumFromQuickSortThread(QVector<int> random_vector)
{
    for (QVector<int>::iterator i = random_vector.begin(); i != random_vector.end(); ++i) {
        ui->quickSortList->addItem(QString::number(*i));
    }
}

