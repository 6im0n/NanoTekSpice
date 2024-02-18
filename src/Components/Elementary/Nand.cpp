/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Nand
*/

#include "Components/Elementary/Nand.hpp"

nts::NandComponent::NandComponent() : Acomponent(3)
{
}

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate state1 = getLink(1);
        nts::Tristate state2 = getLink(2);
        if (state1 == nts::Tristate::True && state2 == nts::Tristate::True)
            return nts::Tristate::False;
        else if ((state1 == nts::Tristate::False || state2 == nts::Tristate::False ) && state1 != nts::Tristate::True && state2 != nts::Tristate::True)
            return nts::Tristate::True;
        else if ((state1 == nts::Tristate::True || state2 == nts::Tristate::True) && state1 != nts::Tristate::Undefined && state2 != nts::Tristate::Undefined)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    } else if (pin == 1 || pin == 2) {
        return this->_links[pin]->compute(this->_pins[pin]);
    }
    return nts::Tristate::Undefined;
}
