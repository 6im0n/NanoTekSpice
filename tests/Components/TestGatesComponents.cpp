/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestGatesComponents
*/

#include "Components/ComponentsInclude.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(C4001, testWrongPin)
{
    nts::C4001 c4001comp("test");

    cr_assert_eq(c4001comp.compute(0), nts::Tristate::Undefined);
}

Test(C4011, testWrongPin)
{
    nts::C4011 c4011comp("test");

    cr_assert_eq(c4011comp.compute(0), nts::Tristate::Undefined);
}

Test(C4030, testWrongPin)
{
    nts::C4030 c4030comp("test");

    cr_assert_eq(c4030comp.compute(0), nts::Tristate::Undefined);
}

Test(C4069, testWrongPin)
{
    nts::C4069 c4069comp("test");

    cr_assert_eq(c4069comp.compute(0), nts::Tristate::Undefined);
}

Test(C4071, testWrongPin)
{
    nts::C4071 c4071comp("test");

    cr_assert_eq(c4071comp.compute(0), nts::Tristate::Undefined);
}

Test(C4081, testWrongPin)
{
    nts::C4081 c4081comp("test");

    cr_assert_eq(c4081comp.compute(0), nts::Tristate::Undefined);
}
