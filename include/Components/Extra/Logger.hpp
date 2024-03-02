/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Logger
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class Logger : public AComponent {
        public:
            Logger(std::string name = "");
            ~Logger() = default;
            nts::Tristate compute(std::size_t pin) override;
        private:
           nts::Tristate _prevClock;
    };
}
