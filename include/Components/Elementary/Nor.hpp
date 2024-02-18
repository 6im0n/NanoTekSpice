/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** And
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class NorComponent : public AComponent {
    public:
        NorComponent(std::string name = "");
        ~NorComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
