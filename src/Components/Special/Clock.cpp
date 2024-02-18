/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Clock
*/


#include "Components/Special/Clock.hpp"

nts::ClockComponent::ClockComponent(std::string name) : AComponent(1, name)
{
    this->_state = nts::Tristate::Undefined;
}

void nts::ClockComponent::setState(nts::Tristate state)
{
    this->_state = state;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (this->_state == nts::Tristate::Undefined)
        return;
    if (tick % 2 == 0)
        this->_state = this->_state;
    else
        this->_state = (this->_state == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return this->_state;
    return nts::Tristate::Undefined;
}
