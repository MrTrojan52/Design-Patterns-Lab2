#ifndef ACOMMAND_H
#define ACOMMAND_H
#include "ICommand.h"

class ACommand : public ICommand {
public:
    void Execute() override;
protected:
    virtual void doExecute() = 0;
};

#endif // ACOMMAND_H
