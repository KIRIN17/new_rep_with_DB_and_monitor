#ifndef MAIN_PARSEREXCEPTION_H
#define MAIN_PARSEREXCEPTION_H

#include <stdexcept>

class ParserException : public std::exception{
protected:
    std::string message;
public:
    explicit ParserException(std::string message_) : message(std::move(message_)) {}
    explicit ParserException(const char *message_) : message(message_) {}

    ~ParserException() override = default;

    const char *what() const noexcept override { return message.c_str(); }
};

#endif //MAIN_PARSEREXCEPTION_H
