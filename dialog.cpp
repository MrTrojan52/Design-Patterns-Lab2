#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include "headers/MatrixNormal.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spnMax->setMaximum(INT_MAX);
    ui->spnNonZero->setMaximum(ui->spnCols->value() * ui->spnRows->value());
    connect(ui->spnRows,SIGNAL(valueChanged(int)), this, SLOT(matrixSizeChanged(void)));
    connect(ui->spnCols,SIGNAL(valueChanged(int)), this, SLOT(matrixSizeChanged(void)));
    _matrix = new MatrixNormal(9,9);
}

Dialog::~Dialog()
{
    delete _matrix;
    delete ui;

}


void Dialog::matrixSizeChanged() {
    ui->spnNonZero->setMaximum(ui->spnCols->value() * ui->spnRows->value());
}
