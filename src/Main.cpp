/*
** EPITECH PROJECT, 2024
** BootStrap NTS
** File description:
** main
*/

#include <iostream>
#include "include.hpp"
#include <memory>


std::ostream & operator<<(std::ostream & s, nts::Tristate v)
{
    if (v == nts::Tristate::True)
        s << "1";
    else if (v == nts::Tristate::False)
        s << "0";
    else
        s << "0";
    return s;
}
int main(void)
{
    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::AndComponent>();
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::InputComponent>();
    // std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::FalseComponent>();
    //std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> inverter = std::make_unique<nts::NotComponent>();

    gate->setLink(1, *input1, 1); // link input1 to gate pin 1
    input1->setLink(1, *gate, 1); // link input2 to gate pin 1

    gate->setLink(2, *input2, 1); // link input2 to gate pin 2
    input2->setLink(1, *gate, 2); // link input2 to gate pin 2

    inverter->setLink(1, *gate, 3);

    gate->setLink(3, *inverter, 1);

    input1->setState(nts::Tristate::True); // set input1 to true
    input2->setState(nts::Tristate::True); // set input2 to false
    std::cout << "!(" << input1->compute(1);
    std::cout << " && " << input2->compute(1) << ") -> " << inverter->compute(2) << std::endl;
}