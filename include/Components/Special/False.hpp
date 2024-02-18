/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** False
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
        public:
            FalseComponent(std::string name);
            ~FalseComponent() = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}
