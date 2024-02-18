/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4081
*/

/*
           +---------4081---------+
 in_01  -1-|>-+---\       ignored-|-14-
           |  | &  |-+            |
 in_02  -2-|>-+---/  |     /---+-<|-13- in_13
           |         |  +-|  & |  |
 out_03 -3-|<--------+  |  \---+-<|-12- in_12
           |            |         |
 out_04 -4-|<--------+  +-------->|-11- out_11
           |         |            |
 in_05  -5-|>-+---\  |  +-------->|-10- out_10
           |  | &  |-+  |         |
 in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
           |            +-|  & |  |
        -7-|-ignored       \---+-<|-8-  in_08
           +----------------------+
*/

#include "Components/Gates/4081.hpp"
#include "Components/Elementary/And.hpp"

nts::C4081::C4081() : AChipset(14)
{
    std::array<AndComponent*, 4> andGate = {new nts::AndComponent, new nts::AndComponent, new nts::AndComponent, new nts::AndComponent};

    this->_intLinks = {
        nullptr,
        andGate[0], andGate[0], andGate[0],
        andGate[1], andGate[1], andGate[1], nullptr,
        andGate[2], andGate[2], andGate[2],
        andGate[3], andGate[3], andGate[3],
        nullptr
    };

    this->_intPins = {0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 3, 3, 2, 1, 0};
}

nts::Tristate nts::C4081::compute(std::size_t pin)
{
    if (pin == 0 || pin == 7 || pin == 14 || pin > this->_intPins.size())
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
