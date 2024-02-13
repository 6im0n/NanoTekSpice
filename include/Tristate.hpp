/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Tristate
*/

#pragma once

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };
}