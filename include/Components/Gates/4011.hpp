/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4011
*/

#pragma once

#include <array>
#include "AChipset.hpp"

namespace nts {
    class C4011 : public AChipset {
    public:
        C4011();
        ~C4011() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
