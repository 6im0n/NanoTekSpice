/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4040
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class C4040 : public AComponent {
    public:
        C4040(std::string name = "");
        ~C4040() = default;
        nts::Tristate compute(std::size_t pin) override;
        void updateState(void);
        void resetState(void);
    private:
        std::vector<nts::Tristate> _out;
        std::map<size_t, size_t> _pinMap;
        nts::Tristate _prevClock;
        int _prevValue;
    };
}
