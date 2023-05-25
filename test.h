//
// Created by russ on 2023/5/25.
//

#ifndef OHMYTASK_TEST_H
#define OHMYTASK_TEST_H

#include <QWidget>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class test; }
QT_END_NAMESPACE

class test : public QWidget {
Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    ~test() override;

private:
    Ui::test *ui;
};


#endif //OHMYTASK_TEST_H
