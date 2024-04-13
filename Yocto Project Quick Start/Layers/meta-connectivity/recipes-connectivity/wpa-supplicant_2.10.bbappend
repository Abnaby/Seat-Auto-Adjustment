# Extend the base recipe search path to $HERE/init-ifupdown
FILESEXTRAPATHS:prepend := "${THISDIR}/wpa-supplicant:"

do_install:append () {
	install -m 0644 ${WORKDIR}/wpa_supplicant.conf ${D}/${sysconfdir}/
}
