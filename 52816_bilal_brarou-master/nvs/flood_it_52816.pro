QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# CONFIG += c++17 # rnvs : comm

QMAKE_CXXFLAGS += -std=c++17 -pedantic-errors # rnvs : ajout

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Board.cpp \
    Cell.cpp \
    CellView.cpp \
    Game.cpp \
    GameView.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Board.h \
    Cell.h \
    CellView.h \
    Color.h \
    Game.h \
    GameView.h \
    Observable.h \
    Observer.h \
    fileManager.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    flood_it_52816.pro.user
