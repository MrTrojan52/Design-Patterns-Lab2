#-------------------------------------------------
#
# Project created by QtCreator 2018-10-21T18:53:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DPLab2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += \
       c++11 \
       console

SOURCES += \
        main.cpp \
        dialog.cpp \
    qpaintwidget.cpp \
    sources/AMatrix.cpp \
    sources/MatrixInitiator.cpp \
    sources/MatrixNormal.cpp \
    sources/MatrixSparse.cpp \
    sources/MatrixStatistics.cpp \
    sources/VectorNormal.cpp \
    sources/VectorSparse.cpp \
    sources/consoledrawer.cpp \
    sources/guidrawer.cpp

HEADERS += \
        dialog.h \
    qpaintwidget.h \
    headers/AMatrix.h \
    headers/IMatrix.h \
    headers/IVector.h \
    headers/MatrixInitiator.h \
    headers/MatrixNormal.h \
    headers/MatrixSparse.h \
    headers/MatrixStatistics.h \
    headers/VectorNormal.h \
    headers/VectorSparse.h \
    headers/idrawer.h \
    headers/idrawable.h \
    headers/consoledrawer.h \
    headers/guidrawer.h \
    headers/adrawer.h

FORMS += \
        dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
