/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** True
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class TrueComponent : public Acomponent {
    public:
        TrueComponent();
        ~TrueComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
