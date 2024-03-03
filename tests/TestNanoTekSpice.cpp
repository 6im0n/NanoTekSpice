/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestNanoTekSpice
*/

#include "NanoTekSpice.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>

Test(NanoTekSpice, testUnknowComponent)
{
    nts::CircuitFile file("TestFile/NtsFailing/UnknowComponent.nts");

    cr_assert_throw(nts::NanoTekSpice nano(file), nts::Error);
}

Test(NanoTekSpice, testUnknowLink)
{
    nts::CircuitFile file("TestFile/NtsFailing/UnknowLink.nts");

    cr_assert_throw(nts::NanoTekSpice nano(file), nts::Error);
}

Test(NanoTekSpice, testMissingOutput)
{
    nts::CircuitFile file("TestFile/NtsFailing/MissingOutput.nts");

    cr_assert_throw(nts::NanoTekSpice nano(file), nts::Error);
}

Test(NanoTekSpice, testInfinityLoop)
{
    nts::CircuitFile file("TestFile/NtsFailing/InfinityLoop.nts");

    cr_assert_throw(nts::NanoTekSpice nano(file), nts::Error);
}

Test(NanoTekSpice, testBasicNanoTekSpice)
{
    nts::CircuitFile file("TestFile/NtsSingle/and.nts");
    nts::NanoTekSpice *nano = new nts::NanoTekSpice(file);

    cr_assert_not_null(nano);
}

Test(NanoTekSpice, testGetterInputNames)
{
    nts::CircuitFile file("TestFile/NtsSingle/and.nts");
    nts::NanoTekSpice nano(file);
    std::vector<std::string> inputNames = nano.getInputNames();

    cr_assert_eq(inputNames.size(), 2);
    cr_assert_str_eq(inputNames[0].c_str(), "in_1");
    cr_assert_str_eq(inputNames[1].c_str(), "in_2");
}

Test(NanoTekSpice, testDisplayFunction)
{
    nts::CircuitFile file("TestFile/NtsSingle/and.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 0\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testSimulateFunction)
{
    nts::CircuitFile file("TestFile/NtsSingle/and.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryXorComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/xor.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryNotComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/not.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryOrComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/or.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryNorComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/nor.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryNandComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/nand.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryAndComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/and.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryInputOutputComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/input_output.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryTrueComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/true.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\noutput(s):\n  out: 1\n");
}

Test(NanoTekSpice, testFactoryFalseComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/false.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\noutput(s):\n  out: 0\n");
}

Test(NanoTekSpice, testFactoryClockComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/clock.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  cl: U\noutput(s):\n  out: U\n");
}

Test(NanoTekSpice, testFactoryDFlipFlopComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/DFlipFlop.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  cl: U\n  data: U\n  reset: U\n  set: U\noutput(s):\n  q1: U\n  q2: U\n");
}

Test(NanoTekSpice, testFactoryFullAdderComponent)
{
    nts::CircuitFile file("TestFile/NtsSingle/FullAdder.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_1: U\n  in_2: U\n  in_3: U\noutput(s):\n  out_1: U\n  out_2: U\n");
}

Test(NanoTekSpice, testFactoryComponent4001)
{
    nts::CircuitFile file("TestFile/NtsSingle/4001_nor.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n");
}

Test(NanoTekSpice, testFactoryComponent4011)
{
    nts::CircuitFile file("TestFile/NtsSingle/4011_nand.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n");
}

Test(NanoTekSpice, testFactoryComponent4030)
{
    nts::CircuitFile file("TestFile/NtsSingle/4030_xor.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n");
}

Test(NanoTekSpice, testFactoryComponent4069)
{
    nts::CircuitFile file("TestFile/NtsSingle/4069_not.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_01: U\n  in_03: U\n  in_05: U\n  in_09: U\n  in_11: U\n  in_13: U\noutput(s):\n  out_02: U\n  out_04: U\n  out_06: U\n  out_08: U\n  out_10: U\n  out_12: U\n");
}

Test(NanoTekSpice, testFactoryComponent4071)
{
    nts::CircuitFile file("TestFile/NtsSingle/4071_or.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n");
}

Test(NanoTekSpice, testFactoryComponent4081)
{
    nts::CircuitFile file("TestFile/NtsSingle/4081_and.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_01: U\n  in_02: U\n  in_05: U\n  in_06: U\n  in_08: U\n  in_09: U\n  in_12: U\n  in_13: U\noutput(s):\n  out_03: U\n  out_04: U\n  out_10: U\n  out_11: U\n");
}

Test(NanoTekSpice, testFactoryComponent4008)
{
    nts::CircuitFile file("TestFile/NtsSingle/4008_adder.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_a1: U\n  in_a2: U\n  in_a3: U\n  in_a4: U\n  in_b1: U\n  in_b2: U\n  in_b3: U\n  in_b4: U\n  in_c: U\noutput(s):\n  out_0: U\n  out_1: U\n  out_2: U\n  out_3: U\n  out_c: U\n");
}

Test(NanoTekSpice, testFactoryComponent4013)
{
    nts::CircuitFile file("TestFile/NtsSingle/4013_flipflop.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  cl_1_clock: U\n  cl_2_clock: U\n  in_1_data: U\n  in_1_reset: U\n  in_1_set: U\n  in_2_data: U\n  in_2_reset: U\n  in_2_set: U\noutput(s):\n  out_1_q: U\n  out_1_qb: U\n  out_2_q: U\n  out_2_qb: U\n");
}

Test(NanoTekSpice, testFactoryComponent4017)
{
    nts::CircuitFile file("TestFile/NtsSingle/4017_johnson.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    // cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_0: U\n  in_1: U\n  in_r: U\noutput(s):\n  out_0: U\n  out_1: U\n  out_2: U\n  out_3: U\n  out_4: U\n  out_5: U\n  out_6: U\n  out_7: U\n  out_8: U\n  out_9: U\n  out_s: U\n");
    // TODO : Fix this test
}

Test(NanoTekSpice, testFactoryComponent4040)
{
    nts::CircuitFile file("TestFile/NtsSingle/4040_counter.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    // cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  in_0: U\n  in_1: U\n  in_2: U\n  in_3: U\n  in_4: U\n  in_5: U\n  in_6: U\n  in_7: U\n  in_8: U\n  in_9: U\n  in_10: U\n  in_11: U\n  in_12: U\n  in_13: U\n  in_14: U\n  in_15: U\noutput(s):\n  out_0: U\n  out_1: U\n  out_2: U\n  out_3: U\n  out_4: U\n  out_5: U\n  out_6: U\n  out_7: U\n  out_8: U\n  out_9: U\n  out_10: U\n  out_11: U\n  out_12: U\n  out_13: U\n  out_14: U\n  out_15: U\n");
    // TODO : Fix this test
}

Test(NanoTekSpice, testFactoryComponent4094)
{
    nts::CircuitFile file("TestFile/NtsSingle/4094_shift.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  clock: U\n  data: U\noutput(s):\n  out_0: U\n  out_1: U\n  out_2: U\n  out_3: U\n  out_4: U\n  out_5: U\n  out_6: U\n  out_7: U\n  out_qe: U\n  out_qs: U\n");
}

Test(NanoTekSpice, testFactoryComponent4512)
{
    nts::CircuitFile file("TestFile/NtsSingle/4512_selector.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  enable: U\n  in_0: U\n  in_1: U\n  in_2: U\n  in_3: U\n  in_4: U\n  in_5: U\n  in_6: U\n  in_7: U\n  in_a: U\n  in_b: U\n  in_c: U\n  inhibit: U\noutput(s):\n  out_data: U\n");
}

Test(NanoTekSpice, testFactoryComponent4514)
{
    nts::CircuitFile file("TestFile/NtsSingle/4514_decoder.nts");
    nts::NanoTekSpice nano(file);

    cr_redirect_stdout();
    nano.simulate();
    nano.display();
    std::fflush(stdout);
    // cr_assert_stdout_eq_str("tick: 1\ninput(s):\n  enable: U\n  inhibit: U\n  in_0: U\n  in_1: U\n  in_2: U\n  in_3: U\n  in_4: U\n  in_5: U\n  in_6: U\n  in_7: U\noutput(s):\n  out_0: U\n  out_1: U\n  out_2: U\n  out_3: U\n  out_4: U\n  out_5: U\n  out_6: U\n  out_7: U\n");
    // TODO : Fix this test
}
