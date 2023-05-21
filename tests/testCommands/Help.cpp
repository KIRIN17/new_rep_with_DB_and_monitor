#include <sstream>

#include "Help.h"

std::string Help::getQuery(){
    return "help";
}

std::string Help::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Help::run() {
    return helpMessage;
}

std::string Help::help() {
    return helpMessage;
}
