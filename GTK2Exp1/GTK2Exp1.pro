QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.c

INCLUDEPATH +=\
        D:/msys64/mingw64/include/gtk-3.0 \
        D:/msys64/mingw64/include/glib-2.0 \
        D:/msys64/mingw64/lib/glib-2.0/include \
        D:/msys64/mingw64/include/pango-1.0 \
        D:/msys64/mingw64/include/cairo \
        D:/msys64/mingw64/include/gdk-pixbuf-2.0 \
        D:/msys64/mingw64/include/atk-1.0

LIBS +=\
        -LD:/msys64/mingw64/lib \
        -lgtk-3 -lgdk-3 -lgdi32 \
        -limm32 -lshell32 -lole32 -Wl, \
        -luuid -lwinmm -ldwmapi \
        -lsetupapi -lcfgmgr32   \
        -lz -lpangowin32-1.0 \
        -lpangocairo-1.0 -lpango-1.0    \
        -latk-1.0 -lcairo-gobject -lcairo \
        -lgdk_pixbuf-2.0 -lgio-2.0  \
        -lgobject-2.0 -lglib-2.0 -lintl


QMAKE_CFLAGS = `pkg-config --cflags --libs gtk+-3.0`
#QMAKE_CXXFLAGS = $$QMAKE_CFLAGS

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
