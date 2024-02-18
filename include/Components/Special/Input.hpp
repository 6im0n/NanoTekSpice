/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Input
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class InputComponent : public AComponent {
    public:
        InputComponent(std::string name);
        ~InputComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
        void setState(nts::Tristate state) override;
    private:
        nts::Tristate _state;
    };
}
