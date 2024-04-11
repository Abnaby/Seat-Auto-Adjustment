SUMMARY = "Prebuilt WiringPi Library"
DESCRIPTION = "Prebuilt WiringPi library and binaries for Raspberry Pi."
LICENSE = "CLOSED"



ABS_PATH_TO_FILES = "/home/abnaby/yocto/myLayers/meta-rpihw/recipes-wiringpi/wiringPi/files"

DEPENDS = "libgpiod sudo"


S = "${WORKDIR}"

# Defines the suffix for shared libraries used on the target platform
SOLIBS = ".so"
FILES_SOLIBSDEV = ""

do_install() {
    # Create directory in the rootfs for library files
    install -d ${D}/usr/lib
    # Install library files to the rootfs directory ${libdir} = /usr/lib
    install -m 0755 ${ABS_PATH_TO_FILES}/lib/* ${D}${libdir}
}

# Define which files to package
FILES_${PN} += "${libdir}/libwiringPi.so"
FILES_${PN} += "${libdir}/libwiringPiDev.so"