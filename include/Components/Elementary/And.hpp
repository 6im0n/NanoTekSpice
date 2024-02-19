/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** And
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
    public:
        AndComponent(std::string name = "");
        ~AndComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
