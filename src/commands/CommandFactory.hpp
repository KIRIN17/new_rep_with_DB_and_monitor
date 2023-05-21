#ifndef MAIN_COMMANDFACTORY_H
#define MAIN_COMMANDFACTORY_H

#include "BaseCommand.h"

template<typename CommandClasses>
class CommandFactory {
protected:
    template<std::size_t index, class ...Args>
    static typename std::enable_if<index == std::tuple_size_v<CommandClasses>, std::shared_ptr<BaseCommand>>::type
    construct(const std::string &query, [[maybe_unused]] Args... args){
        (void) query; // unused
        return nullptr;
    }

    /**
     * Сравнивает строку запроса с соответствующей строкой в классе команды, находящейся на index позиции в передаваемом
     * кортеже, при соответствии строит объект команды и возвращает указатель базовой команды, при несоответствии -
     * продолжает поиск рекурсивно по всем элементам кортежа
     * @tparam index Индекс класса команды в кортеже
     * @tparam Args Дополнительные аргументы, необходимые конструктору класса команды
     * @param query Строка запроса соответствующая искомой команде
     * @return Указатель на базовый класс команды
     */
    template<std::size_t index = 0, class ...Args>
    static typename std::enable_if<index < std::tuple_size_v<CommandClasses>, std::shared_ptr<BaseCommand>>::type
    construct(const std::string &query, Args... args){
        using CommandClass = std::tuple_element_t<index, CommandClasses>;
        if(query == CommandClass::getQuery()){
            return std::make_shared<CommandClass>(args...);
        }

        return construct<index + 1>(query, args...);
    }

public:
    CommandFactory() = default;
    CommandFactory(const CommandFactory &) = default;
    CommandFactory(CommandFactory &&) noexcept = default;
    virtual ~CommandFactory() noexcept = default;

    /**
     * Фабричный метод создает объект команды из строки запроса
     * @param commandQuery строка запроса, целиком состоящая из символов строки запроса искомого класса команды
     * @return указатель на объект типа класса базовой команды
     */
    virtual std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) {
        (void) commandString; // unused
        return nullptr;
    }
};

#endif //MAIN_COMMANDFACTORY_H
