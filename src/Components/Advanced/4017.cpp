/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4017
*/

/*
 Johnson Decade Counter (4017)

          +-4017----------------+
          |                     |
 in_0 -14->                     |
          |   JOHNSON DECADE    |
 in_1 -13->       COUNTER       |
          |                     |
 in_r -15->                     >-12- out_s
          |                     |
          +-v-v-v-v-v-v-v-v-v-v-+
            | | | | | | | | | |
   out_0 -3-+ | | | | | | | | +-11- out_9
     out_1 -2-+ | | | | | | +-9- out_8
       out_2 -4-+ | | | | +-6- out_7
         out_3 -7-+ | | +-5- out_6
          out_4 -10-+ +-1- out_5
*/

#include "Components/Advanced/4017.hpp"

nts::C4017::C4017(std::string name) : AComponent(16, name)
{
    this->_out = std::vector<nts::Tristate>(11, nts::Tristate::Undefined);
    this->_prevClock = nts::Tristate::Undefined;
    this->resetState();
    this->_pinMap = {{3, 0}, {2, 1}, {4, 2}, {7, 3}, {10, 4}, {1, 5}, {5, 6}, {6, 7}, {9, 8}, {11, 9}, {12, 10}};
}

nts::Tristate nts::C4017::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 0 || pin == 16 || pin == 8 || pin > this->_pins.size())
        return nts::Tristate::Undefined;
    if (pin == 14 || pin == 13 || pin == 15) {
        return this->_links[pin]->compute(this->_pins[pin]);
    } else {
        this->updateState();
        return this->_out[this->_pinMap.find(pin)->second];
    }
    return nts::Tristate::Undefined;
}

void nts::C4017::resetState(void)
{
    for (int i = 1; i < 10; i++)
        this->_out[i] = nts::Tristate::False;
    this->_out[0] = nts::Tristate::True;
    this->_out[10] = nts::Tristate::True;
    this->_prevValue = 0;
}

void nts::C4017::updateState(void)
{
    nts::Tristate clock = getLink(14);
    nts::Tristate reset = getLink(15);
    nts::Tristate enable = getLink(13);

    if (reset == nts::Tristate::True) {
        this->resetState();
        return;
    }
    if (enable == nts::Tristate::True || enable == nts::Tristate::Undefined){
        enable == nts::Tristate::True ? this->_prevClock = nts::Tristate::False : this->_prevClock;
        return;
    }
    if (clock != this->_prevClock)
        this->_prevClock = clock;
    else
        return;
    for (int i = 0; i < 10; i++)
        this->_out[i] = nts::Tristate::False;
    if (clock == nts::Tristate::True) {
        this->_prevValue = (this->_prevValue + 1) % 10;
    }
    if (this->_prevValue < 5)
        this->_out[10] = nts::Tristate::True;
    else
        this->_out[10] = nts::Tristate::False;
    this->_out[this->_prevValue] = nts::Tristate::True;
}
