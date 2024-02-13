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

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin > 0 && pin <= _pins.size())
        return this->_state;
    return nts::Tristate::Undefined;
}
