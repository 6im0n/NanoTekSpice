/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestSpecialComponents
*/

#include "Components/ComponentsInclude.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(TrueComponent, testWrongPin)
{
    nts::TrueComponent truecomp("test");

    cr_assert_eq(truecomp.compute(2), nts::Tristate::Undefined);
}

Test(OutputComponent, testWrongPin)
{
    nts::OutputComponent outputcomp("test");

    cr_assert_eq(outputcomp.compute(2), nts::Tristate::Undefined);
}

Test(InputComponent, testWrongPin)
{
    nts::InputComponent inputcomp("test");

    cr_assert_eq(inputcomp.compute(2), nts::Tristate::Undefined);
}

Test(InputComponent, testSetValue)
{
    nts::InputComponent inputcomp("test");

    cr_assert_eq(inputcomp.compute(1), nts::Tristate::Undefined);
    inputcomp.setState(nts::Tristate::True);
    cr_assert_eq(inputcomp.compute(1), nts::Tristate::True);
}

Test(FalseComponent, testWrongPin)
{
    nts::FalseComponent falsecomp("test");

    cr_assert_eq(falsecomp.compute(2), nts::Tristate::Undefined);
}

Test(ClockComponent, testWrongPin)
{
    nts::ClockComponent clockcomp("test");

    cr_assert_eq(clockcomp.compute(2), nts::Tristate::Undefined);
}

Test(ClockComponent, testSetState)
{
    nts::ClockComponent clockcomp("test");

    cr_assert_eq(clockcomp.compute(1), nts::Tristate::Undefined);
    clockcomp.setState(nts::Tristate::True);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::True);
}

Test(ClockComponent, testSimulate1)
{
    nts::ClockComponent clockcomp("test");

    cr_assert_eq(clockcomp.compute(1), nts::Tristate::Undefined);
    clockcomp.simulate(1);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::Undefined);
}

Test(ClockComponent, testSimulate2)
{
    nts::ClockComponent clockcomp("test");

    cr_assert_eq(clockcomp.compute(1), nts::Tristate::Undefined);
    clockcomp.setState(nts::Tristate::True);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::True);
    clockcomp.simulate(1);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::False);
}

Test(ClockComponent, testSimulate3)
{
    nts::ClockComponent clockcomp("test");

    cr_assert_eq(clockcomp.compute(1), nts::Tristate::Undefined);
    clockcomp.setState(nts::Tristate::True);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::True);
    clockcomp.simulate(1);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::False);
    clockcomp.simulate(2);
    cr_assert_eq(clockcomp.compute(1), nts::Tristate::False);
}