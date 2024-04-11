SUMMARY = "Recipe for C++ apps"
DESCRIPTION = "This Recipe contain all source file related to c++"
LICENSE = "CLOSED"

SRC_URI = "file://tictacktoeGame.cpp"

S = "${WORKDIR}"

do_compile() {
    ${CXX} ${CXXFLAGS} ${LDFLAGS} tictacktoeGame.cpp -o tictacktoeGame
}
do_install() {
    install -d ${D}${bindir}
    install -m 0755 tictacktoeGame ${D}${bindir}
}