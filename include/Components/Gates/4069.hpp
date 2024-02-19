/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4069
*/

#pragma once

#include <array>
#include "Components/AChipset.hpp"

namespace nts {
    class C4069 : public AChipset {
    public:
        C4069(std::string name = "");
        ~C4069() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
