#ifndef MATRIXSETCOMMAND_H
#define MATRIXSETCOMMAND_H

#include "acommand.h"
#include "Matrix/include/IMatrix.h"
#include <memory>
class MatrixSetCommand: public ACommand {
public:
    MatrixSetCommand(std::shared_ptr<IMatrix> m, unsigned long row, unsigned long col, int val);
private:
    std::shared_ptr<IMatrix> _matrix;
    unsigned long _row;
    unsigned long _col;
    int _value;
protected:
    void doExecute() override;
    ICommand* clone() override;

};

#endif // MATRIXSETCOMMAND_H
