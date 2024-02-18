/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4081
*/

#pragma once

#include <array>
#include "AChipset.hpp"

namespace nts {
    class C4081 : public AChipset {
    public:
        C4081();
        ~C4081() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
