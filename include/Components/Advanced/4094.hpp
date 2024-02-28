/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4094
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class C4094 : public AComponent {
    public:
        C4094(std::string name = "");
        ~C4094() = default;
        nts::Tristate compute(size_t pin) override;
        void updateState(void);
        void updateAllStates(nts::Tristate value);
        void updateParallelOutput(nts::Tristate value);
        void bitShiftParallelOutput(nts::Tristate value);
    private:
        std::vector<nts::Tristate> _lastStates;
        nts::Tristate _stateQs;
        nts::Tristate _stateQe;
    };
}