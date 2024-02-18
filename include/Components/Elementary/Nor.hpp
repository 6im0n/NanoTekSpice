/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** And
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class NorComponent : public Acomponent {
    public:
        NorComponent();
        ~NorComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
