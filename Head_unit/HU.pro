QT       += core gui
QT += qml quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    socket.cpp \
    Get_SWC.cpp \
    decrypt.cpp \
    integrity_check.cpp \
    Packing_Unpacking.cpp

HEADERS += \
    mainwindow.h \
    socket.h \
    Get_SWC.h \
    decrypt.h \
    integrity_check.h \
    Packing_Unpacking.h

FORMS += \
    mainwindow.ui

LIBCRYPTO= $$OPENSSLPATH//usr/lib/x86_64-linux-gnu/libcryptopp.so
LIBS += $$LIBCRYPTO

LIBPOCOFOUND= $$OPENSSLPATH//usr/lib/x86_64-linux-gnu/libPocoFoundation.so
LIBS += $$LIBPOCOFOUND

LIBPOCOZIP= $$OPENSSLPATH//usr/lib/x86_64-linux-gnu/libPocoZip.so
LIBS += $$LIBPOCOZIP


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    img/Mentor_Graphics-Logo.wine.png
