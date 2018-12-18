#include "Command/include/acommand.h"
#include "Command/include/commandmanager.h"
void ACommand::Execute() {
    doExecute();
    CommandManager::getInstance()->Registry(this->clone());
}
