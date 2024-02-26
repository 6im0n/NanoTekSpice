/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4514
*/

#pragma once

#include <array>
#include "Components/AChipset.hpp"

namespace nts {
    class C4514 : public AChipset {
    public:
        C4514(std::string name = "");
        ~C4514() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
