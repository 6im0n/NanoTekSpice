/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4030
*/

/*

           +---------4030---------+
 in_01  -1-|>-+---\       ignored-|-14-
           |  |xor |-+            |
 in_02  -2-|>-+---/  |     /---+-<|-13- in_13
           |         |  +-| xor|  |
 out_03 -3-|<--------+  |  \---+-<|-12- in_12
           |            |         |
 out_04 -4-|<--------+  +-------->|-11- out_11
           |         |            |
 in_05  -5-|>-+---\  |  +-------->|-10- out_10
           |  |xor |-+  |         |
 in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
           |            +-| xor|  |
        -7-|-ignored       \---+-<|-8-  in_08
           +----------------------+
*/
#include "Components/Gates/4030.hpp"
#include "Components/Elementary/Xor.hpp"

nts::C4030::C4030() : AChipset(14)
{
    std::array<XorComponent*, 4> XorGate = {new nts::XorComponent, new nts::XorComponent, new nts::XorComponent, new nts::XorComponent};

    this->_intLinks = {
        nullptr,
        XorGate[0], XorGate[0], XorGate[0],
        XorGate[1], XorGate[1], XorGate[1], nullptr,
        XorGate[2], XorGate[2], XorGate[2],
        XorGate[3], XorGate[3], XorGate[3],
        nullptr
    };
    this->_intPins = {0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 3, 3, 2, 1, 0};
}

nts::Tristate nts::C4030::compute(std::size_t pin)
{
    if (pin == 0 || pin == 7 || pin == 14 || pin > _intPins.size())
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
