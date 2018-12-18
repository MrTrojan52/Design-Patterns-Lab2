#include "Command/include/matrixsetcommand.h"


MatrixSetCommand::MatrixSetCommand(std::shared_ptr<IMatrix> m, unsigned long row, unsigned long col, int val) :
    _matrix(m),
    _row(row),
    _col(col),
    _value(val)
{

}

void MatrixSetCommand::doExecute() {
    _matrix->set(_row, _col, _value);
}

ICommand* MatrixSetCommand::clone() {
    return new MatrixSetCommand(_matrix, _row, _col, _value);
}
