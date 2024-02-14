/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Input
*/

#include "Components/Special/Input.hpp"

nts::InputComponent::InputComponent() : Acomponent(1)
{
    this->_state = nts::Tristate::Undefined;
}

void nts::InputComponent::setState(nts::Tristate state)
{
    this->_state = state;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return this->_state;
    return nts::Tristate::Undefined;
}
