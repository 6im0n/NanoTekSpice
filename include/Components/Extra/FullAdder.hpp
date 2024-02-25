/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** FullAdder
*/

#pragma once

#include "Components/AChipset.hpp"

namespace nts {
    class FullAdder : public AChipset {
        public:
            FullAdder(std::string name = "");
            ~FullAdder() = default;
            nts::Tristate compute(std::size_t pin) override;

    };
}
