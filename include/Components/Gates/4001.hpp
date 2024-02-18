/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4001
*/

#pragma once

#include <array>
#include "AChipset.hpp"
namespace nts {
    class C4001 : public AChipset {
    public:
        C4001();
        ~C4001() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
