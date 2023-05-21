#ifndef MONITOR_MYCOMMANDFACTORY_HPP
#define MONITOR_MYCOMMANDFACTORY_HPP

#include <utility>

#include <CommandFactory.hpp>

#include "Add.h"
#include "Init.h"
#include "Help.h"
#include "Print.h"
#include "Find.h"
#include "Del.h"
#include "Last.h"

template<typename CommandClasses>
class MyCommandFactory : public CommandFactory<CommandClasses> {
private:
    Database* database;
    std::string string;
public:
    //explicit MyCommandFactory(std::string string_);
    MyCommandFactory(std::string string_,Database* database_);

    std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) override {
        return CommandFactory<CommandClasses>().template construct(commandString, string, database);
    }
};

template<typename CommandClasses>
MyCommandFactory<CommandClasses>::MyCommandFactory(std::string string_,Database* database_) : string(std::move(string_)),database(database_) {}

#endif //MONITOR_MYCOMMANDFACTORY_HPP
