/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** SpecialComponent
*/

#pragma once
#include "Acomponent.hpp"

namespace nts {
    class InputComponent : public Acomponent {
    public:
        InputComponent();
        ~InputComponent();
        nts::Tristate compute(std::size_t pin) override;
    };

    class OutputComponent : public Acomponent {
    public:
        OutputComponent();
        ~OutputComponent();
        nts::Tristate compute(std::size_t pin) override;
    };

    class FalseComponent : public Acomponent {
    public:
        FalseComponent();
        ~FalseComponent();
        nts::Tristate compute(std::size_t pin) override;
    };

    class TrueComponent : public Acomponent {
    public:
        TrueComponent();
        ~TrueComponent();
        nts::Tristate compute(std::size_t pin) override;
    };
}
