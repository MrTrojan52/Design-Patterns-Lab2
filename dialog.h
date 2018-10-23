#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qpaintwidget.h"
#include "headers/IMatrix.h"
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

private:
    Ui::Dialog *ui;
    IMatrix *_matrix;
};

#endif // DIALOG_H
