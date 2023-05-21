#include <sstream>
#include "../database.h"
#include "Del.h"
#include <iostream>
#include "condition_parser.h"
#include "functions.h"

Del::Del(std::string string, Database *database_) : inner(string), database(database_) {}

std::string Del::getQuery() {
    return "del";
}

std::string Del::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Del::run() {

    string line;
    getline(cin, line);
    istringstream is(line);

    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
    };

    int count = database->RemoveIf(predicate);
    cout << "Removed " << count << " entries" << endl;

    return "";
}

std::string Del::help() {
    return helpMessage;
}
