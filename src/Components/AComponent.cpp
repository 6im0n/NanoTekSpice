/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** AComponent
*/

#include "Components/AComponent.hpp"

nts::AComponent::AComponent(size_t size, const std::string &name)
{
    this->_ticks = 0;
    this->_links = std::deque<nts::IComponent *>(size + 1, nullptr);
    this->_pins = std::deque<size_t>(size + 1, 0);
    this->_name = name;
}

void nts::AComponent::setState(nts::Tristate state)
{
    (void)state;
}

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = &other;
    this->_pins[pin] = otherPin;
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (this->_links[pin] == nullptr)
        return nts::Tristate::Undefined;
    return this->_links[pin]->compute(this->_pins[pin]);
}

std::string nts::AComponent::getName() const
{
    return this->_name;
}
