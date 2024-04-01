SUMMARY = "Set Qt Environment Variables at Boot Time"
DESCRIPTION = "A recipe to set Qt environment variables at boot time."

LICENSE = "CLOSED"

SRC_URI = "file://set_qt_environment.sh"


S = "${WORKDIR}"

# RDEPENDS:reqqtexports = " bash"
RDEPENDS:${PN} = " bash"

do_install() {
    install -d ${D}/etc/profile.d
    install -m 0755 ${WORKDIR}/set_qt_environment.sh ${D}/etc/profile.d/
}

inherit allarch
