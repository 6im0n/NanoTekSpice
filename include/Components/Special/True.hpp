/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** True
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
    public:
        TrueComponent(std::string name);
        ~TrueComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
