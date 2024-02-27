/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** False
*/

#include "Components/Special/False.hpp"

nts::FalseComponent::FalseComponent(std::string name) : AComponent(1, name)
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 1)
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}
