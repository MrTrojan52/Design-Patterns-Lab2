#include "dialog.h"
#include "ui_dialog.h"
#include "headers/MatrixNormal.h"
#include "headers/MatrixSparse.h"
#include "headers/consoledrawer.h"
#include "headers/MatrixInitiator.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spnMax->setMaximum(INT_MAX);
    ui->spnNonZero->setMaximum(ui->spnCols->value() * ui->spnRows->value());
    connect(ui->spnRows,SIGNAL(valueChanged(int)), this, SLOT(matrixSizeChanged(void)));
    connect(ui->spnCols,SIGNAL(valueChanged(int)), this, SLOT(matrixSizeChanged(void)));
}


Dialog::~Dialog()
{
    delete _matrix;
    delete ui;

}


void Dialog::matrixSizeChanged() {
    ui->spnNonZero->setMaximum(ui->spnCols->value() * ui->spnRows->value());
}

void Dialog::on_psbNormal_clicked()
{
   system("clear");
   if(this->_matrix)
       delete this->_matrix;
   ConsoleDrawer cd;
   this->_matrix = new MatrixNormal(ui->spnRows->value(), ui->spnCols->value(), &cd);
   MatrixInitiator::fillMatrix(this->_matrix, ui->spnNonZero->value(), ui->spnMax->value());
   this->_matrix->Draw();
}

void Dialog::on_psbSparse_clicked()
{
    system("clear");
    if(this->_matrix)
        delete this->_matrix;
    ConsoleDrawer cd;
    this->_matrix = new MatrixSparse(ui->spnRows->value(), ui->spnCols->value(), &cd);
    MatrixInitiator::fillMatrix(this->_matrix, ui->spnNonZero->value(), ui->spnMax->value());
    this->_matrix->Draw();
}

void Dialog::on_chkBorder_toggled(bool checked)
{
    Q_UNUSED(checked);
}
