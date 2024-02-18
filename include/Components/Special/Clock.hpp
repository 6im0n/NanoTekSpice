/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Clock
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class ClockComponent : public AComponent {
    public:
        ClockComponent(std::string name);
        ~ClockComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setState(nts::Tristate state) override;
    private:
        nts::Tristate _state;
    };
}
