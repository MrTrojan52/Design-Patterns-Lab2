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
    Drawer/src/consoledrawer.cpp \
    Drawer/src/guidrawer.cpp \
    Factories/src/MatrixFactory.cpp \
    Factories/src/vectornormalfactory.cpp \
    Factories/src/vectorsparsefactory.cpp \
    Matrix/src/AMatrix.cpp \
    Matrix/src/horizontalmatrixgroup.cpp \
    Matrix/src/MatrixInitiator.cpp \
    Matrix/src/MatrixNormal.cpp \
    Matrix/src/MatrixSparse.cpp \
    Matrix/src/MatrixStatistics.cpp \
    Matrix/src/renumdecorator.cpp \
    Matrix/src/verticalmatrixgroup.cpp \
    Vector/src/VectorNormal.cpp \
    Vector/src/VectorSparse.cpp

HEADERS += \
        dialog.h \
    qpaintwidget.h \
    Drawer/include/adrawer.h \
    Drawer/include/consoledrawer.h \
    Drawer/include/guidrawer.h \
    Drawer/include/idrawable.h \
    Drawer/include/idrawer.h \
    Factories/include/IAbstractFactory.h \
    Factories/include/ivectorfactory.h \
    Factories/include/matrixfactory.h \
    Factories/include/vectornormalfactory.h \
    Factories/include/vectorsparsefactory.h \
    Matrix/include/AMatrix.h \
    Matrix/include/horizontalmatrixgroup.h \
    Matrix/include/iiterable.h \
    Matrix/include/IMatrix.h \
    Matrix/include/MatrixInitiator.h \
    Matrix/include/MatrixNormal.h \
    Matrix/include/MatrixSparse.h \
    Matrix/include/MatrixStatistics.h \
    Matrix/include/renumdecorator.h \
    Matrix/include/verticalmatrixgroup.h \
    Vector/include/IVector.h \
    Vector/include/VectorNormal.h \
    Vector/include/VectorSparse.h

FORMS += \
        dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
