# This is a sample Qt project file (.pro) for building a simple Qt application.

# Set the type of project (app, lib, etc.)
TEMPLATE = app

# Specify the name of the output binary (executable or library)
TARGET = helloQt

# Specify the include path for header files (current directory in this case)
INCLUDEPATH += .

# Specify the Qt modules required by the application
QT += gui widgets

# Add a define to enable deprecated warnings from Qt
DEFINES += QT_DEPRECATED_WARNINGS

# List the source files (.cpp files) that are part of the project
SOURCES += helloQt.cpp