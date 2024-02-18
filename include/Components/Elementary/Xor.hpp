/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Xor
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class XorComponent : public AComponent {
    public:
        XorComponent(std::string name = "");
        ~XorComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
