/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4069
*/

#pragma once

#include <array>
#include "AChipset.hpp"

namespace nts {
    class C4069 : public AChipset {
    public:
        C4069();
        ~C4069() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
