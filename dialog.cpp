#include "dialog.h"
#include "ui_dialog.h"
#include "headers/MatrixNormal.h"
#include "headers/MatrixSparse.h"
#include "headers/consoledrawer.h"
#include "headers/MatrixInitiator.h"
#include "headers/renumdecorator.h"
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
    //delete _matrix;
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
    if(this->_matrix) {
        system("clear");
       // delete this->_matrix;
    }
   this->_cDrawer->needBorder(ui->chkBorder->isChecked());
   std::shared_ptr<IMatrix> m(new MatrixNormal(ui->spnRows->value(), ui->spnCols->value(), this->_cDrawer));
   this->_matrix = m;
   MatrixInitiator::fillMatrix(this->_matrix.get(), ui->spnNonZero->value(), ui->spnMax->value());
   this->_matrix->Draw();
   this->_gDrawer->needBorder(ui->chkBorder->isChecked());
   ui->widget->update();
}

void Dialog::on_psbSparse_clicked()
{

    if(this->_matrix) {
        system("clear");
        //delete this->_matrix;
    }
    this->_cDrawer->needBorder(ui->chkBorder->isChecked());
    std::shared_ptr<IMatrix> m(new MatrixSparse(ui->spnRows->value(), ui->spnCols->value(), this->_cDrawer));
    this->_matrix = m;
    MatrixInitiator::fillMatrix(this->_matrix.get(), ui->spnNonZero->value(), ui->spnMax->value());
    this->_matrix->Draw();
    this->_gDrawer->needBorder(ui->chkBorder->isChecked());
    ui->widget->update();
}

void Dialog::on_chkBorder_toggled(bool checked)
{

    this->_cDrawer->needBorder(checked);
    if(this->_matrix) {
        system("clear");
        this->_matrix->setDrawer(this->_cDrawer);
        this->_matrix->Draw();
    }
    this->_gDrawer->needBorder(ui->chkBorder->isChecked());
    ui->widget->update();
}

void Dialog::on_psbRenum_clicked()
{
    if(this->_matrix) {
        srand(static_cast<unsigned int>(time(nullptr)));
        int swap1 = -1, swap2 = -1;
        system("clear");
        std::shared_ptr<RenumDecorator> rd(new RenumDecorator(this->_matrix, this->_cDrawer));
        //RenumDecorator* rd = new RenumDecorator(this->_matrix, this->_cDrawer);
        if(rd->getRows() != 1) {
            swap1 = rand() % rd->getRows();
            swap2 = swap1;
            while(swap2 == swap1)
                swap2 = rand() % rd->getRows();
            rd->swapRows(swap1, swap2);
        }


        if(rd->getCols() != 1) {
            swap1 = rand() % rd->getCols();
            swap2 = swap1;
            while(swap2 == swap1)
                swap2 = rand() % rd->getCols();
            rd->swapCols(swap1, swap2);
        }


        this->_matrix = rd;
        this->_cDrawer->needBorder(ui->chkBorder->isChecked());
        this->_matrix->Draw();
        this->_gDrawer->needBorder(ui->chkBorder->isChecked());
        ui->widget->update();
    }

}

void Dialog::on_psbRestore_clicked()
{
    if(this->_matrix) {
        system("clear");
        this->_matrix = this->_matrix->getComponent();
        this->_matrix->setDrawer(this->_cDrawer);
        this->_matrix->Draw();
        ui->widget->update();
    }
}
