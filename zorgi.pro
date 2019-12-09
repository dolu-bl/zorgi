QT += quick \
    svg

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += src/main.cpp \
    src/misc/keyemitter.cpp \
    src/model/spacemodel.cpp \
    src/model/player.cpp \
    src/model/item.cpp \

HEADERS += \
    src/misc/keyemitter.h \
    src/model/spacemodel.h \
    src/model/player.h \
    src/model/item.h

RESOURCES += res/resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# FEXME: hack to fix: can not find -lc++
# https://evileg.com/ru/forum/topic/984/#post-5907
android
{
    QMAKE_LFLAGS += -nostdlib++
}
