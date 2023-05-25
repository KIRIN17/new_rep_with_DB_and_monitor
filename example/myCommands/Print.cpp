#include <sstream>
#include "../database.h"
#include "Print.h"
#include <iostream>

std::string ToStringDB(Database* database){
    std::string result = "";
    for(const auto& item : database->get_ALL_DATA()){
        result += ToStringVector(item.first,item.first.ToString(),database);
    }
    return result;
}

std::string ToStringVector(const Date& date,std::string nums,const Database* database){
    std::string result = "";
    int index = 0;
    std::map<Date,std::vector<std::string>> tmp = database->get_ALL_DATA();
    if(tmp.count(date)){
        for(const auto& item : tmp.at(date)){
            result += nums + ' ' + item;
            if(index != database->get_ALL_DATA().at(date).size() - 1)
                result += '\n';
            index++;
        }
    }
    result += "\n";
    return result;
}

Print::Print(std::string string, Database* database_) : inner(string), database(database_) {}

std::string Print::getQuery(){
    return "print";
}

std::string Print::checkAndAssemble(Parser &parser) {
    return "";
}

std::string Print::run() {
    string result = ToStringDB(database);
    return result;
}

std::string Print::help() {
    return helpMessage;
}
