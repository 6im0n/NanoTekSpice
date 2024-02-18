/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4071
*/

#pragma once

#include <array>
#include "Components/AChipset.hpp"

namespace nts {
    class C4071 : public AChipset {
    public:
        C4071(std::string name = "");
        ~C4071() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
