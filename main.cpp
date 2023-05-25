#include <QApplication>
#include <QVBoxLayout>
#include <QTextEdit>
#include "test.h"
#include <QWindow>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test w;
    w.show();
    return QApplication::exec();
}
