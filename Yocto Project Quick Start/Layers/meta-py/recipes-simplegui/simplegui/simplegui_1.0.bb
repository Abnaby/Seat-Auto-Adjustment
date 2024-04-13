# meta-simplegui/recipes-gui/simplegui/simplegui_1.0.bb

SUMMARY = "Simple GUI application"
DESCRIPTION = "A simple GUI application using Tkinter"

LICENSE = "CLOSED"

SRC_URI = "file://simplegui.py"

S = "${WORKDIR}"

RDEPENDS_${PN} = "python3-tkinter"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 simplegui.py ${D}${bindir}
}
