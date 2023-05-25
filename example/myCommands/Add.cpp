#include <sstream>
#include "../database.h"
#include "Add.h"
#include <iostream>

//std::string ParseEvent(std::istream &is) {
//    std::string res;
//    is >> std::ws;
//    std::getline(is, res);
//    return res;
//}

Add::Add(std::string string,Database* database_) : inner(string),database(database_) {}

std::string Add::getQuery(){
    return "add";
}

std::string Add::checkAndAssemble(Parser &parser) {
    std::string for_date = parser.getKeyArgs()["d"];
    istringstream stream_for_date(for_date);
    std::string for_event = parser.getKeyArgs()["e"];
    istringstream stream_for_event(for_event);

    int y,m,d;
    if(stream_for_date >> y && stream_for_date.get() == '-' && stream_for_date >> m && stream_for_date.get() == '-' && stream_for_date >> d && (stream_for_date.peek() == ' ' || stream_for_date.peek() == EOF)){
        if(((m < 1 || m > 12) && (d < 1 || d > 31)) || (m < 1 || m > 12)){
            //throw std::runtime_error("Month value is invalid: " + std::to_string(m));
            return "Month value is invalid: " + std::to_string(m);
            //return {-1,-1,-1};
            //return stream;
        }else{
            if(d < 1 || d > 31){
                //throw std::runtime_error("Day value is invalid: " + std::to_string(d));
                return "Day value is invalid: " + std::to_string(d);
                //return {-1,-1,-1};
            }
            else{
                date.SetData(y,m,d);
                event = for_event;

                return "";
            }
        }
    }else{
        return "Wrong date format\n";
    }
}

std::string Add::run() {
    database->set_to_ALL_DATA(date,event);
    database->set_to_ALL_DATA_SET(date,event);
    return "";
}
std::string Add::help() {
    return helpMessage;
}
