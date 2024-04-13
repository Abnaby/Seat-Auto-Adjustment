SUMMARY = "Recipe for C++ apps"
DESCRIPTION = "This Recipe contain all source file related to c++"
LICENSE = "CLOSED"

SRC_URI = "file://rectangleArea.cpp"

S = "${WORKDIR}"

do_compile() {
    ${CXX} ${CXXFLAGS} ${LDFLAGS} rectangleArea.cpp -o algorithmAppPath
}
do_install() {
    install -d ${D}${bindir}
    install -m 0755 algorithmAppPath ${D}${bindir}
}