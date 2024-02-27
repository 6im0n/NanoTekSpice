/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** C
*/

#pragma once

#include "IComponent.hpp"
#include <deque>

namespace nts {
    class AChipset : public IComponent {
    public:
        AChipset(size_t size, std::string name);
        ~AChipset() = default;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) override;
        void setState(nts::Tristate state) override;
        std::string getName() const override;
        void checkIfNotLoop();
    protected:
        size_t _ticks;
        std::string _name;
        std::deque<IComponent *> _intLinks;
        std::deque<IComponent *> _extlinks;
        std::deque<size_t> _extPins;
        std::deque<size_t> _intPins;
        size_t loop;
    };
}
