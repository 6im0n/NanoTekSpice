/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** False
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class FalseComponent : public Acomponent {
        public:
            FalseComponent();
            ~FalseComponent() = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}
