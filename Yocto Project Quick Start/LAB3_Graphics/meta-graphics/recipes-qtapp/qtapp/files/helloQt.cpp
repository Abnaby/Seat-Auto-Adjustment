#include <QApplication>
#include <QLabel>
#include <QWidget>

int main (int argc, char *argv[])
{
    QApplication app(argc,argv);
    QLabel hello("<center>HELLO QT WORLD</center>");
    hello.setWindowTitle("QT Hello App");
    hello.resize(200,200);
    hello.show();
    return app.exec();
}