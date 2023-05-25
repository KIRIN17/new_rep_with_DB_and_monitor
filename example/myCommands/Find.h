//#ifndef MAIN_HELP_H
//#define MAIN_HELP_H

#include <utility>
#include "../database.h"
#include "BaseCommand.h"

class Find : public BaseCommand {
private:
    Database* database;
    std::string inner;

    static constexpr char helpMessage[] = "";
protected:
    std::string help() override;
public:

    Find(std::string string, Database* database);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

template <typename T> vector<string> FindIf(T predicate,std::map<Date,std::vector<std::string>> ALL_DATA){
    vector<string> res;

    for(const pair<Date,vector<string>>& p : ALL_DATA){
        Date tmp = p.first;
        size_t size_1 = res.size();

        copy_if(p.second.begin(),p.second.end(),back_inserter(res),[predicate,tmp](const string& s){
            return predicate(tmp,s);
        });

        size_t size_2 = res.size();

        if(size_1 != size_2){//добавление данной даты к каждому новому добавленному событию
            for (int i = size_1; i < size_2; ++i) {
                res[i] = tmp.ToString() + " " + res[i];
            }
        }

    }
    return res;
}
//#endif //MAIN_HELP_H
