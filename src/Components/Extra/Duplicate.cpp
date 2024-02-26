/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Duplicate
*/

#include "Components/Extra/Duplicate.hpp"

nts::DupComponent::DupComponent(std::string name) : AComponent(3, name)
{
}

nts::Tristate nts::DupComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return this->_links[1]->compute(this->_pins[1]);
    if (pin == 2 || pin == 3)
        return this->_links[1]->compute(this->_pins[1]);
    return nts::Tristate::Undefined;
}
