Test(C4011, testWrongPin2)
{
    nts::C4011 c4011comp("test");

    cr_assert_eq(c4011comp.compute(7), nts::Tristate::Undefined);
    cr_assert_eq(c4011comp.compute(14), nts::Tristate::Undefined);
    cr_assert_eq(c4011comp.compute(99), nts::Tristate::Undefined);
}