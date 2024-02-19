/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4011
*/

#pragma once

#include <array>
#include "Components/AChipset.hpp"

namespace nts {
    class C4011 : public AChipset {
    public:
        C4011(std::string name = "");
        ~C4011() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
