/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Acomponent
*/

#pragma once

#include "Icomponent.hpp"
#include <deque>

namespace nts {
    class Acomponent : public IComponent {
    public:
        Acomponent(size_t);
        ~Acomponent() = default;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) override;
        void setState(nts::Tristate) override;
    protected:
        nts::Tristate _state;
        std::deque<IComponent*> _links;
        std::deque<size_t> _pins;
    };
}