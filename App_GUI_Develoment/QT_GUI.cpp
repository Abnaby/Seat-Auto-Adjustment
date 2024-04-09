#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
#include <QProcess>
#include <QMessageBox>
#include <QTimer>

#define ENABLE_DEBUG 0

#if ENABLE_DEBUG == 1
#include <QFile>
#include <QTextStream>
#endif
/************************************************
 ******************* MACROS *******************
 ***********************************************/
#define IN_EDIT_MODE_IDX 1
#define IN_DRIVER_ID_IDX 2
#define IN_WEIGHT_IDX 3
#define IN_HEIGHT_IDX 4
#define NEW_APP_PATH  "D:/OJT/0.Repo/App_GUI_Develoment/release/algorithmAppPath.exe"

#define DELAY_TIME 3000

/************************************************
 ******************* STATIC VAR ****************
 ***********************************************/
static QTimer timer;

/************************************************
 ******************* STATIC FUNC ****************
 ***********************************************/
static void startAlgoApp(QString weightStr, QString heightStr);

static void confirmationMsg()
{
    // Set up the timer if it's not already running
    if (!timer.isActive()) {
        // Set a timeout of DELAY_TIME milliseconds
        timer.setSingleShot(true);
        timer.start(DELAY_TIME);
    }

    // Connect the timer's timeout signal to a lambda function
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        // Create a QMessageBox
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText("Seat positioning is completed");
        msgBox.setInformativeText("Is the new position suitable?");
        msgBox.addButton("Everything OK", QMessageBox::AcceptRole);
        msgBox.addButton("Control it Manually", QMessageBox::RejectRole);
        int ret = msgBox.exec();

        // Check which button the user clicked
        if (ret == QMessageBox::AcceptRole || ret == QMessageBox::RejectRole) {
            // Quit the application
            QCoreApplication::quit();
        }
    });
}

/************************************************
 ******************* APP ************************
 ***********************************************/
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Fonts
    QFont UsedFonts;
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
    QObject::connect(&BTN_startProcess, &QPushButton::clicked, [&]()
                     {
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
        startAlgoApp(weight,height); });
    // Show the main window
    mainWindow.show();

    return app.exec();
}

void startAlgoApp(QString weightStr, QString heightStr)
{
    // Convert string values to integers
    int weight = weightStr.toInt();
    int height = heightStr.toInt();
    // Start the algorithm application with the provided inputs using QProcess
    QString algorithmAppPath = NEW_APP_PATH;
    QStringList arguments;
    //          IN_EDIT_MODE_IDX  IN_DRIVER_ID_IDX  IN_WEIGHT_IDX           IN_HEIGHT_IDX
    arguments << QString::number(1) << QString::number(0) << QString::number(weight) << QString::number(height);

    bool started = QProcess::startDetached(algorithmAppPath, arguments);
    if (started)
    {
        // If the process started successfully, wait for it to finish
        // This approach might block the main thread, consider using QProcess::start instead
        QProcess process;
        process.start(algorithmAppPath, arguments);
        process.waitForFinished();
        // Get the exit code of the process
        int exitCode = process.exitCode();
        if (exitCode == 0)
        {
            // If exit code is 0, show a popup window indicating operation failed
            QMessageBox::critical(nullptr, "Operation Failed", "The operation failed.");
            // show options [LATER ADDSON]
        }
        else
        {
            confirmationMsg();
        }
#if ENABLE_DEBUG == 1
        // Write the exit code to a file
        QFile file("exit_code.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << exitCode;
            file.close();
        }
        else
        {
            qDebug() << "Failed to open file for writing";
        }
#endif
    }
    else
    {
        QMessageBox::critical(nullptr, "Process Error", "Failed to start the process.");
    }
#if ENABLE_DEBUG == 1
    qDebug() << "Failed to start the process";
#endif
}