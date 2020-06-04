TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Baner.cpp \
        Boot.cpp \
        Character.cpp \
        Enemy.cpp \
        Helper.cpp \
        Hero.cpp \
        Music.cpp \
        Tile.cpp \
        Timer.cpp \
        main.cpp

INCLUDEPATH += "D:/SFML-2.5.1/include"

LIBS += -L "D:/SFML-2.5.1/lib"

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Baner.h \
    Character.h \
    Header.h \
    Hero.h \
    Music.h \
    Tile.h \
    Timer.h

DISTFILES += \
    cele_i_TODO
