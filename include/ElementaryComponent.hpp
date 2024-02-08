/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** ElementaryComponent
*/

#pragma once

#include "Acomponent.hpp"

namespace nts {
    class AndComponent : public Acomponent {
    public:
        AndComponent();
        ~AndComponent();
        nts::Tristate compute(std::size_t pin) override;
    };

    class OrComponent : public Acomponent {
    public:
        OrComponent();
        ~OrComponent();
        nts::Tristate compute(std::size_t pin) override;
    };

    class NotComponent : public Acomponent {
    public:
        NotComponent();
        ~NotComponent();
        nts::Tristate compute(std::size_t pin) override;
    };
}
