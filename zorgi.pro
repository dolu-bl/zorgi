QT += quick \
    svg

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS \
    QT_DISABLE_DEPRECATED_BEFORE=0x060000 \
    _USE_MATH_DEFINES

SOURCES += src/main.cpp \
    src/game.cpp \
    src/misc/keyemitter.cpp \
    src/model/asteroid.cpp \
    src/model/spacemodel.cpp \
    src/model/player.cpp \
    src/model/item.cpp \
    src/proxy/proxyitem.cpp \
    src/proxy/spaceproxy.cpp

HEADERS += \
    src/game.h \
    src/misc/keyemitter.h \
    src/misc/directiontype.h \
    src/model/asteroid.h \
    src/model/itemtype.h \
    src/model/spacemodel.h \
    src/model/player.h \
    src/model/item.h \
    src/proxy/proxyitem.h \
    src/proxy/spaceproxy.h

RESOURCES += res/resources.qrc

INCLUDEPATH += src/

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/res/qml
QML2_IMPORT_PATH += $$PWD/res/qml

# FEXME: hack to fix: can not find -lc++
# https://evileg.com/ru/forum/topic/984/#post-5907
android {
    QMAKE_LFLAGS += -nostdlib++
}
