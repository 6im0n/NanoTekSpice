/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Input
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class InputComponent : public Acomponent {
    public:
        InputComponent();
        ~InputComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
