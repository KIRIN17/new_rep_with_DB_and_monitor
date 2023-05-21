#ifndef MAIN_HELP_H
#define MAIN_HELP_H

#include <utility>
#include "../database.h"
#include "BaseCommand.h"

class Help : public BaseCommand {
private:
    std::string inner;
    Database* database;

    static constexpr char helpMessage[] = "Add date event — добавить в базу данных пару (date, event);\n"
                                          "\n"
                                          "Print — вывести всё содержимое базы данных;\n"
                                          "\n"
                                          "Find condition — вывести все записи, содержащиеся в базе данных, которые удовлетворяют условию condition;\n"
                                          "\n"
                                          "Del condition — удалить из базы все записи, которые удовлетворяют условию condition;\n"
                                          "\n"
                                          "Last date — вывести запись с последним событием, случившимся в данную дату.\n"
                                          "\n"
                                          "Условия в командах Find и Del накладывают определённые ограничения на даты и события, например:\n"
                                          "\n"
                                          "Find date < 2017-11-06 — найти все события, которые случились раньше 6 ноября 2017 года;\n"
                                          "\n"
                                          "Del event != \"holiday\" — удалить из базы все события, кроме «holiday»;\n"
                                          "\n"
                                          "Find date >= 2017-01-01 AND date < 2017-07-01 AND event == \"sport event\" — найти всё события «sport event», случившиеся в первой половине 2017 года;\n"
                                          "\n"
                                          "Del date < 2017-01-01 AND (event == \"holiday\" OR event == \"sport event\") — удалить из базы все события «holiday» и «sport event», случившиеся до 2017 года.\n"
                                          "\n"
                                          "В командах обоих типов условия могут быть пустыми: под такое условие попадают все события.\n";
protected:
    std::string help() override;
public:
    Help(std::string string,Database* database_);

    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;
};

#endif //MAIN_HELP_H
