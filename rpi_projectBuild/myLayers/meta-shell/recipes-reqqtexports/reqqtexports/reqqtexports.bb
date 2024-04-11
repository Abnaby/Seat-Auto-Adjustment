SUMMARY = "A simple shell to print display"
DESCRIPTION = "This recipe installs a shell script."

LICENSE = "CLOSED"

SRC_URI = "file://reqqtexports.sh"

S = "${WORKDIR}"

RDEPENDS:reqqtexports = " bash"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 reqqtexports.sh ${D}${bindir}
}



inherit allarch
