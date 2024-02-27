/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** True
*/

#include "Components/Special/True.hpp"

nts::TrueComponent::TrueComponent(std::string name) : AComponent(1, name)
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 1)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}
