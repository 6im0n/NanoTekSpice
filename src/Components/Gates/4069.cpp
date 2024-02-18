/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4069
*/

/*
           +----4069----+
 in_01  -1-|>--+    ign-|-14-
           |  _|_       |
           |  \ /   +--<|-13- in_13
           |   v   _|_  |
           |   O   \ /  |
           |   |    v   |
 out_02 -2-|<--+    O   |
           |        |   |
 in_03  -3-|>--+    +-->|-12- out_12
           |  _|_       |
           |  \ /   +--<|-11- in_11
           |   v   _|_  |
           |   O   \ /  |
           |   |    v   |
 out_04 -4-|<--+    O   |
           |        |   |
 in_05  -5-|>--+    +-->|-10- out_10
           |  _|_       |
           |  \ /   +--<|-9-  in_09
           |   v   _|_  |
           |   O   \ /  |
           |   |    v   |
 out_06 -6-|<--+    O   |
           |        |   |
        -7-|-ign    +-->|-8-  out_08
           +------------+
*/

#include "Components/Gates/4069.hpp"
#include "Components/Elementary/Not.hpp"

nts::C4069::C4069() : AChipset(14)
{
    std::array<NotComponent*, 6> NotGate = {new nts::NotComponent, new nts::NotComponent, new nts::NotComponent, new nts::NotComponent, new nts::NotComponent, new nts::NotComponent};

    this->_intLinks = {
        nullptr,
        NotGate[0], NotGate[0],
        NotGate[1], NotGate[1],
        NotGate[2], NotGate[2], nullptr,
        NotGate[3], NotGate[3],
        NotGate[4], NotGate[4],
        NotGate[5], NotGate[5],
        nullptr
    };
    this->_intPins = {0, 1, 2, 1, 2, 1, 2, 0, 2, 1, 2, 1, 2, 1, 0};
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    if (pin == 0 || pin == 7 || pin == 14 || pin > _intPins.size()){
        return nts::Tristate::Undefined;
    }
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
