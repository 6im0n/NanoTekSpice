/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4514
*/

/*
 4-bits Decoder (4514)

                              +-11- out_00
                              |   +-09- out_01
                              |   |   +-10- out_02
                              |   |   |   +-08- out_03
                              |   |   |   |   +-07- out_04
              inhibit -23-+   |   |   |   |   |   +-06- out_05
                          |   |   |   |   |   |   |
          +---4514--------v---^---^---^---^---^---^-------+
          |               |   |   |   |   |   |   |       |
 in_0  -2->---+---+---+---+---+---+---+---+---+---+---+--->-05- out_06
          |   | L |   |                               |   |
 in_1  -3->---| A |---|                               +--->-04- out_07
          |   | T |   |        4-to-16 DECODER        |   |
 in_2 -21->---| C |---|                               +--->-18- out_08
          |   | H |   |                               |   |
 in_3 -22->---+---+---+-------+---+---+---+---+---+---+--->-17- out_09
          |     |  ign ign    |   |   |   |   |   |       |
          +-----^---+---+-----v---v---v---v---v---v-------+
                |   |   |     |   |   |   |   |   |
      strobe -1-+   |   |     |   |   |   |   |   +-20- out_10
                -12-+   |     |   |   |   |   +-19- out_11
                    -24-+     |   |   |   +-14- out_12
                              |   |   +-13- out_13
                              |   +-16- out_14
                              +-15- out_15
*/

#include "Components/Advanced/4514.hpp"

nts::C4514::C4514(std::string name) : AComponent(24, name)
{
    this->_pinMap = {{11, 0}, {9, 1}, {10, 2}, {8, 3}, {7, 4}, {6, 5}, {5, 6}, {4, 7}, {18, 8}, {17, 9}, {20, 10}, {19, 11}, {14, 12}, {13, 13}, {16, 14}, {15, 15}};
    this->resetState();
}

nts::Tristate nts::C4514::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 0 || pin == 24 || pin == 12 || pin > this->_pins.size())
        return nts::Tristate::Undefined;
    if (pin == 2 || pin == 3 || pin == 21 || pin == 22 || pin == 23) {
        return this->_links[pin]->compute(this->_pins[pin]);
    }
    if (getLink(23) == nts::Tristate::True)
        return nts::Tristate::False;
    else {
        this->updateState();
        return this->_out[this->_pinMap.find(pin)->second];
    }
}

void nts::C4514::resetState(void)
{
    for (int i = 0; i < 16; i++)
        this->_out[i] = nts::Tristate::False;
}

void nts::C4514::updateState(void)
{
    nts::Tristate inhibit = getLink(23);
    nts::Tristate strobe = getLink(1);
    nts::Tristate in_a = getLink(2);
    nts::Tristate in_b = getLink(3);
    nts::Tristate in_c = getLink(21);
    nts::Tristate in_d = getLink(22);
    std::array<nts::Tristate, 4> inputsArray = {in_a, in_b, in_c, in_d};
    std::array<bool, 4> inputs = {0, 0, 0, 0};
    int binaryValue = 0;

    if (strobe == nts::Tristate::False) {
        return;
    }
    if (inhibit == nts::Tristate::True || inhibit == nts::Tristate::Undefined) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        inputs[i] = (inputsArray[i] == nts::Tristate::True) ? 1 : 0;
        binaryValue += inputs[i] * (1 << i);
    }
    this->resetState();
    this->_out[binaryValue] = nts::Tristate::True;
}
