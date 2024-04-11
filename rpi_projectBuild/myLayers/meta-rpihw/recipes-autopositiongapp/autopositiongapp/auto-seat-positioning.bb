SUMMARY = "Prebuilt auto seat positioning app"
DESCRIPTION = "Prebuilt auto seat positioning that build on rpi3 hardware."
LICENSE = "CLOSED"

DEPENDS = "wiringpi"

S = "${WORKDIR}"

SRC_URI = " \
    file://AutoSeatPositioning \
"

do_install() {
    install -D -m 0755 AutoSeatPositioning ${D}/usr/bin/AutoSeatPositioning 
}


FILES:${PN} += "/usr/bin/AutoSeatPositioning  \
                "