/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** 4512
*/

/*
 8 Channel Data Selector (4512)

          in_3 -4-+ +-5- in_4
        in_2 -3-+ | | +-6- in_5
      in_1 -2-+ | | | | +-7- in_6
    in_0 -1-+ | | | | | | +-9- in_7
            | | | | | | | |
          +-v-v-v-v-v-v-v-v-+
          |                 |
 in_a -11->                 <-10- inhibit
          |                 |
 in_b -12->                 |
          |                 |
 in_c -13->                 <-15- enable
          |                 |
          +-4512---v--------+
                   |
                   +-14- out_data
*/

#include "Components/Advanced/4512.hpp"

nts::C4512::C4512(std::string name) : AComponent(16, name)
{
}

nts::Tristate nts::C4512::getOutput(void)
{
    nts::Tristate inhibit = this->getLink(10);
    nts::Tristate enable = this->getLink(15);
    nts::Tristate in_a = this->getLink(11);
    nts::Tristate in_b = this->getLink(12);
    nts::Tristate in_c = this->getLink(13);

    if (enable == nts::Tristate::True || enable == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (inhibit == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (inhibit == nts::Tristate::True)
        return nts::Tristate::False;
    if (in_a == nts::Tristate::Undefined || in_b == nts::Tristate::Undefined || in_c == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    size_t index = (in_c == nts::Tristate::True) * 4 + (in_b == nts::Tristate::True) * 2 + (in_a == nts::Tristate::True);
    if (index == 7)
        return this->getLink(9);
    return this->getLink(index + 1);
}

nts::Tristate nts::C4512::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 0 || pin == 8 || pin == 16 || pin > 16)
        return nts::Tristate::Undefined;
    if (pin == 14)
        return getOutput();
    return this->_links[pin]->compute(this->_pins[pin]);
}
