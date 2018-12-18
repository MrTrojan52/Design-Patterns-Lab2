#ifndef INITAPPCOMMAND_H
#define INITAPPCOMMAND_H
#include "acommand.h"
#include "Matrix/include/IMatrix.h"
#include <memory>
class InitAppCommand: public ACommand {
public:
    InitAppCommand(std::shared_ptr<IMatrix> m) : _matrix(m)  {    }
private:
    std::shared_ptr<IMatrix> _matrix;
protected:
    void doExecute() override;
    ICommand* clone() override;

};

#endif // INITAPPCOMMAND_H
