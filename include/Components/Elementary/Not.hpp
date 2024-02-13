/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Not
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class NotComponent : public Acomponent {
    public:
        NotComponent();
        ~NotComponent();
        nts::Tristate compute(std::size_t pin) override;
    };
}