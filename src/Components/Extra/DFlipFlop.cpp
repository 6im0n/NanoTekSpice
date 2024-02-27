/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** DFlipFlop
*/

#include "Components/Extra/DFlipFlop.hpp"

nts::DFlipFlop::DFlipFlop(std::string name) : AComponent(6, name)
{
    this->_prevClock = nts::Tristate::Undefined;
    this->_prevStateQ = nts::Tristate::Undefined;
    this->_prevStateQ2 = nts::Tristate::Undefined;
}

nts::Tristate nts::DFlipFlop::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 5 || pin == 6) {
        this->updateState();
        if (pin == 5)
            return this->_prevStateQ;
        else
            return this->_prevStateQ2;
    }
    if (pin == 1 || pin == 2 || pin == 3 || pin == 4)
        return this->_links[pin]->compute(this->_pins[pin]);
    return nts::Tristate::Undefined;
}

void nts::DFlipFlop::updateState(void)
{
    nts::Tristate clock = getLink(1);
    nts::Tristate data = getLink(2);
    nts::Tristate reset = getLink(3);
    nts::Tristate set = getLink(4);

    if (set == nts::Tristate::True || reset == nts::Tristate::True) {
        this->_prevStateQ = set;
        this->_prevStateQ2 = reset;
        return;
    } else if (set == nts::Tristate::False && reset == nts::Tristate::False && clock == nts::Tristate::False) {
        return;
    } else if (set == nts::Tristate::Undefined || reset == nts::Tristate::Undefined ||
    clock == nts::Tristate::Undefined || data == nts::Tristate::Undefined) {
        this->_prevStateQ = nts::Tristate::Undefined;
        this->_prevStateQ2 = nts::Tristate::Undefined;
        return;
    } else {
        this->_prevStateQ = data == nts::Tristate::True ? nts::Tristate::True : nts::Tristate::False;
        this->_prevStateQ2 = data == nts::Tristate::True ? nts::Tristate::False : nts::Tristate::True;
    }
}
