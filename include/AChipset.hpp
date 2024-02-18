/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** C
*/

#pragma once

#include "Icomponent.hpp"
#include <deque>

namespace nts {
    class AChipset : public IComponent {
    public:
        AChipset(size_t size);
        ~AChipset() = default;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) override;
        void setState(nts::Tristate state) override;
    protected:
        size_t _ticks;
        std::deque<IComponent *> _intLinks;
        std::deque<IComponent *> _extlinks;
        std::deque<size_t> _extPins;
        std::deque<size_t> _intPins;
    };
}
