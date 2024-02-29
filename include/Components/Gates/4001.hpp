/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4001
*/

#pragma once

#include "Components/AChipset.hpp"

namespace nts {
    class C4001 : public AChipset {
    public:
        C4001(std::string name = "");
        ~C4001() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
