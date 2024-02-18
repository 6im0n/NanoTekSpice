/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Or
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
    public:
        OrComponent(std::string name);
        ~OrComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
