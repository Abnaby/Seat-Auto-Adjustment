SUMMARY = "Auto Seat Positioning GUI application"
DESCRIPTION = "The GUI application using QT5"

LICENSE = "CLOSED"

DEPENDS += "qtbase wayland "

SRC_URI = "file://QT_GUI.cpp \
           file://QT_GUI.pro \
          "

S = "${WORKDIR}"

do_install:append () {
    install -d ${D}${bindir}
    install -m 0755 QT_GUI ${D}${bindir}
    export QT_QPA_PLATFORM=wayland:xcb
}

FILES_${PN} += "${bindir}/QT_GUI"
inherit qmake5