/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Xor
*/

#include "Components/Elementary/Xor.hpp"

nts::XorComponent::XorComponent(std::string name) : AComponent(3, name)
{
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 3) {
        nts::Tristate state1 = getLink(1);
        nts::Tristate state2 = getLink(2);
        if ( state1 == state2 && state1 != nts::Tristate::Undefined)
            return nts::Tristate::False;
        else if (state1 != state2 && state1 != nts::Tristate::Undefined && state2 != nts::Tristate::Undefined)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    } else if (pin == 1 || pin == 2) {
        return this->_links[pin]->compute(this->_pins[pin]);
    }
    return nts::Tristate::Undefined;
}
