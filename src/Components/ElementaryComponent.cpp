/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** ElementaryComponents
*/

#include "ElementaryComponent.hpp"

nts::AndComponent::AndComponent() : Acomponent(3)
{
}

nts::AndComponent::~AndComponent()
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate state1 = getLink(1);
        nts::Tristate state2 = getLink(2);
        if (state1 == nts::Tristate::True && state2 == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::False;
    } else if (pin == 1 || pin == 2) {
        return this->_links[pin]->compute(this->_pins[pin]);
    }
    return nts::Tristate::Undefined;
}

nts::OrComponent::OrComponent() : Acomponent(3)
{
}

nts::OrComponent::~OrComponent()
{
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate state1 = getLink(1);
        nts::Tristate state2 = getLink(2);
        if (state1 == nts::Tristate::True || state2 == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::False;
    } else if (pin == 1 || pin == 2) {
        return this->_links[pin]->compute(this->_pins[pin]);
    }
    return nts::Tristate::Undefined;
}

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