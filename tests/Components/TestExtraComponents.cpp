/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestExtraComponents
*/

#include "Components/ComponentsInclude.hpp"
#include "Components/Extra/DFlipFlop.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(DFlipFlopComponent, testWrongPin)
{
    nts::DFlipFlop dflipflopcomp("test");

    cr_assert_eq(dflipflopcomp.compute(7), nts::Tristate::Undefined);
}

Test(DFlipFlopComponent, testCompute1)
{
    nts::IComponent *dflipflop = new nts::DFlipFlop("test");
    nts::IComponent *clock = new nts::TrueComponent("test");
    nts::IComponent *data = new nts::TrueComponent("test");
    nts::IComponent *reset = new nts::TrueComponent("test");
    nts::IComponent *set = new nts::TrueComponent("test");

    dflipflop->setLink(1, *clock, 1);
    dflipflop->setLink(2, *data, 1);
    dflipflop->setLink(3, *reset, 1);
    dflipflop->setLink(4, *set, 1);
    cr_assert_eq(dflipflop->compute(1), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(2), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(3), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(4), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(5), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(6), nts::Tristate::True);
}

Test(DFlipFlopComponent, testCompute2)
{
    nts::IComponent *dflipflop = new nts::DFlipFlop("test");
    nts::IComponent *clock = new nts::FalseComponent("test");
    nts::IComponent *data = new nts::TrueComponent("test");
    nts::IComponent *reset = new nts::FalseComponent("test");
    nts::IComponent *set = new nts::FalseComponent("test");

    dflipflop->setLink(1, *clock, 1);
    dflipflop->setLink(2, *data, 1);
    dflipflop->setLink(3, *reset, 1);
    dflipflop->setLink(4, *set, 1);
    cr_assert_eq(dflipflop->compute(1), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(2), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(3), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(4), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(5), nts::Tristate::Undefined);
    cr_assert_eq(dflipflop->compute(6), nts::Tristate::Undefined);
}

Test(DFlipFlopComponent, testCompute3)
{
    nts::IComponent *dflipflop = new nts::DFlipFlop("test");
    nts::IComponent *clock = new nts::TrueComponent("test");
    nts::IComponent *data = new nts::TrueComponent("test");
    nts::IComponent *reset = new nts::FalseComponent("test");
    nts::IComponent *set = new nts::FalseComponent("test");

    dflipflop->setLink(1, *clock, 1);
    dflipflop->setLink(2, *data, 1);
    dflipflop->setLink(3, *reset, 1);
    dflipflop->setLink(4, *set, 1);
    cr_assert_eq(dflipflop->compute(1), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(2), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(3), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(4), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(5), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(6), nts::Tristate::False);
}

Test(DFlipFlopComponent, testCompute4)
{
    nts::IComponent *dflipflop = new nts::DFlipFlop("test");
    nts::IComponent *clock = new nts::TrueComponent("test");
    nts::IComponent *data = new nts::FalseComponent("test");
    nts::IComponent *reset = new nts::FalseComponent("test");
    nts::IComponent *set = new nts::FalseComponent("test");

    dflipflop->setLink(1, *clock, 1);
    dflipflop->setLink(2, *data, 1);
    dflipflop->setLink(3, *reset, 1);
    dflipflop->setLink(4, *set, 1);
    cr_assert_eq(dflipflop->compute(1), nts::Tristate::True);
    cr_assert_eq(dflipflop->compute(2), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(3), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(4), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(5), nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(6), nts::Tristate::True);
}

Test(DFlipFlopComponent, testSetState)
{
    nts::IComponent *dflipflop = new nts::DFlipFlop("test");
    nts::IComponent *clock = new nts::TrueComponent("test");
    nts::IComponent *data = new nts::FalseComponent("test");
    nts::IComponent *reset = new nts::FalseComponent("test");
    nts::IComponent *set = new nts::FalseComponent("test");


    dflipflop->setLink(1, *clock, 1);
    dflipflop->setLink(2, *data, 1);
    dflipflop->setLink(3, *reset, 1);
    dflipflop->setLink(4, *set, 1);
    cr_assert_eq(dflipflop->compute(1), nts::Tristate::True);
    dflipflop->setState(nts::Tristate::False);
    cr_assert_eq(dflipflop->compute(1), nts::Tristate::True);
}

Test(DFlipFlopComponent, testGetLink)
{
    nts::IComponent *dflipflop = new nts::DFlipFlop("test");
    nts::IComponent *clock = new nts::TrueComponent("test");
    nts::IComponent *data = new nts::FalseComponent("test");
    nts::IComponent *reset = new nts::FalseComponent("test");
    nts::IComponent *set = new nts::FalseComponent("test");


    dflipflop->setLink(1, *clock, 1);
    dflipflop->setLink(2, *data, 1);
    dflipflop->setLink(3, *reset, 1);
    dflipflop->setLink(4, *set, 1);
    cr_assert_eq(dflipflop->getLink(0), nts::Tristate::Undefined);
}

Test(DuplicateComponent, testWrongPin)
{
    nts::DupComponent duplicatecomp("test");

    cr_assert_eq(duplicatecomp.compute(7), nts::Tristate::Undefined);
}

Test(DuplicateComponent, testCompute1)
{
    nts::IComponent *duplicate = new nts::DupComponent("test");
    nts::IComponent *input = new nts::TrueComponent("test");

    duplicate->setLink(1, *input, 1);
    cr_assert_eq(duplicate->compute(1), nts::Tristate::True);
    cr_assert_eq(duplicate->compute(2), nts::Tristate::True);
    cr_assert_eq(duplicate->compute(3), nts::Tristate::True);
}

Test(DuplicateComponent, testCompute2)
{
    nts::IComponent *duplicate = new nts::DupComponent("test");
    nts::IComponent *input = new nts::FalseComponent("test");

    duplicate->setLink(1, *input, 1);
    cr_assert_eq(duplicate->compute(1), nts::Tristate::False);
    cr_assert_eq(duplicate->compute(2), nts::Tristate::False);
    cr_assert_eq(duplicate->compute(3), nts::Tristate::False);
}

Test(FullAdderComponent, testWrongPin)
{
    nts::FullAdder fulladdercomp("test");

    cr_assert_eq(fulladdercomp.compute(7), nts::Tristate::Undefined);
}

Test(FullAdderComponent, testSetState)
{
    nts::FullAdder fulladdercomp("test");
    nts::IComponent *input1 = new nts::TrueComponent("test");
    nts::IComponent *input2 = new nts::TrueComponent("test");
    nts::IComponent *input3 = new nts::TrueComponent("test");

    fulladdercomp.setLink(1, *input1, 1);
    fulladdercomp.setLink(2, *input2, 1);
    fulladdercomp.setLink(3, *input3, 1);
    cr_assert_eq(fulladdercomp.compute(1), nts::Tristate::True);
    fulladdercomp.setState(nts::Tristate::False);
    cr_assert_eq(fulladdercomp.compute(1), nts::Tristate::True);
}

Test(FullAdderComponent, testGetLink)
{
    nts::FullAdder fulladdercomp("test");
    nts::IComponent *input1 = new nts::TrueComponent("test");
    nts::IComponent *input2 = new nts::TrueComponent("test");
    nts::IComponent *input3 = new nts::TrueComponent("test");

    fulladdercomp.setLink(1, *input1, 1);
    fulladdercomp.setLink(2, *input2, 1);
    fulladdercomp.setLink(3, *input3, 1);
    cr_assert_eq(fulladdercomp.getLink(0), nts::Tristate::Undefined);
    cr_assert_eq(fulladdercomp.getLink(1), nts::Tristate::True);
    cr_assert_eq(fulladdercomp.getLink(2), nts::Tristate::True);
    cr_assert_eq(fulladdercomp.getLink(3), nts::Tristate::True);
}

Test(FullAdderComponent, testErrorInSetLink)
{
    nts::FullAdder fulladdercomp("test");
    nts::IComponent *input1 = new nts::TrueComponent("test");
    nts::IComponent *input2 = new nts::TrueComponent("test");
    nts::IComponent *input3 = new nts::TrueComponent("test");

    fulladdercomp.setLink(1, *input1, 1);
    fulladdercomp.setLink(2, *input2, 1);
    fulladdercomp.setLink(3, *input3, 1);
    cr_assert_throw(fulladdercomp.setLink(0, *input3, 1), nts::Error);
}

Test(FullAdderComponent, testInfinityLoop)
{
    nts::FullAdder fulladdercomp("test");
    nts::IComponent *input1 = new nts::TrueComponent("test");
    nts::IComponent *input2 = new nts::TrueComponent("test");
    nts::IComponent *input3 = new nts::TrueComponent("test");

    fulladdercomp.setLink(1, *input1, 1);
    fulladdercomp.setLink(2, *input2, 1);
    fulladdercomp.setLink(3, *input3, 1);
    for (int i = 0; i < MAX_LOOP; i++)
        fulladdercomp.compute(1);
    cr_assert_throw(fulladdercomp.compute(1), nts::Error);
}

Test(LoggerComponent, testWrongPin)
{
    nts::Logger loggercomp("test");

    cr_assert_eq(loggercomp.compute(0), nts::Tristate::Undefined);
}

Test(LoggerComponent, testWrongPin2)
{
    nts::Logger loggercomp("test");

    cr_assert_eq(loggercomp.compute(99), nts::Tristate::Undefined);
}

Test(LoggerComponent, TestInputState)
{
    nts::IComponent *Logger = new nts::Logger("test");
    nts::IComponent *input = new nts::TrueComponent("test");

    Logger->setLink(1, *input, 1);

    input->setState(nts::Tristate::True);
    cr_assert_eq(Logger->compute(1), nts::Tristate::True);
}

Test(LoggerComponent, TestInhibit)
{
    nts::IComponent *Logger = new nts::Logger("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    Logger->setLink(10, *inhibit, 1);

    inhibit->setState(nts::Tristate::True);

    cr_assert_eq(Logger->compute(11), nts::Tristate::Undefined);
}

Test(LoggerComponent, TestInhibit2)
{
    nts::IComponent *Logger = new nts::Logger("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    Logger->setLink(10, *inhibit, 1);

    inhibit->setState(nts::Tristate::Undefined);

    cr_assert_eq(Logger->compute(11), nts::Tristate::Undefined);
}

Test(LoggerComponent, TestInputState2)
{
    nts::IComponent *Logger = new nts::Logger("test");
    nts::IComponent *input_1 = new nts::InputComponent("test");
    nts::IComponent *input_2 = new nts::InputComponent("test");
    nts::IComponent *input_4 = new nts::InputComponent("test");
    nts::IComponent *input_8 = new nts::InputComponent("test");
    nts::IComponent *input_16 = new nts::InputComponent("test");
    nts::IComponent *input_32 = new nts::InputComponent("test");
    nts::IComponent *input_64 = new nts::InputComponent("test");
    nts::IComponent *input_128 = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    std::ifstream file("./log.bin");
    char lastChar;

    Logger->setLink(1, *input_1, 1);
    Logger->setLink(2, *input_2, 1);
    Logger->setLink(3, *input_4, 1);
    Logger->setLink(4, *input_8, 1);
    Logger->setLink(5, *input_16, 1);
    Logger->setLink(6, *input_32, 1);
    Logger->setLink(7, *input_64, 1);
    Logger->setLink(8, *input_128, 1);
    Logger->setLink(9, *clock, 1);
    Logger->setLink(10, *inhibit, 1);

    input_1->setState(nts::Tristate::False);
    input_2->setState(nts::Tristate::True);
    input_4->setState(nts::Tristate::False);
    input_8->setState(nts::Tristate::False);
    input_16->setState(nts::Tristate::False);
    input_32->setState(nts::Tristate::False);
    input_64->setState(nts::Tristate::True);
    input_128->setState(nts::Tristate::False);
    clock->setState(nts::Tristate::False);
    Logger->compute(11);
    clock->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);
    Logger->compute(11);

    file.seekg(-1, std::ios_base::end);
    file.get(lastChar);
    cr_assert_eq(lastChar, 66);
    file.close();
}

Test(LoggerComponent, InputUndefined)
{
    nts::IComponent *Logger = new nts::Logger("test");
    nts::IComponent *input_7 = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    Logger->setLink(7, *input_7, 1);
    Logger->setLink(9, *clock, 1);
    Logger->setLink(10, *inhibit, 1);

    input_7->setState(nts::Tristate::False);
    clock->setState(nts::Tristate::False);
    Logger->compute(11);
    clock->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);
    Logger->compute(11);

    cr_assert_eq(Logger->compute(11), nts::Tristate::Undefined);
}