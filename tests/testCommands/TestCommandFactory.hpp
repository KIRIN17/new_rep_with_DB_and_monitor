#ifndef MONITOR_TESTCOMMANDFACTORY_HPP
#define MONITOR_TESTCOMMANDFACTORY_HPP

#include <utility>

#include <CommandFactory.hpp>

#include "Init.h"
#include "Help.h"

class TestCommandFactory : public CommandFactory<std::tuple<Init, Help>> {
public:
    explicit TestCommandFactory() = default;

    std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) override {
        return construct(commandString);
    }
};

#endif //MONITOR_TESTCOMMANDFACTORY_HPP
