/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4030
*/

#pragma once

#include <array>
#include "Components/AChipset.hpp"

namespace nts {
    class C4030 : public AChipset {
    public:
        C4030(std::string name = "");
        ~C4030() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
