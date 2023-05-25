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

    //string line; getline(cin, line);
    //istringstream is(line);
    string for_condition = parser.getKeyArgs()["c"];
    //cout << for_condition;
    auto condition = ParseCondition(for_condition);
    string result = "";
    if(condition != nullptr){
        auto predicate = [condition](const Date &date, const string &event) {
            return condition->Evaluate(date, event);
        };

        const auto entries = FindIf(predicate,database->get_ALL_DATA());
        for (const auto &entry : entries) {
            //cout << entry << endl;
            result += entry + "\n";
        }
        //cout << "Found " << entries.size() << " entries" << endl;
        result += "Found " + to_string(entries.size()) + " entries\n";
    }

    return result; // always correct
}

std::string Find::run() {
//
//    string line; getline(cin, line);
//    istringstream is(line);
//
//    auto condition = ParseCondition(is);
//    if(condition != nullptr){
//        auto predicate = [condition](const Date &date, const string &event) {
//            return condition->Evaluate(date, event);
//        };
//
//        const auto entries = FindIf(predicate,database->get_ALL_DATA());
//        for (const auto &entry : entries) {
//            cout << entry << endl;
//        }
//        cout << "Found " << entries.size() << " entries" << endl;
//    }

    return "";
}

std::string Find::help() {
    return helpMessage;
}
