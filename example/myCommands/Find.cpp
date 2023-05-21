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
    return ""; // always correct
}

std::string Find::run() {

    string line; getline(cin, line);
    istringstream is(line);

    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
    };

    const auto entries = FindIf(predicate,database->get_ALL_DATA());
    for (const auto &entry : entries) {
        cout << entry << endl;
    }
    cout << "Found " << entries.size() << " entries" << endl;
    return "";
}

std::string Find::help() {
    return helpMessage;
}
