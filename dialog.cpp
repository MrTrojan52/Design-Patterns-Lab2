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
    ui->widget->installEventFilter(this);
    this->_cDrawer = new ConsoleDrawer;
    this->_gDrawer = new GuiDrawer;
    this->_matrix = nullptr;
}


Dialog::~Dialog()
{
    delete _matrix;
    delete _cDrawer;
    delete _gDrawer;
    delete ui;

}

bool Dialog::eventFilter(QObject* watched, QEvent* event) {
    if (watched == ui->widget && event->type() == QEvent::Paint) {
         QPainter painter;
         painter.begin(ui->widget);
         this->_gDrawer->setPainter(&painter);
         if(this->_matrix) {
             this->_matrix->setDrawer(_gDrawer);
             this->_matrix->Draw();
         }
         painter.end();
         return true;
        }
        return false;
}

void Dialog::matrixSizeChanged() {
    ui->spnNonZero->setMaximum(ui->spnCols->value() * ui->spnRows->value());
}

void Dialog::on_psbNormal_clicked()
{
   system("clear");
   if(this->_matrix)
       delete this->_matrix;
   this->_cDrawer->needBorder(ui->chkBorder->isChecked());
   this->_matrix = new MatrixNormal(ui->spnRows->value(), ui->spnCols->value(), this->_cDrawer);
   MatrixInitiator::fillMatrix(this->_matrix, ui->spnNonZero->value(), ui->spnMax->value());
   this->_matrix->Draw();
   this->_gDrawer->needBorder(ui->chkBorder->isChecked());
   ui->widget->update();
}

void Dialog::on_psbSparse_clicked()
{
    system("clear");
    if(this->_matrix)
        delete this->_matrix;
    this->_cDrawer->needBorder(ui->chkBorder->isChecked());
    this->_matrix = new MatrixSparse(ui->spnRows->value(), ui->spnCols->value(), this->_cDrawer);
    MatrixInitiator::fillMatrix(this->_matrix, ui->spnNonZero->value(), ui->spnMax->value());
    this->_matrix->Draw();
    this->_gDrawer->needBorder(ui->chkBorder->isChecked());
    ui->widget->update();
}

void Dialog::on_chkBorder_toggled(bool checked)
{
    system("clear");
    this->_cDrawer->needBorder(checked);
    if(this->_matrix) {
        this->_matrix->setDrawer(this->_cDrawer);
        this->_matrix->Draw();
    }
    this->_gDrawer->needBorder(ui->chkBorder->isChecked());
    ui->widget->update();
}
