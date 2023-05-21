#include <sstream>
#include "../database.h"
#include "Last.h"
#include <iostream>
#include "condition_parser.h"

Last::Last(std::string string,Database* database_) : inner(string),database(database_) {}

std::string Last::getQuery(){
    return "last";
}

std::string Last::checkAndAssemble(Parser &parser) {
    return ""; // always correct
}

std::string Last::run() {

    string line; getline(cin, line);
    istringstream is(line);

    Date date = ParseDate(is);

    if(database->get_ALL_DATA().count(date))//если дата имеется в словаре(проверить случай поиска последнего события после его удаления)
        return date.ToString() + ' ' + database->get_ALL_DATA().at(date)[database->get_ALL_DATA().at(date).size() - 1];
    else{
        auto it = database->get_ALL_DATA().upper_bound(date);
        if(it == database->get_ALL_DATA().begin() || database->get_ALL_DATA().size() == 0)
            std::cout <<  "No entries";
        else{
            std::cout <<  (prev(it))->first.ToString() + ' ' + *(--(prev(it)->second).end());
        }
    }

    return "";
}

std::string Last::help() {
    return helpMessage;
}
