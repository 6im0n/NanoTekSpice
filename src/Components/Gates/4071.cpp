/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4071
*/

/*

           +---------4071---------+
 in_01  -1-|>-+---\       ignored-|-14-
           |  | or |-+            |
 in_02  -2-|>-+---/  |     /---+-<|-13- in_13
           |         |  +-| or |  |
 out_03 -3-|<--------+  |  \---+-<|-12- in_12
           |            |         |
 out_04 -4-|<--------+  +-------->|-11- out_11
           |         |            |
 in_05  -5-|>-+---\  |  +-------->|-10- out_10
           |  | or |-+  |         |
 in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
           |            +-| or |  |
        -7-|-ignored       \---+-<|-8-  in_08
           +----------------------+

*/

#include "Components/Gates/4071.hpp"
#include "Components/Elementary/Or.hpp"
#include <array>
#include <iostream>

nts::C4071::C4071() : AChipset(14)
{
    std::array<OrComponent*, 4> OrGate = {new nts::OrComponent, new nts::OrComponent, new nts::OrComponent, new nts::OrComponent};

    this->_intLinks = {
        nullptr,
        OrGate[0], OrGate[0], OrGate[0],
        OrGate[1], OrGate[1], OrGate[1], nullptr,
        OrGate[2], OrGate[2], OrGate[2],
        OrGate[3], OrGate[3], OrGate[3],
        nullptr
    };
    this->_intPins = {0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 3, 3, 2, 1, 0};
}

nts::Tristate nts::C4071::compute(std::size_t pin)
{
    if (pin == 0 || pin == 7 || pin == 14 || this->_intLinks[pin] == nullptr)
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
