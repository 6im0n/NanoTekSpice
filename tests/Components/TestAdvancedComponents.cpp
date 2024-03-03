/*
** EPITECH PROJECT, 2024
** MicroTekSpice [SSH: 192.168.1.209]
** File description:
** TestAdvancedComponents
*/


#include "Components/ComponentsInclude.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(C4013, TestWrongPin)
{
    nts::C4017 c4013comp("test");

    cr_assert_eq(c4013comp.compute(99), nts::Tristate::Undefined);
}

Test(C4017, TestWrongPin)
{
    nts::C4017 c4017comp("test");

    cr_assert_eq(c4017comp.compute(0), nts::Tristate::Undefined);
}

Test(C4017, TestCompute1)
{
    nts::IComponent *c4017 = new nts::C4017("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4017->setLink(14, *clock, 1);
    c4017->setLink(15, *reset, 1);
    c4017->setLink(13, *enable, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4017->compute(3), nts::Tristate::True);
}

Test(C4017, TestReset)
{
    nts::IComponent *c4017 = new nts::C4017("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4017->setLink(14, *clock, 1);
    c4017->setLink(15, *reset, 1);
    c4017->setLink(13, *enable, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::True);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4017->compute(3), nts::Tristate::True);
}

Test(C4017, TestValueIncrement)
{
    nts::IComponent *c4017 = new nts::C4017("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4017->setLink(14, *clock, 1);
    c4017->setLink(15, *reset, 1);
    c4017->setLink(13, *enable, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);
    c4017->compute(3);
    clock->setState(nts::Tristate::True);
    c4017->compute(3);

    cr_assert_eq(c4017->compute(2), nts::Tristate::True);
}

Test(C4017, TestInputPinReturnValue)
{
    nts::IComponent *c4017 = new nts::C4017("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4017->setLink(14, *clock, 1);
    c4017->setLink(15, *reset, 1);
    c4017->setLink(13, *enable, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4017->compute(14), nts::Tristate::False);
}

Test(C4040, TestWrongPin)
{
    nts::C4017 c4013comp("test");

    cr_assert_eq(c4013comp.compute(0), nts::Tristate::Undefined);
}

Test(C4040, TestCompute1)
{
    nts::IComponent *c4040 = new nts::C4040("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");

    c4040->setLink(10, *clock, 1);
    c4040->setLink(11, *reset, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::False);

    cr_assert_eq(c4040->compute(9), nts::Tristate::False);
}

Test(C4040, TestReset)
{
    nts::IComponent *c4040 = new nts::C4040("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");

    c4040->setLink(10, *clock, 1);
    c4040->setLink(11, *reset, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::True);

    cr_assert_eq(c4040->compute(9), nts::Tristate::False);
}

Test(C4040, TestIncrementValue)
{
    nts::IComponent *c4040 = new nts::C4040("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");

    c4040->setLink(10, *clock, 1);
    c4040->setLink(11, *reset, 1);

    clock->setState(nts::Tristate::True);
    reset->setState(nts::Tristate::False);
    c4040->compute(9);
    clock->setState(nts::Tristate::False);
    c4040->compute(9);

    cr_assert_eq(c4040->compute(9), nts::Tristate::True);
}

Test(C4040, TestIncrementValueMax)
{
    nts::IComponent *c4040 = new nts::C4040("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");

    c4040->setLink(10, *clock, 1);
    c4040->setLink(11, *reset, 1);

    reset->setState(nts::Tristate::False);

    for (int i = 0; i < 4096; i++) {
        clock->setState(nts::Tristate::True);
        c4040->compute(9);
        clock->setState(nts::Tristate::False);
        c4040->compute(9);
    }

    cr_assert_eq(c4040->compute(9), nts::Tristate::False);
}

Test(C4040, TestInputPinReturnValue)
{
    nts::IComponent *c4040 = new nts::C4040("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *reset = new nts::InputComponent("test");

    c4040->setLink(10, *clock, 1);
    c4040->setLink(11, *reset, 1);

    clock->setState(nts::Tristate::False);
    reset->setState(nts::Tristate::False);

    cr_assert_eq(c4040->compute(10), nts::Tristate::Undefined);
}