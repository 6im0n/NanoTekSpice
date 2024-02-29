/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4094
*/

/*
 8-bits Shift Register (4094)

                   out_3 -7-+   +-14- out_4
               out_2 -6-+   |   |   +-13- out_5
           out_1 -5-+   |   |   |   |   +-12- out_6
       out_0 -4-+   |   |   |   |   |   |   +-11- out_7
                |   |   |   |   |   |   |   |
            +---^---^---^---^---^---^---^---^---+
            |   |   |   |   |   |   |   |   |   |
 enable -15->--[/]-[/]-[/]-[/]-[/]-[/]-[/]-[/]  |
            |   |   |   |   |   |   |   |   |   |
            |  +-----------------------------+  |
            |  |         saved value         |  |
            |  +-----------------------------+  |
            |   |   |   |   |   |   |   |   |   |
  strobe -1->--[/]-[/]-[/]-[/]-[/]-[/]-[/]-[/]  |
            |   |   |   |   |   |   |   |   |   |
            |  +-----------------------------+  |
    data -2->-->    8 bits shift register    >-->-9- out_qs
            |  +-^-------------------------v-+  |
            |    |                         |    |
   clock -3->----+                         +---->-10- out_qe
            |                                   |
            +-4094------------------------------+
*/

#include "Components/Advanced/4094.hpp"

nts::C4094::C4094(std::string name) : AComponent(16, name)
{
    this->_lastStates = std::vector<nts::Tristate>(8, nts::Tristate::Undefined);
    this->_stateQs = nts::Tristate::Undefined;
    this->_stateQe = nts::Tristate::Undefined;
}

void nts::C4094::updateAllStates(nts::Tristate value)
{
    for (size_t i = 0; i < 8; i++)
        this->_lastStates[i] = value;
    this->_stateQs = value;
    this->_stateQe = value;
}

void nts::C4094::updateParallelOutput(nts::Tristate value)
{
    for (size_t i = 0; i < 8; i++)
        this->_lastStates[i] = value;
}

void nts::C4094::bitShiftParallelOutput(nts::Tristate value)
{
    for (size_t i = 7; i > 0; i--)
        this->_lastStates[i] = this->_lastStates[i - 1];
    this->_lastStates[0] = value;
}

void nts::C4094::updateState(void)
{
    nts::Tristate strobe = this->getLink(1);
    nts::Tristate data = this->getLink(2);
    nts::Tristate clock = this->getLink(3);
    nts::Tristate enable = this->getLink(15);

    if (enable == nts::Tristate::Undefined || clock == nts::Tristate::Undefined)
        return this->updateAllStates(nts::Tristate::Undefined);
    if (enable == nts::Tristate::False) {
        this->updateParallelOutput(nts::Tristate::True);
        this->_stateQs = clock == nts::Tristate::True ? this->_lastStates[6] : this->_stateQs;
        this->_stateQe = clock == nts::Tristate::True ? this->_stateQe : this->_lastStates[6];
        return;
    }
    if (clock == nts::Tristate::False) {
        this->_stateQe = this->_lastStates[6];
        return;
    }
    if (strobe == nts::Tristate::Undefined)
        return this->updateAllStates(nts::Tristate::Undefined);
    this->_stateQs = this->_lastStates[6];
    if (strobe == nts::Tristate::False) {
        return;
    }
    if (data == nts::Tristate::Undefined)
        return this->updateAllStates(nts::Tristate::Undefined);
    this->bitShiftParallelOutput(data);
}

nts::Tristate nts::C4094::compute(std::size_t pin)
{
    if (this->loop == 0)
        this->updateState();
    this->checkIfNotLoop();
    if (pin == 0 || pin == 8 || pin == 16 || pin > 16)
        return nts::Tristate::Undefined;
    if ((pin >= 1 && pin <= 3) || pin == 15)
        return this->_links[pin]->compute(this->_pins[pin]);
    if (pin == 9)
        return this->_stateQs;
    if (pin == 10)
        return this->_stateQe;
    if (pin >= 11 && pin <= 14)
        return this->_lastStates[8 - (pin - 10)];
    else
        return this->_lastStates[pin - 4];
}
