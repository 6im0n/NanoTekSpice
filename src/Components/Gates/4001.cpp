/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4001
*/

/*
           +----------4001----------+
 in_01  -1-|>-+---\         ignored-|-14-
           |  | or  |o-+             |
 in_02  -2-|>-+---/   |      /---+-<|-13- in_13
           |          |  +-o|  or |  |
 out_03 -3-|<---------+   |  \---+-<|-12- in_12
           |              |         |
 out_04 -4-|<---------+  +--------->|-11- out_11
           |          |             |
 in_05  -5-|>-+---\   |  +--------->|-10- out_10
           |  | or  |o-+  |          |
 in_06  -6-|>-+---/      |   /---+-<|-9-  in_09
           |             +-o|  or |  |
        -7-|-ignored         \---+-<|-8-  in_08
           +------------------------+
*/

#include "Components/Gates/4001.hpp"
#include "Components/Elementary/Nor.hpp"

nts::C4001::C4001() : AChipset(14)
{
    std::array<NorComponent*, 4> NorGates = {new nts::NorComponent, new nts::NorComponent, new nts::NorComponent, new nts::NorComponent};

    this->_intLinks = {
        nullptr,
        NorGates[0], NorGates[0], NorGates[0],
        NorGates[1], NorGates[1], NorGates[1], nullptr,
        NorGates[2], NorGates[2], NorGates[2],
        NorGates[3], NorGates[3], NorGates[3],
        nullptr
    };

    this->_intPins = {0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 3, 3, 2, 1, 0};
}

nts::Tristate nts::C4001::compute(std::size_t pin)
{
    if (pin == 0 || pin == 7 || pin == 14 || pin > this->_intPins.size())
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
