/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4013
*/

/*
 Dual D-Type Flip-Flop (4013)

     cl_1_clock  -3-+
                    |
                +---v---+
                |   |   |
                | +-v-+ |
                | |   | |
 in_1_data   -5->-> L | |
                | | A >->-1-  out_1_q
 in_1_set    -6->-> T | |
                | | C >->-2-  out_1_qb
 in_1_reset  -4->-> H | |
                | |   | |
                | +---+ |
                |       |
                | +---+ |
                | |   | |
 in_2_data   -9->-> L | |
                | | A >->-13- out_2_q
 in_2_set    -8->-> T | |
                | | C >->-12- out_2_qb
 in_2_reset -10->-> H | |
                | |   | |
                | +-^-+ |
                |   |   |
                +---^---+
                    |
     cl_2_clock -11-+
*/

#include "Components/Advanced/4013.hpp"
#include "Components/Extra/DFlipFlop.hpp"

nts::C4013::C4013(std::string name) : AChipset(14, name)
{
    std::array<DFlipFlop*, 2> DFlipFlops = {
        new nts::DFlipFlop,
        new nts::DFlipFlop
    };

    this->_intLinks = {
        nullptr,
        DFlipFlops[0], DFlipFlops[0], DFlipFlops[0],
        DFlipFlops[0], DFlipFlops[0], DFlipFlops[0],
        nullptr,
        DFlipFlops[1], DFlipFlops[1], DFlipFlops[1],
        DFlipFlops[1], DFlipFlops[1], DFlipFlops[1],
        nullptr
    };

    this->_intPins = {0, 5, 6, 1, 3, 2, 4, 0, 4, 2, 3, 1, 6, 5, 0};
}

nts::Tristate nts::C4013::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 0 || pin == 7 || pin == 14 || pin > this->_intPins.size()) {
        return nts::Tristate::Undefined;
    }
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
