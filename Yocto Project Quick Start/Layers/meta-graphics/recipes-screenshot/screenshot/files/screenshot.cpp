#include <QApplication>
#include <QScreen>
#include <QPixmap>
#include <QDateTime>
#include <QDebug>
#include <QFile>


#define SAVE_IN_PATH "/home/weston/screenshot_"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Get the primary screen
    QScreen *screen = QGuiApplication::primaryScreen();

    // Capture the whole screen
    QPixmap screenshot = screen->grabWindow(0);

    // Generate a filename based on current timestamp and specify the path
    QString fileName = SAVE_IN_PATH +
            QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss") + ".png";

    // Save the screenshot in the specified directory
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open file for writing:" << file.errorString();
        return 1;
    }

    if (!screenshot.save(&file, "PNG")) {
        qWarning("Failed to save screenshot.");
        return 1;
    }

    return 0;
}
