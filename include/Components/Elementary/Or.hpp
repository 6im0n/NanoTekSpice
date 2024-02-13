/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Or
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class OrComponent : public Acomponent {
    public:
        OrComponent();
        ~OrComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
