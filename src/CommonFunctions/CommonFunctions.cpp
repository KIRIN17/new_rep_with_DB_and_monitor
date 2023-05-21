#include <algorithm>
#include <string>
#include <vector>

#include "CommonFunctions.h"

namespace MonCom{
    bool isWhitespace(char symbol) {
        static constexpr char whitespaces[] = { ' ', '\t', '\0' };
        return std::any_of(std::begin(whitespaces), std::end(whitespaces), [symbol](char wp) -> bool {
            return symbol == wp;
        });
    }

    void toLower(std::string &text) {
        std::for_each(std::begin(text), std::end(text), [](char &symbol) -> void{
            symbol = static_cast<char>(std::tolower(symbol));
        }); // cast to lower case
    }

    std::string toLower(std::string &&text) {
        std::for_each(std::begin(text), std::end(text), [](char &symbol) -> void{
            symbol = static_cast<char>(std::tolower(symbol));
        }); // cast to lower case
        return text;
    }

    bool isASCII(const std::string &str){
        return !std::any_of(std::begin(str), std::end(str), [](const char character) -> bool {
            return character < 0;
        });
    }
}
