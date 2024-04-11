SUMMARY = "Simple GUI application"
DESCRIPTION = "A simple GUI application using QT5"

LICENSE = "CLOSED"

DEPENDS += "qtbase wayland "

SRC_URI = "file://helloQt.cpp \
           file://helloQt.pro \
          "

S = "${WORKDIR}"

do_install:append () {
    install -d ${D}${bindir}
    install -m 0755 helloQt ${D}${bindir}
    export QT_QPA_PLATFORM=wayland:xcb
}

FILES_${PN} += "${bindir}/helloQt"
inherit qmake5