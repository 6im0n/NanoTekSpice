/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Utils
*/

#include "Include.hpp"
#include "Utils/Utils.hpp"

void Utils::trimEnd(std::string &str) {
    const char *ws = " \t\n";

    str.erase(0, str.find_first_not_of(ws));
    str.erase(str.find_last_not_of(ws) + 1);
}
