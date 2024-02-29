/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4512
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class C4512 : public AComponent {
    public:
        C4512(std::string name = "");
        ~C4512() = default;
        nts::Tristate compute(size_t pin) override;
        nts::Tristate getOutput(void);
    };
}
