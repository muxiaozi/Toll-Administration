#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T10:54:50
#
#-------------------------------------------------

QT += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Toll-Administration
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    tablemodel.cpp \
    abstractpage.cpp \
    paydialog.cpp \
    incometablemodel.cpp

HEADERS  += mainwindow.h \
    database.h \
    tablemodel.h \
    abstractpage.h \
    paydialog.h \
    incometablemodel.h

FORMS    += mainwindow.ui \
    paydialog.ui

RESOURCES += \
    source.qrc

RC_ICONS = app.ico
