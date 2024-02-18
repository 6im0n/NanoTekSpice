/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** And
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class NandComponent : public Acomponent {
    public:
        NandComponent();
        ~NandComponent() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}
