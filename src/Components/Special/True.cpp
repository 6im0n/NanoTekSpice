/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** True
*/

#include "Components/Special/True.hpp"

nts::TrueComponent::TrueComponent() : Acomponent(1)
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}
