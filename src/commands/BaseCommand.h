#ifndef MONITOR_BASECOMMAND_H
#define MONITOR_BASECOMMAND_H

#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <memory>
#include <algorithm>

#include "Parser.h"

/**
 * Класс образует базу для дальнейших классов-команд, хранит общие методы обработки введенной строки
 */
class BaseCommand {
protected:
    /**
     * Метод проверяет аргументы из объекта парсера и собирает их в соответствующие команде переменные
     * @param parser объект парсера, содержащий массивы полученных аргументов
     * @return сообщение об ошибке (при ошибке)
     */
    virtual std::string checkAndAssemble(Parser &parser) = 0;

    /**
     * Метод запускает соответствующую команде функцию ФС
     * @return Код ошибки или void в зависимости от команды
     */
    virtual std::string run() = 0;
    /**
     * Выводит в сохраненный поток вывода информацию о команде
     * @return Сохраненный поток вывода
     */
    virtual std::string help() = 0;
public:
    explicit BaseCommand();

    virtual ~BaseCommand() = default;

    /**
     * Метод обрабатывает, устанавливает аргументы команды из строки запроса и исполняет команду
     * @param parser объект парсера обработавший запрос
     * @return сообщение об ошибке (при ошибке)
     */
    virtual std::string processQuery(Parser &parser);
};

#endif //MONITOR_BASECOMMAND_H
