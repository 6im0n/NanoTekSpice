/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Output
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class OutputComponent : public Acomponent {
    public:
        OutputComponent();
        ~OutputComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
