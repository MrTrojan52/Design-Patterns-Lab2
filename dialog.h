#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qpaintwidget.h"
#include "Matrix/include/AMatrix.h"
#include "Drawer/include/consoledrawer.h"
#include "Drawer/include/guidrawer.h"
#include "Matrix/include/renumdecorator.h"
#include "Matrix/include/horizontalmatrixgroup.h"
#include "Matrix/include/verticalmatrixgroup.h"
#include "Factories/include/matrixfactory.h"
#include "Command/include/commandmanager.h"
#include "Command/include/matrixsetcommand.h"
#include "Command/include/initappcommand.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void matrixSizeChanged();
private slots:
    void on_psbNormal_clicked();

    void on_psbSparse_clicked();

    void on_chkBorder_toggled(bool checked);

    void on_psbRenum_clicked();

    void on_psbRestore_clicked();

    void on_objMakeGroup_clicked();

    void on_psbChange_clicked();

    void on_psbUndo_clicked();

private:
    bool eventFilter(QObject* watched, QEvent* event);
    void redrawMatrix();
    Ui::Dialog *ui;
    std::shared_ptr<AMatrix> _matrix;
    ConsoleDrawer* _cDrawer;
    GuiDrawer* _gDrawer;
    MatrixFactory* matrix_factory;
};

#endif // DIALOG_H
