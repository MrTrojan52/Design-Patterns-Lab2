#include "Command/include/commandmanager.h"

std::unique_ptr<CommandManager> CommandManager::instance = nullptr;


CommandManager* CommandManager::getInstance() {
    if(instance.get())
        return instance.get();
    else {
        instance = std::unique_ptr<CommandManager>(new CommandManager);
        return instance.get();
    }
}


void CommandManager::Registry(ICommand* command) {
    if(lock)
        return;
    command_list.push_back(command);
}

void CommandManager::Undo()
{
    if(command_list.size()) {
        command_list.pop_back();
        lock = true;
        for(auto c : command_list)
            c->Execute();
        lock = false;
    }
}
