/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4030
*/

#pragma once

#include "AChipset.hpp"

namespace nts {
    class C4030 : public AChipset {
    public:
        C4030();
        ~C4030() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
