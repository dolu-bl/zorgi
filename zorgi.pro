QT += quick \
    svg

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += src/main.cpp \
    src/model/spacemodel.cpp \
    src/model/player.cpp \
    src/model/item.cpp \

RESOURCES += res/resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/model/spacemodel.h \
    src/model/player.h \
    src/model/item.h