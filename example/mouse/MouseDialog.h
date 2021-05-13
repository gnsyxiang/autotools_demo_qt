/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    MouseDialog.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    10/05 2021 18:52
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        10/05 2021      create the file
 * 
 *     last modified: 10/05 2021 18:52
 */
#ifndef __EXAMPLE_MOUSE_MOUSE_DIALOG_H_
#define __EXAMPLE_MOUSE_MOUSE_DIALOG_H_

#include <QDialog>

namespace Ui {
    class Dialog;
}

class MouseDialog : public QDialog {
    Q_OBJECT

public:
    explicit MouseDialog(QWidget *parent = nullptr);
    virtual ~MouseDialog();

protected:
    void mousePressEvent(QMouseEvent *event);        //单击
    void mouseReleaseEvent(QMouseEvent *event);      //释放
    void mouseDoubleClickEvent(QMouseEvent *event);  //双击
    void mouseMoveEvent(QMouseEvent *event);         //移动
    void wheelEvent(QWheelEvent *event);             //滑轮

private:
    Ui::Dialog *ui;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif

