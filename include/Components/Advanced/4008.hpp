/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4008
*/

#pragma once

#include "Components/AChipset.hpp"

namespace nts {
    class C4008 : public AChipset {
    public:
        C4008(std::string name = "");
        ~C4008() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
