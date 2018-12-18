#include "Command/include/initappcommand.h"

void InitAppCommand::doExecute()
{
    _matrix->iterate([this](int r, int c, int v)->void {
        this->_matrix->set(r, c, 0);
    });
}


ICommand* InitAppCommand::clone() {
    return new InitAppCommand(_matrix);
}
