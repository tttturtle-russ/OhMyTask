#include <QApplication>
#include <QVBoxLayout>
#include <QTextEdit>
#include "test.h"
#include <QWindow>
#include "third-party/nlohmann/json.hpp"
#include <iostream>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test w;
    w.show();
    return QApplication::exec();
    std::string s("123123");
    std::cout << std::all_of(s.begin(), s.end(), ::isdigit) << std::endl;
}
