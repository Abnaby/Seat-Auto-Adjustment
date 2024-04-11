DESCRIPTION = "Simple GTK helloworld application"
SECTION = "examples"
LICENSE = "CLOSED"

SRC_URI = "file://gtk_hello_world.c"

S = "${WORKDIR}"

DEPENDS = "gtk+"

inherit pkgconfig

do_compile() {
        ${CC} ${LDFLAGS} gtk_hello_world.c -o helloworld `pkg-config --cflags --libs gtk+-2.0`
}

do_install() {
        install -d ${D}${bindir}
        install -m 0755 helloworld ${D}${bindir}
}

