/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestGatesComponents
*/

#include "Components/ComponentsInclude.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

//----------------------------------------4001----------------------------------------

Test(C4001, testWrongPin)
{
    nts::C4001 c4001comp("test");

    cr_assert_eq(c4001comp.compute(0), nts::Tristate::Undefined);
}

Test(C4001, testWrongPin2)
{
    nts::C4001 c4001comp("test");

    cr_assert_eq(c4001comp.compute(7), nts::Tristate::Undefined);
}

Test(C4001, testWrongPin3)
{
    nts::C4001 c4001comp("test");

    cr_assert_eq(c4001comp.compute(14), nts::Tristate::Undefined);
}

Test(C4001, testWrongPin4)
{
    nts::C4001 c4001comp("test");

    cr_assert_eq(c4001comp.compute(99), nts::Tristate::Undefined);
}

//----------------------------------------4011----------------------------------------

Test(C4011, testWrongPin)
{
    nts::C4011 c4011comp("test");

    cr_assert_eq(c4011comp.compute(0), nts::Tristate::Undefined);
}

Test(C4011, testWrongPin2)
{
    nts::C4011 c4011comp("test");

    cr_assert_eq(c4011comp.compute(7), nts::Tristate::Undefined);
}

Test(C4011, testWrongPin3)
{
    nts::C4011 c4011comp("test");

    cr_assert_eq(c4011comp.compute(14), nts::Tristate::Undefined);
}

Test(C4011, testWrongPin4)
{
    nts::C4011 c4011comp("test");

    cr_assert_eq(c4011comp.compute(99), nts::Tristate::Undefined);
}

//----------------------------------------4030----------------------------------------

Test(C4030, testWrongPin)
{
    nts::C4030 c4030comp("test");

    cr_assert_eq(c4030comp.compute(0), nts::Tristate::Undefined);
}

Test(C4030, testWrongPin2)
{
    nts::C4030 c4030comp("test");

    cr_assert_eq(c4030comp.compute(7), nts::Tristate::Undefined);
}

Test(C4030, testWrongPin3)
{
    nts::C4030 c4030comp("test");

    cr_assert_eq(c4030comp.compute(14), nts::Tristate::Undefined);
}

Test(C4030, testWrongPin4)
{
    nts::C4030 c4030comp("test");

    cr_assert_eq(c4030comp.compute(99), nts::Tristate::Undefined);
}

//----------------------------------------4069----------------------------------------

Test(C4069, testWrongPin)
{
    nts::C4069 c4069comp("test");

    cr_assert_eq(c4069comp.compute(0), nts::Tristate::Undefined);
}

Test(C4069, testWrongPin2)
{
    nts::C4069 c4069comp("test");

    cr_assert_eq(c4069comp.compute(7), nts::Tristate::Undefined);
}

Test(C4069, testWrongPin3)
{
    nts::C4069 c4069comp("test");

    cr_assert_eq(c4069comp.compute(14), nts::Tristate::Undefined);
}

Test(C4069, testWrongPin4)
{
    nts::C4069 c4069comp("test");

    cr_assert_eq(c4069comp.compute(99), nts::Tristate::Undefined);
}

//----------------------------------------4071----------------------------------------

Test(C4071, testWrongPin)
{
    nts::C4071 c4071comp("test");

    cr_assert_eq(c4071comp.compute(0), nts::Tristate::Undefined);
}

Test(C4071, testWrongPin2)
{
    nts::C4071 c4071comp("test");

    cr_assert_eq(c4071comp.compute(7), nts::Tristate::Undefined);
}

Test(C4071, testWrongPin3)
{
    nts::C4071 c4071comp("test");

    cr_assert_eq(c4071comp.compute(14), nts::Tristate::Undefined);
}

Test(C4071, testWrongPin4)
{
    nts::C4071 c4071comp("test");

    cr_assert_eq(c4071comp.compute(99), nts::Tristate::Undefined);
}

//----------------------------------------4081----------------------------------------

Test(C4081, testWrongPin)
{
    nts::C4081 c4081comp("test");

    cr_assert_eq(c4081comp.compute(0), nts::Tristate::Undefined);
}

Test(C4081, testWrongPin2)
{
    nts::C4081 c4081comp("test");

    cr_assert_eq(c4081comp.compute(7), nts::Tristate::Undefined);
}

Test(C4081, testWrongPin3)
{
    nts::C4081 c4081comp("test");

    cr_assert_eq(c4081comp.compute(14), nts::Tristate::Undefined);
}

Test(C4081, testWrongPin4)
{
    nts::C4081 c4081comp("test");

    cr_assert_eq(c4081comp.compute(99), nts::Tristate::Undefined);
}
