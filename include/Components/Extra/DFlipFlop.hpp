/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** DFlipFlop
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class DFlipFlop : public AComponent {
        public:
            DFlipFlop(std::string name = "");
            ~DFlipFlop() = default;
            nts::Tristate compute(std::size_t pin) override;
            void updateState(void);

        private:
            nts::Tristate _prevStateQ;
            nts::Tristate _prevStateQ2;
            nts::Tristate _prevClock;
    };
}
