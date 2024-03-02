/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestElementaryComponents
*/

#include "Components/ComponentsInclude.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(AndComponent, testWrongPin)
{
    nts::AndComponent andcomp("test");

    cr_assert_eq(andcomp.compute(7), nts::Tristate::Undefined);
}

Test(AndComponent, testCompute1)
{
    nts::IComponent *andcomp = new nts::AndComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");
    nts::IComponent *falsecomp = new nts::FalseComponent("test");

    andcomp->setLink(1, *truecomp, 1);
    andcomp->setLink(2, *falsecomp, 1);
    cr_assert_eq(andcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(andcomp->compute(2), nts::Tristate::False);
    cr_assert_eq(andcomp->compute(3), nts::Tristate::False);
}

Test(AndComponent, testCompute2)
{
    nts::IComponent *andcomp = new nts::AndComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");

    andcomp->setLink(1, *truecomp, 1);
    andcomp->setLink(2, *truecomp, 1);
    cr_assert_eq(andcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(andcomp->compute(2), nts::Tristate::True);
    cr_assert_eq(andcomp->compute(3), nts::Tristate::True);
}

Test(NandComponent, testWrongPin)
{
    nts::NandComponent nandcomp("test");

    cr_assert_eq(nandcomp.compute(7), nts::Tristate::Undefined);
}

Test(NandComponent, testCompute1)
{
    nts::IComponent *nandcomp = new nts::NandComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");
    nts::IComponent *falsecomp = new nts::FalseComponent("test");

    nandcomp->setLink(1, *truecomp, 1);
    nandcomp->setLink(2, *falsecomp, 1);
    cr_assert_eq(nandcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(nandcomp->compute(2), nts::Tristate::False);
    cr_assert_eq(nandcomp->compute(3), nts::Tristate::True);
}

Test(NandComponent, testCompute2)
{
    nts::IComponent *nandcomp = new nts::NandComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");

    nandcomp->setLink(1, *truecomp, 1);
    nandcomp->setLink(2, *truecomp, 1);
    cr_assert_eq(nandcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(nandcomp->compute(2), nts::Tristate::True);
    cr_assert_eq(nandcomp->compute(3), nts::Tristate::False);
}

Test(OrComponent, testWrongPin)
{
    nts::OrComponent orcomp("test");

    cr_assert_eq(orcomp.compute(7), nts::Tristate::Undefined);
}

Test(OrComponent, testCompute1)
{
    nts::IComponent *orcomp = new nts::OrComponent("test");
    nts::IComponent *falsecomp = new nts::FalseComponent("test");

    orcomp->setLink(1, *falsecomp, 1);
    orcomp->setLink(2, *falsecomp, 1);
    cr_assert_eq(orcomp->compute(1), nts::Tristate::False);
    cr_assert_eq(orcomp->compute(2), nts::Tristate::False);
    cr_assert_eq(orcomp->compute(3), nts::Tristate::False);
}

Test(OrComponent, testCompute2)
{
    nts::IComponent *orcomp = new nts::OrComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");

    orcomp->setLink(1, *truecomp, 1);
    orcomp->setLink(2, *truecomp, 1);
    cr_assert_eq(orcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(orcomp->compute(2), nts::Tristate::True);
    cr_assert_eq(orcomp->compute(3), nts::Tristate::True);
}

Test(NorComponent, testWrongPin)
{
    nts::NorComponent norcomp("test");

    cr_assert_eq(norcomp.compute(7), nts::Tristate::Undefined);
}

Test(NorComponent, testCompute1)
{
    nts::IComponent *norcomp = new nts::NorComponent("test");
    nts::IComponent *falsecomp = new nts::FalseComponent("test");

    norcomp->setLink(1, *falsecomp, 1);
    norcomp->setLink(2, *falsecomp, 1);
    cr_assert_eq(norcomp->compute(1), nts::Tristate::False);
    cr_assert_eq(norcomp->compute(2), nts::Tristate::False);
    cr_assert_eq(norcomp->compute(3), nts::Tristate::True);
}

Test(NorComponent, testCompute2)
{
    nts::IComponent *norcomp = new nts::NorComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");

    norcomp->setLink(1, *truecomp, 1);
    norcomp->setLink(2, *truecomp, 1);
    cr_assert_eq(norcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(norcomp->compute(2), nts::Tristate::True);
    cr_assert_eq(norcomp->compute(3), nts::Tristate::False);
}

Test(XorComponent, testWrongPin)
{
    nts::XorComponent xorcomp("test");

    cr_assert_eq(xorcomp.compute(7), nts::Tristate::Undefined);
}

Test(XorComponent, testCompute1)
{
    nts::IComponent *xorcomp = new nts::XorComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");
    nts::IComponent *falsecomp = new nts::FalseComponent("test");

    xorcomp->setLink(1, *truecomp, 1);
    xorcomp->setLink(2, *falsecomp, 1);
    cr_assert_eq(xorcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(xorcomp->compute(2), nts::Tristate::False);
    cr_assert_eq(xorcomp->compute(3), nts::Tristate::True);
}

Test(XorComponent, testCompute2)
{
    nts::IComponent *xorcomp = new nts::XorComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");

    xorcomp->setLink(1, *truecomp, 1);
    xorcomp->setLink(2, *truecomp, 1);
    cr_assert_eq(xorcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(xorcomp->compute(2), nts::Tristate::True);
    cr_assert_eq(xorcomp->compute(3), nts::Tristate::False);
}

Test(NotComponent, testWrongPin)
{
    nts::NotComponent notcomp("test");

    cr_assert_eq(notcomp.compute(3), nts::Tristate::Undefined);
}

Test(NotComponent, testCompute1)
{
    nts::IComponent *notcomp = new nts::NotComponent("test");
    nts::IComponent *truecomp = new nts::TrueComponent("test");

    notcomp->setLink(1, *truecomp, 1);
    cr_assert_eq(notcomp->compute(1), nts::Tristate::True);
    cr_assert_eq(notcomp->compute(2), nts::Tristate::False);
}

Test(NotComponent, testCompute2)
{
    nts::IComponent *notcomp = new nts::NotComponent("test");
    nts::IComponent *falsecomp = new nts::FalseComponent("test");

    notcomp->setLink(1, *falsecomp, 1);
    cr_assert_eq(notcomp->compute(1), nts::Tristate::False);
    cr_assert_eq(notcomp->compute(2), nts::Tristate::True);
}
