#include <sstream>
#include "../database.h"
#include "Del.h"
#include <iostream>
//#include "condition_parser.h"
#include "../tokens_and_another/condition_parser.h"
#include "functions.h"

Del::Del(std::string string, Database *database_) : inner(string), database(database_) {}

std::string Del::getQuery() {
    return "del";
}

std::string Del::checkAndAssemble(Parser &parser) {

    string for_condition = parser.getKeyArgs()["c"];

    auto condition = ParseCondition(for_condition);
    string result = "";

    if (condition != nullptr) {
        auto predicate = [condition](const Date &date, const string &event) {
            return condition->Evaluate(date, event);
        };

        //int count = RemoveIf(predicate, database);
        int count = database->RemoveIf(predicate);
        result = "Removed " + to_string(count) + " entries\n";
    }

    return result; // always correct
}

std::string Del::run() {

    return "";
}

std::string Del::help() {
    return helpMessage;
}
