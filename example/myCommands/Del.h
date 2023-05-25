//#ifndef MAIN_HELP_H
//#define MAIN_HELP_H

#include <utility>
#include "../database.h"
#include "BaseCommand.h"

template <typename T> int RemoveIf(T predicate,Database* database) {//в предикат нужно передавать параметры?
    int count = 0;
    for(auto i = database->get_ALL_DATA().begin();i != database->get_ALL_DATA().end(); ++i){
        Date tmp = i->first;
        auto it = stable_partition(database->get_ALL_DATA()[i->first].begin(),database->get_ALL_DATA()[i->first].end(),[predicate,tmp](const string& s){
            return predicate(tmp,s);
        });

        for(auto j = database->get_ALL_DATA()[i->first].begin();j != it;++j){
            database->get_ALL_DATA_SET()[i->first].erase(*j);
        }

        int size_1 = database->get_ALL_DATA().at(i->first).size();
        database->get_ALL_DATA()[i->first].erase(database->get_ALL_DATA()[i->first].begin(),it);
        int size_2 = database->get_ALL_DATA().at(i->first).size();
        count += size_1 - size_2;

    }
    for(auto i = database->get_ALL_DATA().begin();i != database->get_ALL_DATA().end();){//удаление пустых дат
        if(database->get_ALL_DATA().at(i->first).empty()){
            i = database->get_ALL_DATA().erase(i);
        }
        else{
            ++i;
        }
    }


    for(auto i = database->get_ALL_DATA_SET().begin();i != database->get_ALL_DATA_SET().end();){//удаление пустых дат
        if(!database->get_ALL_DATA().count(i->first)){
            i = database->get_ALL_DATA_SET().erase(i);
        }
        else{
            ++i;
        }
    }

    return count;
}

class Del : public BaseCommand {
private:
    Database* database;
    std::string inner;

    static constexpr char helpMessage[] = "";
protected:
    std::string help() override;
public:

    Del(std::string string, Database* database);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

//#endif //MAIN_HELP_H
