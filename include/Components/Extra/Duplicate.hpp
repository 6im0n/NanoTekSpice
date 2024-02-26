/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Duplicate
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class DupComponent : public AComponent {
        public:
            DupComponent(std::string name = "");
            ~DupComponent() = default;
            nts::Tristate compute(std::size_t pin) override;

    };
}
