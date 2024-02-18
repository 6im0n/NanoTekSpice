/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4011
*/

/*
           +----------4011----------+
 in_01  -1-|>-+---\         ignored-|-14-
           |  | &  |o-+             |
 in_02  -2-|>-+---/   |      /---+-<|-13- in_13
           |          |  +-o|  & |  |
 out_03 -3-|<---------+   |  \---+-<|-12- in_12
           |              |         |
 out_04 -4-|<---------+  +--------->|-11- out_11
           |          |             |
 in_05  -5-|>-+---\   |  +--------->|-10- out_10
           |  | &  |o-+  |          |
 in_06  -6-|>-+---/      |   /---+-<|-9-  in_09
           |             +-o|  & |  |
        -7-|-ignored         \---+-<|-8-  in_08
           +------------------------+
*/

#include "Components/Gates/4011.hpp"
#include "Components/Elementary/Nand.hpp"

nts::C4011::C4011() : AChipset(14)
{
    std::array<NandComponent*, 4> NandGates = {new nts::NandComponent, new nts::NandComponent, new nts::NandComponent, new nts::NandComponent};

    this->_intLinks = {
        nullptr,
        NandGates[0], NandGates[0], NandGates[0],
        NandGates[1], NandGates[1], NandGates[1], nullptr,
        NandGates[2], NandGates[2], NandGates[2],
        NandGates[3], NandGates[3], NandGates[3],
        nullptr
    };

    this->_intPins = {0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 3, 3, 2, 1, 0};
}

nts::Tristate nts::C4011::compute(std::size_t pin)
{
    if (pin == 0 || pin == 7 || pin == 14 || pin > _intPins.size())
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
