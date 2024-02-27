/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4013
*/

#pragma once

#include <array>
#include "Components/AChipset.hpp"

namespace nts {
    class C4013 : public AChipset {
        public:
            C4013(std::string name = "");
            ~C4013() = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}
