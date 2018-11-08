#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qpaintwidget.h"
#include "headers/AMatrix.h"
#include "headers/consoledrawer.h"
#include "headers/guidrawer.h"
#include "memory"
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

private:
    bool eventFilter(QObject* watched, QEvent* event);
    Ui::Dialog *ui;
    std::shared_ptr<IMatrix> _matrix;
    ConsoleDrawer* _cDrawer;
    GuiDrawer* _gDrawer;
};

#endif // DIALOG_H
