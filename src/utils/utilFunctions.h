#ifndef MAIN_UTILFUNCTIONS_H
#define MAIN_UTILFUNCTIONS_H

#include <stdexcept>
#include <algorithm>

namespace MonUt {
    /**
     * Функция проверяет является ли входной символ пробелом или другим пропускаемым знаком (символ табуляции)
     * @param symbol входной символ
     * @return true если входной символ - пропускаемый знак, false - otherwise
     */
    bool isWhitespace(char symbol);

    /**
     * Преобразует символы в строке в нижний регистр
     * @param text строка
     */
    void toLower(std::string &text);

    std::string toLower(std::string &&text);
}

#endif //MAIN_UTILFUNCTIONS_H
