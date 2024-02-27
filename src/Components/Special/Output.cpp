/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Output
*/

#include "Components/Special/Output.hpp"

nts::OutputComponent::OutputComponent(std::string name) : AComponent(1, name)
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 1 && this->_links[pin] != nullptr)
        return this->_links[pin]->compute(this->_pins[pin]);
    return nts::Tristate::Undefined;
}
