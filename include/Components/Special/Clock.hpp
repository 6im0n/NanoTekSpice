/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Clock
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class ClockComponent : public Acomponent {
    public:
        ClockComponent();
        ~ClockComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        void setState(nts::Tristate state) override;
    };
}
