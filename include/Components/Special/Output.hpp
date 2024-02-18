/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Output
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class OutputComponent : public AComponent {
    public:
        OutputComponent(std::string name);
        ~OutputComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
