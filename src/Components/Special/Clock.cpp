/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Clock
*/


#include "Components/Special/Clock.hpp"

nts::ClockComponent::ClockComponent() : Acomponent(1)
{
}

void nts::ClockComponent::setState(nts::Tristate state)
{
    this->_state = state;

}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin == 1 && this->_ticks % 2 == 0)
        return this->_state;
    else
        return (this->_state == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True;
    return nts::Tristate::Undefined;
}
