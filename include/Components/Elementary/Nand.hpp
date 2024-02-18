/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** And
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class NandComponent : public AComponent {
    public:
        NandComponent(std::string name = "");
        ~NandComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
