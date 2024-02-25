/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4008
*/

/*
    4-bits Adder (4008)

                  +-14- out_c
                  |
           +-4008-^------+
           |      |      |
 in_b4 -15->---+--^--+   |
           |   | sum |--->-13- out_3
 in_a4  -1->---+--+--+   |
           |      |      |
 in_b3  -2->---+--^--+   |
           |   | sum |--->-12- out_2
 in_a3  -3->---+--+--+   |
           |      |      |
 in_b2  -4->---+--^--+   |
           |   | sum |--->-11- out_1
 in_a2  -5->---+--+--+   |
           |      |      |
 in_b1  -6->---+--^--+   |
           |   | sum |--->-10- out_0
 in_a1  -7->---+--+--+   |
           |      |      |
 in_c   -9->------+      |
           |             |
        -8-+- ign   ign -+-16-
           |             |
           +-------------+
*/

#include "Components/Advanced/4008.hpp"
#include "Components/Extra/FullAdder.hpp"

nts::C4008::C4008(std::string name) : AChipset(16, name)
{
    std::array<FullAdder*, 4> FullAdders = {
        new nts::FullAdder,
        new nts::FullAdder,
        new nts::FullAdder,
        new nts::FullAdder
    };

    FullAdders[0]->setLink(3, *FullAdders[1], 5);
    FullAdders[1]->setLink(3, *FullAdders[2], 5);
    FullAdders[2]->setLink(3, *FullAdders[3], 5);

    this->_intLinks = {
        nullptr,
        FullAdders[0], FullAdders[1], FullAdders[1], FullAdders[2],
        FullAdders[2], FullAdders[3], FullAdders[3], nullptr,
        FullAdders[3], FullAdders[3], FullAdders[2], FullAdders[1],
        FullAdders[0], FullAdders[0], FullAdders[0], nullptr
    };

    this->_intPins = {0, 2, 1, 2, 1, 2, 1, 2, 0, 3, 4, 4, 4, 4, 5, 1, 0};
}

nts::Tristate nts::C4008::compute(std::size_t pin)
{
    if (pin == 0 || pin == 8 || pin == 16 || pin > this->_intPins.size())
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
