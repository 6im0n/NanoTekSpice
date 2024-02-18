/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Acomponent
*/

#include "Acomponent.hpp"


nts::Acomponent::Acomponent(size_t size)
{
    this->_ticks = 0;
    this->_links = std::deque<nts::IComponent *>(size + 1, nullptr);
    this->_pins = std::deque<size_t>(size + 1, 0);
}

void nts::Acomponent::setState(nts::Tristate state)
{
    (void)state;
}

void nts::Acomponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::Acomponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = &other;
    this->_pins[pin] = otherPin;
}

nts::Tristate nts::Acomponent::getLink(std::size_t pin)
{
    if (this->_links[pin] == nullptr)
        return nts::Tristate::Undefined;
    return this->_links[pin]->compute(this->_pins[pin]);
}
