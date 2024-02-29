/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4017
*/

#pragma once

#include <array>
#include "Components/AComponent.hpp"

namespace nts {
    class C4017 : public AComponent {
    public:
        C4017(std::string name = "");
        ~C4017() = default;
        nts::Tristate compute(std::size_t pin) override;
        void updateState(void);
        void resetState(void);
    private:
        std::array<nts::Tristate, 11> _out;
        std::map<int, int> _pinMap;
        nts::Tristate _prevClock;
        int _prevValue;
    };
}
