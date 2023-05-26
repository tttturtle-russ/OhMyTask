/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QCheckBox>
#include <QString>
#include "third-party/nlohmann/json.hpp"
#include <iostream>
QT_BEGIN_NAMESPACE

using nlohmann::json;

class Ui_test
{
public:
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    std::function<void()> onOk = [&]() {
        nlohmann::basic_json i;
        if (textEdit->toPlainText().toStdString().find_first_not_of("0123456789") == std::string::npos){
            auto checkbox = new QCheckBox(textEdit->toPlainText(),verticalLayoutWidget);
            std::cout << textEdit->toPlainText().toStdString() << std::endl;
            checkbox->adjustSize();
            QObject::connect(checkbox, &QCheckBox::clicked, checkbox, &QCheckBox::deleteLater);
            verticalLayout->addWidget(checkbox);
            textEdit->clear();
            return;
        }
        try {
            i = json::parse(textEdit->toPlainText().toStdString());
        } catch (json::parse_error ) {
            // handle it as raw string
            auto checkbox = new QCheckBox(textEdit->toPlainText(),verticalLayoutWidget);
            checkbox->adjustSize();
            QObject::connect(checkbox, &QCheckBox::clicked, checkbox, &QCheckBox::deleteLater);
            verticalLayout->addWidget(checkbox);
            textEdit->clear();
            return;
        }
        for (auto &item : i.items()) {
            if (item.value().is_array()) {
                for (const auto &i: item.value().get<std::vector<std::string>>()){
                    auto newCheckBox = new QCheckBox(verticalLayoutWidget);
                    newCheckBox->setText(QString::fromStdString(i));
                    newCheckBox->adjustSize();
                    QObject::connect(newCheckBox, &QCheckBox::clicked, newCheckBox, &QCheckBox::deleteLater);
                    verticalLayout->addWidget(newCheckBox);
                }
                continue;
            }
            auto newCheckBox = new QCheckBox(verticalLayoutWidget);
            if (item.value().is_string()) {
                newCheckBox->setText(QString::fromStdString(item.value().get<std::string>()));
                newCheckBox->adjustSize();
                QObject::connect(newCheckBox, &QCheckBox::clicked, newCheckBox, &QCheckBox::deleteLater);
                verticalLayout->addWidget(newCheckBox);
            }
        }
    };
    std::function<void()> onCancel = [&]() {
        textEdit->clear();
    };

    void setupUi(QWidget *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName("test");
        test->resize(391, 300);
        textEdit = new QTextEdit(test);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 0, 391, 131));
        buttonBox = new QDialogButtonBox(test);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(250, 140, 128, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(test);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 170, 371, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, test, onOk);
        QObject::connect(buttonBox,&QDialogButtonBox::rejected, test, onCancel);
        retranslateUi(test);
        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QWidget *test)
    {
        test->setWindowTitle(QCoreApplication::translate("test", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
