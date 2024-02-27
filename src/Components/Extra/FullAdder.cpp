/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** FullAdder
*/

#include "Components/Extra/FullAdder.hpp"
#include "Components/Elementary/Xor.hpp"
#include "Components/Elementary/And.hpp"
#include "Components/Elementary/Or.hpp"
#include "Components/Extra/Duplicate.hpp"

nts::FullAdder::FullAdder(std::string name) : AChipset(5, name)
{
    XorComponent *Xor1 = new XorComponent;
    XorComponent *Xor2 = new XorComponent;
    AndComponent *And1 = new AndComponent;
    AndComponent *And2 = new AndComponent;
    OrComponent *Or1 = new OrComponent;
    DupComponent *Dup1 = new DupComponent;
    DupComponent *Dup2 = new DupComponent;
    DupComponent *Dup3 = new DupComponent;

    Xor1->setLink(1, *Dup1, 2);
    Xor1->setLink(2, *Dup2, 2);
    And1->setLink(1, *Dup1, 3);
    And1->setLink(2, *Dup2, 3);
    Xor2->setLink(1, *Xor1, 3);
    Xor2->setLink(2, *Dup3, 2);
    And2->setLink(1, *Xor1, 3);
    And2->setLink(2, *Dup3, 3);
    Or1->setLink(1, *And2, 3);
    Or1->setLink(2, *And1, 3);

    this->_intLinks = {
        nullptr,
        Dup1, Dup2, Dup3,
        Xor2, Or1
    };

    this->_intPins = {0, 1, 1, 1, 3, 3};
}

nts::Tristate nts::FullAdder::compute(std::size_t pin)
{
    this->checkIfNotLoop();
    if (pin == 0 || pin > this->_intPins.size())
        return nts::Tristate::Undefined;
    return this->_intLinks[pin]->compute(_intPins[pin]);
}
