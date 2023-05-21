#include <sstream>
#include "../database.h"
#include "Print.h"
#include <iostream>
Print::Print(std::string string, Database* database_) : inner(string), database(database_) {}

std::string Print::getQuery(){
    return "print";
}

std::string Print::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Print::run() {

    database->Print(std::cout);
    return "";
}

std::string Print::help() {
    return helpMessage;
}
