/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Not
*/

#include "Not.hpp"

nts::NotComponent::NotComponent() : Acomponent(2)
{
}

nts::NotComponent::~NotComponent()
{
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin == 2) {
        nts::Tristate state = getLink(1);
        if (state == nts::Tristate::True)
            return nts::Tristate::False;
        else if (state == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    } else if (pin == 1) {
        return this->_links[pin]->compute(this->_pins[pin]);
    }
    return nts::Tristate::Undefined;
}