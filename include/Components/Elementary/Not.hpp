/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Not
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
    public:
        NotComponent(std::string name);
        ~NotComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
