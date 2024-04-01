# Recipe Name: helloQt
# Version: 1.0
# License: Proprietary (CLOSED)
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
}

FILES_${PN} += "${bindir}/helloQt"
inherit qmake5