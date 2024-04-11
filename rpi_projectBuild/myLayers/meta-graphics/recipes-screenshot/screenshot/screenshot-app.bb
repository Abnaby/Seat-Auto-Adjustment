SUMMARY = "Auto Seat Positioning GUI application"
DESCRIPTION = "The GUI application using QT5"

LICENSE = "CLOSED"

DEPENDS += "qtbase wayland "

SRC_URI = "file://screenshot.cpp \
           file://screenshot.pro \
          "

S = "${WORKDIR}"

do_install:append () {
    install -d ${D}${bindir}
    install -m 0755 screenshot ${D}${bindir}
    export QT_QPA_PLATFORM=wayland:xcb
}

FILES_${PN} += "${bindir}/screenshot"
inherit qmake5

