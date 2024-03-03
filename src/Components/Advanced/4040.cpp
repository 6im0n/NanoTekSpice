/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4040
*/

/*
 12-bits Binary Counter (4040)

      cl_clock -10-+     +-11- in_reset
                   |     |
    +------4040----v-----v--------------+
 -8-|-ign   12-bit Binary Counter   ign-|-16-
    +------v-v-v-v-v-v-v-v-v-v-v-v------+
           | | | | | | | | | | | |
 out_00 -9-+ | | | | | | | | | | +-1- out_11
   out_01 -7-+ | | | | | | | | +-15- out_10
     out_02 -6-+ | | | | | | +-14- out_09
       out_03 -5-+ | | | | +-12- out_08
         out_04 -3-+ | | +-13- out_07
           out_05 -2-+ +-4- out_06
*/

#include "Components/Advanced/4040.hpp"

nts::C4040::C4040(std::string name) : AComponent(16, name)
{
    this->_out = std::vector<nts::Tristate>(12, nts::Tristate::Undefined);
    this->_prevClock = nts::Tristate::False;
    this->resetState();
    this->_pinMap = {{9, 0}, {7, 1}, {6, 2}, {5, 3}, {3, 4}, {2, 5}, {4, 6}, {13, 7}, {12, 8}, {14, 9}, {15, 10}, {1, 11}};
}

void nts::C4040::resetState(void)
{
    this->_prevValue = 0;
    for (int i = 0; i < 12; i++)
    	this->_out[i] = nts::Tristate::False;
}

void nts::C4040::updateState(void)
{
    nts::Tristate reset = this->getLink(11);
    nts::Tristate clock = this->getLink(10);

    if (reset == nts::Tristate::True) {
        this->resetState();
        this->_prevClock = clock;
        return;
    }
    if (clock == nts::Tristate::Undefined)
        return;
    if (clock == nts::Tristate::False && this->_prevClock == nts::Tristate::True) {
        this->_prevValue++;
        if (this->_prevValue == 4096)
            this->_prevValue = 0;
        for (int i = 0; i < 12; i++)
            this->_out[i] = (this->_prevValue & (1 << i)) ? nts::Tristate::True : nts::Tristate::False;
    }
    this->_prevClock = clock;
}

nts::Tristate nts::C4040::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 0 || pin == 8 || pin == 16 || pin > this->_pins.size())
        return nts::Tristate::Undefined;
    if (pin == 11 || pin == 10)
      return this->_links[pin]->compute(this->_pins[pin]);
    else {
    	this->updateState();
        return this->_out[this->_pinMap.find(pin)->second];
    }
    return nts::Tristate::Undefined;
}
