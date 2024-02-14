/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Output
*/

#include "Components/Special/Output.hpp"

nts::OutputComponent::OutputComponent() : Acomponent(1)
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin == 1 && this->_links[pin] != nullptr)
        return this->_links[pin]->compute(this->_pins[pin]);
    return nts::Tristate::Undefined;
}
