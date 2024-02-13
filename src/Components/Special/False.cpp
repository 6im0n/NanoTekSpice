/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** False
*/

#include "Components/Special/False.hpp"

nts::FalseComponent::FalseComponent() : Acomponent(1)
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}
