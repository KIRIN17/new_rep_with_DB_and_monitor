#ifndef MONITOR_MONITOR_H
#define MONITOR_MONITOR_H

#include <iostream>
#include <memory>

#include "CommandFactory.hpp"
#include "MonitorInput.h"
#include "MonitorOutput.h"
#include "ParserException.h"
#include "MonitorHelp.h"

/**
 * Класс реализует монитор, принимает строки запросов из входного потока, передает выходную информацию в выходной поток
 * Для автоматизированного запуска можно использовать метод run.
 * Для ручного управления - методом processInput можно обрабатывать по одной строке за раз.
 * showPrompt чтобы показать готовность к принятию ввода.
 */
template<typename CommandClasses>
class Monitor {
private:
    std::unique_ptr<MonitorOutput> outputer;
    std::unique_ptr<MonitorInput> inputer;
    CommandFactory<CommandClasses> &commandFactory;

    /**
     * Выводимое при выходе сообщение
     */
    std::string exitMessage = "Exit message123";

    /**
     * Выводимое предложение ввода
     */
    std::string prompt = "-> ";

    /**
     * Печатает сообщение помощи
     */
    void printHelp() const;

    /**
     * Создает объект парсера из строки запроса
     * При ошибке выдает ее в выходной поток и печатает помощь
     * @param query строка запроса
     * @return указатель на парсер
     */
    std::shared_ptr<Parser> getParser(const std::string &query) const;

public:
    Monitor(CommandFactory<CommandClasses> &commandFactory_, std::istream &istream_, std::ostream &ostream_, bool echoing_);

    /**
     * Переустанавливает выходное сообщение
     */
    void setExitMessage(std::string newMessage);
    /**
     * Переустанавливает приглашение на ввод
     */
    void setPrompt(std::string newPrompt);

    /**
     * Метод принимает запрос из входного потока и обрабатывает его
     * Для окончания ввода подходит команда EXIT или символ EOF
     * @return false если пользователь ввел команду окончания ввода, true otherwise
     * @tparam Tuple Кортеж из классов команд, обрабатываемых монитором
     */
    bool processInput();
    /**
     * Метод сам управляет принятием ввода из консоли, выводит предложение на ввод
     * @tparam Tuple Кортеж из классов команд, обрабатываемых монитором
     */
    void run();
    /**
     * Функция выводит предложение ввода
     */
    void showPrompt() const;
};

template<typename CommandClasses>
Monitor<CommandClasses>::Monitor(CommandFactory<CommandClasses> &commandFactory_, std::istream &istream_, std::ostream &ostream_, bool echoing_) :
    outputer() , inputer() , commandFactory(commandFactory_)
{
    // init input output objs
    if(echoing_){
        outputer = std::make_unique<MonitorOutput>(ostream_, std::cout);
        inputer = std::make_unique<MonitorInput>(istream_, std::vector{ &std::cout, &ostream_});
    } else{
        outputer = std::make_unique<MonitorOutput>(ostream_);
        inputer = std::make_unique<MonitorInput>(istream_);
    }
}

template<typename CommandClasses>
bool Monitor<CommandClasses>::processInput() {
    std::string query = inputer->getline();

    if(query.empty() && inputer->eof()){
        return false;
    } else{
        std::shared_ptr<Parser> parser = getParser(query);
        if(parser == nullptr) return true;

        std::string &commandString = parser->getCommand();

        if(commandString == "exit") { // check if exiting
            return false;
        } else if(commandString.empty()){
            return true;
        } else { // do command thing
            // make command object
            std::shared_ptr<BaseCommand> command = commandFactory.getCommand(commandString);

            if (command == nullptr) { // if command doesn't exist
                *outputer << "Command " + commandString + " doesn't exist" << "\n";
                printHelp();
            } else { // run command
                std::string message = command->processQuery(*parser);
                *outputer << message << "\n";
            }
        }

        return true;
    }
}

template<typename CommandClasses>
void Monitor<CommandClasses>::run() {
    do{
        showPrompt();
    }while(processInput());

    *outputer << exitMessage;
}

template<typename CommandClasses>
std::shared_ptr<Parser> Monitor<CommandClasses>::getParser(const std::string &query) const {
    try{
        return std::make_shared<Parser>(Parser(query));
    } catch(ParserException &ex){
        *outputer << ex.what() << "\n";
        printHelp();
        return nullptr;
    }
}

template<typename CommandClasses>
void Monitor<CommandClasses>::printHelp() const {
    *outputer << MonitorHelp::getMessage() << "\n";
}

template<typename CommandClasses>
void Monitor<CommandClasses>::showPrompt() const {
    *outputer << prompt;
}

template<typename CommandClasses>
void Monitor<CommandClasses>::setExitMessage(std::string newMessage) {
    exitMessage = std::move(newMessage);
}

template<typename CommandClasses>
void Monitor<CommandClasses>::setPrompt(std::string newPrompt) {
    prompt = std::move(newPrompt);
}

#endif //MONITOR_MONITOR_H
