QT += dbus core gui

TARGET = camera-test
TEMPLATE = app

INCLUDEPATH += /usr/include/meegotouch

CONFIG += link_pkgconfig meegotouchevents
PKGCONFIG += meegotouch meegotouch-boostable

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/camera-test/bin
    INSTALLS += target
}

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

HEADERS += \
    camera.h \
    camerapage.h \
    resultpage.h

SOURCES += \
    camera.cpp \
    main.cpp \
    camerapage.cpp \
    resultpage.cpp

contains(MEEGO_EDITION,harmattan) {
    desktopfile.files = camera-test.desktop
    desktopfile.path = /usr/share/applications
    INSTALLS += desktopfile
}
