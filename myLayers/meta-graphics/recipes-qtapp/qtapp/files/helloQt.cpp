#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
#include <QProcess>

#define ENABLE_DEBUG 0

#define APP_NAME "algorithmAppPath"
#define NEW_APP_PATH  "/usr/bin/algorithmAppPath"

static void startAlgoApp(QString weightStr , QString heightStr);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Fonts
    QFont UsedFonts ;
    UsedFonts.setPixelSize(25);
    // Create main window
    QWidget mainWindow;
    mainWindow.resize(800, 200); // Set window size to 800x200 pixels

    QVBoxLayout layout(&mainWindow);
    // Create label
    QLabel hello("<center>Automatic Seat positioning : </center>");
    hello.setFont(UsedFonts);
    hello.setWindowTitle("Automatic Seat positioning ");

    // Create input fields for weight and height with validators
    QLabel weightLabel("Weight:");
    weightLabel.setFont(UsedFonts);
    QLineEdit weightInput;
    weightInput.setFont(UsedFonts);
    weightInput.setValidator(new QIntValidator(0, 99999, &weightInput)); // Accept integers between 0 and 99999
    QLabel heightLabel("Height:");
     heightLabel.setFont(UsedFonts);
    QLineEdit heightInput;
     heightInput.setFont(UsedFonts);
    heightInput.setValidator(new QIntValidator(0, 99999, &heightInput)); // Accept integers between 0 and 99999

    // Create button
    QPushButton BTN_startProcess("Start seat positioning");
    BTN_startProcess.setFont(UsedFonts);
    // Add widgets to layout
    layout.addWidget(&hello);
    layout.addWidget(&weightLabel);
    layout.addWidget(&weightInput);
    layout.addWidget(&heightLabel);
    layout.addWidget(&heightInput);
    layout.addWidget(&BTN_startProcess);

    // Connect button click signal
    QObject::connect(&BTN_startProcess, &QPushButton::clicked, [&]() {
        // Retrieve weight and height values
        QString weight = weightInput.text();
        QString height = heightInput.text();
        if (weight.isEmpty() || height.isEmpty()) {
            #if ENABLE_DEBUG == 1
            qDebug() << "Invalid Inputs\n";
            #endif
            return;
        }
        else
        {
            #if ENABLE_DEBUG == 1
            qDebug() << "Weight:" << weight;
            qDebug() << "Height:" << height;
            #endif
        }
        startAlgoApp(weight,height);    
    });
    // Show the main window
    mainWindow.show();

    return app.exec();
}

void startAlgoApp(QString weightStr , QString heightStr)
{
    // Convert string values to integers
    int weight = weightStr.toInt();
    int height = heightStr.toInt();
    // Start the algorithm application with the provided inputs using QProcess
    QString algorithmAppPath = NEW_APP_PATH; 
    QStringList arguments;
    arguments << QString::number(weight) << QString::number(height); // Pass weight and height as arguments
    QProcess::startDetached(APP_NAME, arguments);
}