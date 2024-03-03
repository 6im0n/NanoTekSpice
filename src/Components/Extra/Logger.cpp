/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Logger
*/

/*
 Byte Logger Component

           +-Logger-+
           |        |
 in_001 -1->        |
           |        |
 in_002 -2->        |
           |        |
 in_004 -3->        |
           |        |
 in_008 -4->        |
           |        |
 in_016 -5->        |
           |        |
 in_032 -6->        |
           |        |
 in_064 -7->        |
           |        |
 in_128 -8->        |
           |        |
           +-^----^-+
             |    |
    clock -9-+    +-10- inhibit
*/

#include <fstream>
#include "Components/Extra/Logger.hpp"

nts::Logger::Logger(std::string name) : AComponent(10, name)
{
    this->_prevClock = nts::Tristate::Undefined;
}

nts::Tristate nts::Logger::compute(std::size_t pin)
{
    nts::Tristate clock = getLink(9);
    nts::Tristate inhibit = getLink(10);


    if (pin == 0 || pin > this->_pins.size())
        return nts::Tristate::Undefined;
    if (pin == 10 || pin == 9)
        return this->_links[pin]->compute(this->_pins[pin]);
    if (inhibit == nts::Tristate::True || inhibit == nts::Tristate::Undefined) {
        this->_prevClock = clock;
        return nts::Tristate::False;
    }
    if (pin == 11) {
        logToFile(clock, pin);
    }
    this->_prevClock = clock;
    return nts::Tristate::True;
}

void nts::Logger::logToFile(nts::Tristate clock, size_t pin)
{
    std::vector<nts::Tristate> inputs =
        {getLink(1), getLink(2), getLink(3), getLink(4),
        getLink(5), getLink(6), getLink(7), getLink(8)};
    std::ofstream file;
    char value = 0;

    for (size_t i = 0; i < inputs.size(); i++) {
        if (inputs[i] == nts::Tristate::Undefined) {
            this->_prevClock = clock;
            return;
        }
    }
    if (clock == nts::Tristate::True && this->_prevClock
            == nts::Tristate::False && pin == 11) {
        for (size_t i = 0; i < inputs.size(); i++) {
            value += (inputs[i] == nts::Tristate::True) ? 1 << i : 0;
        }
        file.open("./log.bin", std::ios::app);
        file << value;
        file.close();
    }
}