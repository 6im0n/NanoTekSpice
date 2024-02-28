/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** AChipset
*/

#include "Components/AChipset.hpp"

nts::AChipset::AChipset(size_t size, std::string name)
{
    this->_ticks = 0;
    this->_name = name;
    this->_intLinks = std::deque<nts::IComponent *>(size + 1, nullptr);
    this->_extlinks = std::deque<nts::IComponent *>(size + 1, nullptr);
    this->_intPins = std::deque<size_t>(size + 1, 0);
    this->_extPins = std::deque<size_t>(size + 1, 0);
    this->loop = 0;
}

void nts::AChipset::setState(nts::Tristate state)
{
    (void)state;
}

void nts::AChipset::simulate(std::size_t tick)
{
    (void)tick;
    this->loop = 0;
}

void nts::AChipset::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (this->_intLinks[pin] == nullptr) {
        throw nts::Error("Invalid internal link");
    }
    this->_extlinks[pin] = &other;
    this->_extPins[pin] = otherPin;
    this->_intLinks[pin]->setLink(this->_intPins[pin], other, otherPin);
}

nts::Tristate nts::AChipset::getLink(std::size_t pin)
{
    if (this->_extlinks[pin] == nullptr)
        return nts::Tristate::Undefined;
    return this->_extlinks[pin]->compute(this->_extPins[pin]);
}

std::string nts::AChipset::getName() const
{
    return this->_name;
}

void nts::AChipset::checkIfNotLoop()
{
    if (this->loop >= MAX_LOOP)
        throw nts::Error("Infinite loop detected");
    this->loop++;
}
