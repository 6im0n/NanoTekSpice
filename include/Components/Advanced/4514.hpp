/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4514
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class C4514 : public AComponent {
    public:
        C4514(std::string name = "");
        ~C4514() = default;
        nts::Tristate compute(std::size_t pin) override;
        void updateState(void);
        void resetState(void);
    private:
        std::array<nts::Tristate, 16> _out;
        std::map<size_t, size_t> _pinMap;
    };
}
