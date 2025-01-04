#include <MainWindow.h>
#include <QApplication>
#include <Qontrol>
#include <qlogging.h>

auto main(int argc, char *argv[]) -> int {
    QApplication app(argc, argv);

    MainWindow window;
    window.setFixedSize(800,800);
    window.setWindowTitle("Qontrol example");
    window.show();

    return QApplication::exec();
}
