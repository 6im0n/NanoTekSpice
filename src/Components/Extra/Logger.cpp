/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Logger
*/


#include "Components/Extra/Logger.hpp"

nts::Logger::Logger(std::string name) : AComponent(10, name)
{
    this->_prevClock = nts::Tristate::Undefined;
}

nts::Tristate nts::Logger::compute(std::size_t pin)
{
    std::vector<nts::Tristate> inputs = {getLink(1), getLink(2), getLink(3), getLink(4),
        getLink(5), getLink(6), getLink(7), getLink(8)};
    nts::Tristate clock = getLink(9);
    nts::Tristate inhibit = getLink(10);
    size_t value = 0;

    if (pin == 11)
        std::cout << "Logger: " << this->getName() << std::endl; // TODO Add logics
    if (pin == 0 || pin == 10 || pin > this->_pins.size())
        return nts::Tristate::Undefined;
    if (inhibit == nts::Tristate::True || inhibit == nts::Tristate::Undefined)
        return nts::Tristate::False;
    if (clock == nts::Tristate::True && this->_prevClock == nts::Tristate::False) {
        for (size_t i = 0; i < inputs.size(); i++) {
            value += (inputs[i] == nts::Tristate::True) ? 1 << i : 0;
        }
        std::cout << value << std::endl;
    }
    this->_prevClock = clock;
    return nts::Tristate::False;
}
