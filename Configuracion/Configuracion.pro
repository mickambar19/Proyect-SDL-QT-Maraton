#-------------------------------------------------
#
# Project created by QtCreator 2014-11-24T16:45:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Configuracion
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    funciones.cpp \
    pregunta.cpp \
    respuesta.cpp \
    winpreres.cpp

HEADERS  += menu.h \
    funciones.h \
    pregunta.h \
    respuesta.h \
    winpreres.h

FORMS    += menu.ui \
    winpreres.ui
