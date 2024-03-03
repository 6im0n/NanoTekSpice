/*
** EPITECH PROJECT, 2024
** MicroTekSpice [SSH: 192.168.1.209]
** File description:
** TestAdvancedComponents
*/


#include "Components/ComponentsInclude.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

// --------------------------------- 4008 ---------------------------------
Test(C4008, TestWrongPin)
{
    nts::C4008 c4008comp("test");

    cr_assert_eq(c4008comp.compute(0), nts::Tristate::Undefined);
}

Test(C4008, TestWrongPin2)
{
    nts::C4008 c4008comp("test");

    cr_assert_eq(c4008comp.compute(8), nts::Tristate::Undefined);
}

Test(C4008, TestWrongPin3)
{
    nts::C4008 c4008comp("test");

    cr_assert_eq(c4008comp.compute(16), nts::Tristate::Undefined);
}

Test(C4008, TestWrongPi4)
{
    nts::C4008 c4008comp("test");

    cr_assert_eq(c4008comp.compute(99), nts::Tristate::Undefined);
}

// --------------------------------- 4013 ---------------------------------
Test(C4013, TestWrongPin)
{
    nts::C4013 c4013comp("test");

    cr_assert_eq(c4013comp.compute(99), nts::Tristate::Undefined);
}

Test(C4013, TestWrongPin2)
{
    nts::C4013 c4013comp("test");

    cr_assert_eq(c4013comp.compute(0), nts::Tristate::Undefined);
}

Test(C4013, TestWrongPin3)
{
    nts::C4013 c4013comp("test");

    cr_assert_eq(c4013comp.compute(7), nts::Tristate::Undefined);
}

Test(C4013, TestWrongPin4)
{
    nts::C4013 c4013comp("test");

    cr_assert_eq(c4013comp.compute(14), nts::Tristate::Undefined);
}

//--------------------------------- 4017 ---------------------------------
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

//--------------------------------- 4040 ---------------------------------

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

    cr_assert_eq(c4040->compute(10), nts::Tristate::False);
}

//--------------------------------- 4094 ---------------------------------

Test(C4094 , TestWrongPin)
{
    nts::C4094 c4094comp("test");

    cr_assert_eq(c4094comp.compute(0), nts::Tristate::Undefined);
}

Test(C4094, TestCompute1)
{
    nts::IComponent *c4094 = new nts::C4094("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *data = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4094->setLink(1, *strobe, 1);
    c4094->setLink(2, *data, 1);
    c4094->setLink(3, *clock, 1);
    c4094->setLink(15, *enable, 1);

    data->setState(nts::Tristate::True);
    clock->setState(nts::Tristate::False);
    strobe->setState(nts::Tristate::True);
    enable->setState(nts::Tristate::True);

    cr_assert_eq(c4094->compute(4), nts::Tristate::Undefined);
}

Test(C4094, TestIncrementValue)
{
    nts::IComponent *c4094 = new nts::C4094("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *data = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4094->setLink(1, *strobe, 1);
    c4094->setLink(2, *data, 1);
    c4094->setLink(3, *clock, 1);
    c4094->setLink(15, *enable, 1);

    data->setState(nts::Tristate::True);
    clock->setState(nts::Tristate::False);
    strobe->setState(nts::Tristate::True);
    enable->setState(nts::Tristate::False);
    c4094->compute(4);
    clock->setState(nts::Tristate::True);
    c4094->compute(4);

    cr_assert_eq(c4094->compute(4), nts::Tristate::True);
}

Test(C4094, TestShiftValue)
{
    nts::IComponent *c4094 = new nts::C4094("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *data = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4094->setLink(1, *strobe, 1);
    c4094->setLink(2, *data, 1);
    c4094->setLink(3, *clock, 1);
    c4094->setLink(15, *enable, 1);

    data->setState(nts::Tristate::True);
    clock->setState(nts::Tristate::False);
    strobe->setState(nts::Tristate::True);
    enable->setState(nts::Tristate::False);
    c4094->compute(4);
    clock->setState(nts::Tristate::True);
    c4094->compute(4);
    data->setState(nts::Tristate::False);
    clock->setState(nts::Tristate::False);
    c4094->compute(4);
    clock->setState(nts::Tristate::True);

    cr_assert_eq(c4094->compute(5), nts::Tristate::True);
}

Test(C4094, DataUndefined)
{
    nts::IComponent *c4094 = new nts::C4094("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *data = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4094->setLink(1, *strobe, 1);
    c4094->setLink(2, *data, 1);
    c4094->setLink(3, *clock, 1);
    c4094->setLink(15, *enable, 1);

    data->setState(nts::Tristate::True);
    clock->setState(nts::Tristate::False);
    strobe->setState(nts::Tristate::True);
    enable->setState(nts::Tristate::False);
    c4094->compute(4);
    clock->setState(nts::Tristate::True);
    c4094->compute(4);
    data->setState(nts::Tristate::Undefined);
    clock->setState(nts::Tristate::False);
    c4094->compute(4);
    clock->setState(nts::Tristate::True);
    c4094->compute(4);

    cr_assert_eq(c4094->compute(5), nts::Tristate::True);
}

Test(C4094, TestInputPinReturnValue)
{
    nts::IComponent *c4094 = new nts::C4094("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *data = new nts::InputComponent("test");
    nts::IComponent *clock = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4094->setLink(1, *strobe, 1);
    c4094->setLink(2, *data, 1);
    c4094->setLink(3, *clock, 1);
    c4094->setLink(15, *enable, 1);

    strobe->setState(nts::Tristate::False);
    data->setState(nts::Tristate::False);
    clock->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4094->compute(1), nts::Tristate::False);
}
//--------------------------------- 4514 ---------------------------------

Test(C4514, TestWrongPin)
{
    nts::C4514 c4514comp("test");

    cr_assert_eq(c4514comp.compute(0), nts::Tristate::Undefined);
}

Test(C4514, TestCompute1)
{
    nts::IComponent *c4514 = new nts::C4514("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *dataA = new nts::InputComponent("test");
    nts::IComponent *dataB = new nts::InputComponent("test");
    nts::IComponent *dataC = new nts::InputComponent("test");
    nts::IComponent *dataD = new nts::InputComponent("test");

    c4514->setLink(1, *strobe, 1);
    c4514->setLink(2, *dataA, 1);
    c4514->setLink(3, *dataB, 1);
    c4514->setLink(21, *dataC, 1);
    c4514->setLink(22, *dataD, 1);
    c4514->setLink(23, *inhibit, 1);

    dataA->setState(nts::Tristate::False);
    dataB->setState(nts::Tristate::False);
    dataC->setState(nts::Tristate::False);
    dataD->setState(nts::Tristate::False);
    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);

    cr_assert_eq(c4514->compute(11), nts::Tristate::True);
}

Test(C4514, TestDataUndefined)
{
    nts::IComponent *c4514 = new nts::C4514("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *dataA = new nts::InputComponent("test");
    nts::IComponent *dataB = new nts::InputComponent("test");
    nts::IComponent *dataC = new nts::InputComponent("test");
    nts::IComponent *dataD = new nts::InputComponent("test");

    c4514->setLink(1, *strobe, 1);
    c4514->setLink(2, *dataA, 1);
    c4514->setLink(3, *dataB, 1);
    c4514->setLink(21, *dataC, 1);
    c4514->setLink(22, *dataD, 1);
    c4514->setLink(23, *inhibit, 1);

    dataA->setState(nts::Tristate::Undefined);
    dataB->setState(nts::Tristate::Undefined);
    dataC->setState(nts::Tristate::Undefined);
    dataD->setState(nts::Tristate::Undefined);
    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);

    cr_assert_eq(c4514->compute(11), nts::Tristate::Undefined);
}

Test(C4514, TestInputPin)
{
    nts::IComponent *c4514 = new nts::C4514("test");
    nts::IComponent *dataA = new nts::InputComponent("test");

    c4514->setLink(2, *dataA, 1);

    dataA->setState(nts::Tristate::True);

    cr_assert_eq(c4514->compute(2), nts::Tristate::True);
}

Test(C4514, TestInhibit)
{
    nts::IComponent *c4514 = new nts::C4514("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    c4514->setLink(1, *strobe, 1);
    c4514->setLink(23, *inhibit, 1);


    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::True);

    cr_assert_eq(c4514->compute(11), nts::Tristate::False);
}

Test(C4514, TestInhibit2)
{
    nts::IComponent *c4514 = new nts::C4514("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    c4514->setLink(1, *strobe, 1);
    c4514->setLink(23, *inhibit, 1);


    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::Undefined);

    cr_assert_eq(c4514->compute(11), nts::Tristate::False);
}

//--------------------------------- 4512 ---------------------------------

Test(C4512, TestWrongPin)
{
    nts::C4512 c4512comp("test");

    cr_assert_eq(c4512comp.compute(0), nts::Tristate::Undefined);
}

Test(C4512, TestCompute1)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *in_a = new nts::InputComponent("test");
    nts::IComponent *in_b = new nts::InputComponent("test");
    nts::IComponent *in_c = new nts::InputComponent("test");
    nts::IComponent *in_0 = new nts::InputComponent("test");
    nts::IComponent *in_1 = new nts::InputComponent("test");
    nts::IComponent *in_2 = new nts::InputComponent("test");
    nts::IComponent *in_3 = new nts::InputComponent("test");
    nts::IComponent *in_4 = new nts::InputComponent("test");
    nts::IComponent *in_5 = new nts::InputComponent("test");
    nts::IComponent *in_6 = new nts::InputComponent("test");
    nts::IComponent *in_7 = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4512->setLink(11, *in_a, 1);
    c4512->setLink(12, *in_b, 1);
    c4512->setLink(13, *in_c, 1);
    c4512->setLink(1, *in_0, 1);
    c4512->setLink(2, *in_1, 1);
    c4512->setLink(3, *in_2, 1);
    c4512->setLink(4, *in_3, 1);
    c4512->setLink(5, *in_4, 1);
    c4512->setLink(6, *in_5, 1);
    c4512->setLink(7, *in_6, 1);
    c4512->setLink(9, *in_7, 1);
    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);

    in_a->setState(nts::Tristate::True);
    in_b->setState(nts::Tristate::False);
    in_c->setState(nts::Tristate::False);
    in_0->setState(nts::Tristate::False);
    in_1->setState(nts::Tristate::True);
    in_2->setState(nts::Tristate::False);
    in_3->setState(nts::Tristate::False);
    in_4->setState(nts::Tristate::False);
    in_5->setState(nts::Tristate::False);
    in_6->setState(nts::Tristate::False);
    in_7->setState(nts::Tristate::False);
    inhibit->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4512->compute(14), nts::Tristate::True);
}

Test(C4512, TestInhibit)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);

    inhibit->setState(nts::Tristate::Undefined);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4512->compute(14), nts::Tristate::Undefined);
}

Test(C4512, TestInhibit2)
{
    nts::IComponent *c4512 = new nts::C4512("test");

    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);

    inhibit->setState(nts::Tristate::True);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4512->compute(14), nts::Tristate::False);
}

Test(C4512, TestEnable)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);

    inhibit->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::True);

    cr_assert_eq(c4512->compute(14), nts::Tristate::Undefined);
}

Test(C4512, TestEnable2)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);

    inhibit->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::Undefined);

    cr_assert_eq(c4512->compute(14), nts::Tristate::Undefined);
}

Test(C4512, TestInputUndefined)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *in_a = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");


    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);
    c4512->setLink(1, *in_a, 1);

    inhibit->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);
    in_a->setState(nts::Tristate::Undefined);

    cr_assert_eq(c4512->compute(14), nts::Tristate::Undefined);
}

Test(C4512, TestEdgeCaseIndex7)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *in_a = new nts::InputComponent("test");
    nts::IComponent *in_b = new nts::InputComponent("test");
    nts::IComponent *in_c = new nts::InputComponent("test");
    nts::IComponent *in_7 = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *enable = new nts::InputComponent("test");

    c4512->setLink(11, *in_a, 1);
    c4512->setLink(12, *in_b, 1);
    c4512->setLink(13, *in_c, 1);
    c4512->setLink(9, *in_7, 1);
    c4512->setLink(10, *inhibit, 1);
    c4512->setLink(15, *enable, 1);

    in_a->setState(nts::Tristate::True);
    in_b->setState(nts::Tristate::True);
    in_c->setState(nts::Tristate::True);
    in_7->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);
    enable->setState(nts::Tristate::False);

    cr_assert_eq(c4512->compute(14), nts::Tristate::True);
}

Test(C4512, TestInput)
{
    nts::IComponent *c4512 = new nts::C4512("test");
    nts::IComponent *in_a = new nts::InputComponent("test");

    c4512->setLink(11, *in_a, 1);

    in_a->setState(nts::Tristate::True);

    cr_assert_eq(c4512->compute(11), nts::Tristate::True);
}
//--------------------------------- 4515 ---------------------------------

Test(C4515, TestWrongPin)
{
    nts::C4515 C4515comp("test");

    cr_assert_eq(C4515comp.compute(0), nts::Tristate::Undefined);
}

Test(C4515, TestCompute1)
{
    nts::IComponent *C4515 = new nts::C4515("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *dataA = new nts::InputComponent("test");
    nts::IComponent *dataB = new nts::InputComponent("test");
    nts::IComponent *dataC = new nts::InputComponent("test");
    nts::IComponent *dataD = new nts::InputComponent("test");

    C4515->setLink(1, *strobe, 1);
    C4515->setLink(2, *dataA, 1);
    C4515->setLink(3, *dataB, 1);
    C4515->setLink(21, *dataC, 1);
    C4515->setLink(22, *dataD, 1);
    C4515->setLink(23, *inhibit, 1);

    dataA->setState(nts::Tristate::False);
    dataB->setState(nts::Tristate::False);
    dataC->setState(nts::Tristate::False);
    dataD->setState(nts::Tristate::False);
    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);

    cr_assert_eq(C4515->compute(11), nts::Tristate::False);
}

Test(C4515, TestDataUndefined)
{
    nts::IComponent *C4515 = new nts::C4515("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");
    nts::IComponent *dataA = new nts::InputComponent("test");
    nts::IComponent *dataB = new nts::InputComponent("test");
    nts::IComponent *dataC = new nts::InputComponent("test");
    nts::IComponent *dataD = new nts::InputComponent("test");

    C4515->setLink(1, *strobe, 1);
    C4515->setLink(2, *dataA, 1);
    C4515->setLink(3, *dataB, 1);
    C4515->setLink(21, *dataC, 1);
    C4515->setLink(22, *dataD, 1);
    C4515->setLink(23, *inhibit, 1);

    dataA->setState(nts::Tristate::Undefined);
    dataB->setState(nts::Tristate::Undefined);
    dataC->setState(nts::Tristate::Undefined);
    dataD->setState(nts::Tristate::Undefined);
    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::False);

    cr_assert_eq(C4515->compute(11), nts::Tristate::Undefined);
}

Test(C4515, TestInputPin)
{
    nts::IComponent *C4515 = new nts::C4515("test");
    nts::IComponent *dataA = new nts::InputComponent("test");

    C4515->setLink(2, *dataA, 1);

    dataA->setState(nts::Tristate::True);

    cr_assert_eq(C4515->compute(2), nts::Tristate::True);
}

Test(C4515, TestInhibit)
{
    nts::IComponent *C4515 = new nts::C4515("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    C4515->setLink(1, *strobe, 1);
    C4515->setLink(23, *inhibit, 1);


    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::True);

    cr_assert_eq(C4515->compute(11), nts::Tristate::True);
}

Test(C4515, TestInhibit2)
{
    nts::IComponent *C4515 = new nts::C4515("test");
    nts::IComponent *strobe = new nts::InputComponent("test");
    nts::IComponent *inhibit = new nts::InputComponent("test");

    C4515->setLink(1, *strobe, 1);
    C4515->setLink(23, *inhibit, 1);


    strobe->setState(nts::Tristate::True);
    inhibit->setState(nts::Tristate::Undefined);

    cr_assert_eq(C4515->compute(11), nts::Tristate::True);
}
