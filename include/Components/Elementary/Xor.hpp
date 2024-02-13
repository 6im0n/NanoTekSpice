/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Xor
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class XorComponent : public Acomponent {
    public:
        XorComponent();
        ~XorComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
