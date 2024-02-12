/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Acomponent
*/

#include "Acomponent.hpp"

nts::Acomponent::Acomponent()
{
}

nts::Acomponent::Acomponent(size_t size)
{
    this->_links.resize(size + 1);
    this->_pins.resize(size + 1);
    for (size_t i = 0; i < size + 1; i++) {
        this->_links[i] = nullptr;
        this->_pins[i] = nts::Tristate::Undefined;
    }
}


nts::Acomponent::~Acomponent()
{
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