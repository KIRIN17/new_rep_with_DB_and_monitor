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

    std::string for_date = parser.getKeyArgs()["d"];
    istringstream stream_for_date(for_date);

    int y,m,d;
    if(stream_for_date >> y && stream_for_date.get() == '-' && stream_for_date >> m && stream_for_date.get() == '-' && stream_for_date >> d && (stream_for_date.peek() == ' ' || stream_for_date.peek() == EOF)){
        if(((m < 1 || m > 12) && (d < 1 || d > 31)) || (m < 1 || m > 12)){

            return "Month value is invalid: " + std::to_string(m);

        }else{
            if(d < 1 || d > 31){

                return "Day value is invalid: " + std::to_string(d);

            }
            else{
                date.SetData(y,m,d);
                return "";
            }
        }
    }else{
        return "Wrong date format\n";
    }


}

std::string Last::run() {

    if(database->get_ALL_DATA().count(date))//если дата имеется в словаре(проверить случай поиска последнего события после его удаления)
        return date.ToString() + ' ' + database->get_ALL_DATA().at(date)[database->get_ALL_DATA().at(date).size() - 1];
    else{
        auto it = database->get_ALL_DATA().upper_bound(date);
        if(it == database->get_ALL_DATA().begin() || database->get_ALL_DATA().size() == 0)
            return "No entries";
        else{
            return (prev(it))->first.ToString() + ' ' + *(--(prev(it)->second).end());
        }
    }
}

std::string Last::help() {
    return helpMessage;
}
