#include <sstream>
#include "../database.h"
#include "Find.h"
#include <iostream>
#include "condition_parser.h"

Find::Find(std::string string,Database* database_) : inner(string),database(database_) {}

std::string Find::getQuery(){
    return "find";
}

std::string Find::checkAndAssemble(Parser &parser) {


    string for_condition = parser.getKeyArgs()["c"];

    auto condition = ParseCondition(for_condition);
    string result = "";
    if(condition != nullptr){
        auto predicate = [condition](const Date &date, const string &event) {
            return condition->Evaluate(date, event);
        };

        const auto entries = FindIf(predicate,database->get_ALL_DATA());
        for (const auto &entry : entries) {

            result += entry + "\n";
        }

        result += "Found " + to_string(entries.size()) + " entries\n";
    }

    return result; // always correct
}

std::string Find::run() {

    return "";
}

std::string Find::help() {
    return helpMessage;
}
