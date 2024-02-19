/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Tristate
*/

#include "Utils/Tristate.hpp"

std::ostream &operator<<(std::ostream &os, nts::Tristate const &value)
{
    if (value == nts::Tristate::True)
        os << "1";
    else if (value == nts::Tristate::False)
        os << "0";
    else
        os << "U";
    return os;
}

std::string operator+(std::string const &str, nts::Tristate const &value)
{
    std::string ret = str;
    if (value == nts::Tristate::True)
        ret += "1";
    else if (value == nts::Tristate::False)
        ret += "0";
    else
        ret += "U";
    return ret;
}
