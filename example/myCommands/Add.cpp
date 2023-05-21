#include <sstream>
#include "../database.h"
#include "Add.h"
#include <iostream>

std::string ParseEvent(std::istream &is) {
    std::string res;
    is >> std::ws;
    std::getline(is, res);
    return res;
}

Add::Add(std::string string,Database* database_) : inner(string),database(database_) {}

std::string Add::getQuery(){
    return "add";
}

std::string Add::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Add::run() {

    string line; getline(cin, line);
    istringstream is(line);

    const auto date = ParseDate(is);
    const auto event = ParseEvent(is);


    if(!database->get_ALL_DATA_SET().count(date) || !database->get_ALL_DATA_SET().at(date).count(event)){
        database->set_to_ALL_DATA(date,event);
        database->set_to_ALL_DATA_SET(date,event);
    }
    return helpMessage;
}

std::string Add::help() {
    return helpMessage;
}
