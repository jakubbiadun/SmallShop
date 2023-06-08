TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        client.cpp \
        main.cpp \
        menu.cpp \
        order.cpp

HEADERS += \
    client.h \
    menu.h \
    order.h
