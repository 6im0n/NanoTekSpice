/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** SpecialComponents
*/

#include "SpecialComponent.hpp"

nts::TrueComponent::TrueComponent() : Acomponent(1)
{
}

nts::TrueComponent::~TrueComponent()
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::True;
}

nts::FalseComponent::FalseComponent() : Acomponent(1)
{
}

nts::FalseComponent::~FalseComponent()
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::False;
}

nts::InputComponent::InputComponent()
{
}

nts::InputComponent::~InputComponent()
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::Undefined;
}

nts::OutputComponent::OutputComponent()
{
}

nts::OutputComponent::~OutputComponent()
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::Undefined;
}