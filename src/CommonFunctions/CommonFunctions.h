#ifndef MONITOR_EXAMPLE_COMMONFUNCTIONS_H
#define MONITOR_EXAMPLE_COMMONFUNCTIONS_H

#include <algorithm>
#include <string>
#include <stdexcept>

namespace MonCom{
    /**
     * Название файла с сообщениями помощи
     */
    static constexpr char HELPFILENAME[] = "help.txt";

    /**
     * Функция проверяет является ли входной символ пробелом или другим пропускаемым знаком (символ табуляции)
     * @param symbol входной символ
     * @return true если входной символ - пропускаемый знак, false - otherwise
     */
    bool isWhitespace(char symbol);

    /**
     * Функция печатает сообщение помощи для данного индекса
     * Нумерация сообщений происходит с помощью перенумерования BaseCommand::Commands (COMMANDSAMOUNT выводит информацию о мониторе)
     * @return поток вывода
     */
    std::ostream &showHelp(std::ostream &ostream, int index);

    /**
     * Преобразует символы в строке в нижний регистр
     * @param text строка
     */
    void toLower(std::string &text);
    std::string toLower(std::string &&text);

    /**
     * Находит и устанавливает переменные лоигческого типа из переданного отображения в переданную ссылку переменной
     * @tparam Values переменной длины массив строковых значений ключей
     * @param args массив ключей
     * @param boolVar переменная для установки в нее логического значения
     * @param values строки для поиска ключей
     */
    template<class ...Values>
    void findAndSetBoolArg(const std::vector<std::string> &args, bool &boolVar, Values... values){
        if(std::find_if(std::begin(args), std::end(args), [&values...](const std::string &argGiven) -> bool {
            return std::any_of(std::begin({values...}), std::end({values...}), [&argGiven](const std::string &argNeeded) -> bool {
                return argGiven == argNeeded;
            });
        }) != std::end(args)){
            boolVar = true;
        } else{
            boolVar = false;
        }
    }

    /**
     * Функция переводит строку в число
     * @tparam Num_t числовой тип в который происходит конвертация
     * @param strValue строка с числом
     * @param numberVar ссылка на переменную принимающую значение
     * @return true при возникновении ошибки конвертации, false otherwise
     */
    template<class Num_t>
    bool convertToNumber(const std::string &strValue, Num_t& numberVar){
        try {
            numberVar = std::stoi(strValue);
        } catch (std::out_of_range const &ex) {
            return true;
        } catch (std::invalid_argument const &ex) {
            return true;
        }

        return false;
    }

    bool isASCII(const std::string &str);
}

#endif //MONITOR_EXAMPLE_COMMONFUNCTIONS_H
