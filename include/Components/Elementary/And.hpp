/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** And
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class AndComponent : public Acomponent {
    public:
        AndComponent();
        ~AndComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
