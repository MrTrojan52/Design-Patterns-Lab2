#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include <memory>
#include "ICommand.h"
#include <list>
class CommandManager {
private:
    std::list<std::shared_ptr<ICommand>> command_list;
    bool lock = false;
    CommandManager() { }
    static std::unique_ptr<CommandManager> instance;
public:
    CommandManager(CommandManager const&) = delete;
    void operator=(CommandManager const&) = delete;
    static CommandManager* getInstance();
    void Registry(ICommand* command);
    void Undo();
};

#endif // COMMANDMANAGER_H
