QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    requests.cpp

HEADERS += \
    mainwindow.h \
    non_gui.h \
    requests.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    res.qrc

INCLUDEPATH += \
    C:\msys64\mingw64\include


LIBS += -LC:\msys64\mingw64\lib -lcurl


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
