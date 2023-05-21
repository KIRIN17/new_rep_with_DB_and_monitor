#include <sstream>

#include "Help.h"

Help::Help(std::string string,Database* database_) : inner(string),database(database_) {}

std::string Help::getQuery(){
    return "help";
}

std::string Help::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Help::run() {
    //database->Add({3,3,3},"shrek");
    return helpMessage;
}

std::string Help::help() {
    return helpMessage;
}
