/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4515
*/

#pragma once

#include "Components/AComponent.hpp"

namespace nts {
    class C4515 : public AComponent {
    public:
        C4515(std::string name = "");
        ~C4515() = default;
        nts::Tristate compute(std::size_t pin) override;
        void updateState(void);
        void resetState(void);
        void initialOutput(void);
    private:
        std::vector<nts::Tristate> _out;
        std::map<size_t, size_t> _pinMap;
    };
}
