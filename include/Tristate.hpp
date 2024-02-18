/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Tristate
*/

#pragma once

#include "Include.hpp"

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };
}

std::ostream &operator<<(std::ostream &os, nts::Tristate const &value);
std::string operator+(std::string const &str, nts::Tristate const &value);
