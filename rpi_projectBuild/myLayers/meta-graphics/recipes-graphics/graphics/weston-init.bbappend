FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " \
    file://background.jpg \
    file://terminalIcon.png \
    file://seat.png \
    file://weston.ini\
"

do_install:append() {
    install -D -m 0644 weston.ini ${D}${sysconfdir}/xdg/weston/weston.ini
    install -D -m 0644 background.jpg ${D}/usr/share/backgrounds/custom/background.jpg
    install -D -m 0644 terminalIcon.png ${D}/usr/share/icons/32x32/apps/terminalIcon.png
    install -D -m 0644 seat.png ${D}/usr/share/icons/32x32/apps/seat.png
}

FILES:${PN} += "/usr/share/backgrounds/custom/background.jpg \
                /usr/share/icons/32x32/apps/terminalIcon.png \
                /usr/share/icons/32x32/apps/seat.png"
