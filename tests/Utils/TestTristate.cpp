/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestTristate
*/

#include "Utils/Tristate.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Tristate, testTristateOutputOp1)
{
    nts::Tristate tristate = nts::Tristate::Undefined;

    cr_redirect_stdout();
    std::cout << tristate;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("U");
}

Test(Tristate, testTristateOutputOp2)
{
    nts::Tristate tristate = nts::Tristate::True;

    cr_redirect_stdout();
    std::cout << tristate;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("1");
}

Test(Tristate, testTristateOutputOp3)
{
    nts::Tristate tristate = nts::Tristate::False;

    cr_redirect_stdout();
    std::cout << tristate;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("0");
}

Test(Tristate, testTristateStringConcatenationOp1)
{
    nts::Tristate tristate = nts::Tristate::Undefined;
    std::string str = "Test : ";

    cr_redirect_stdout();
    str = str + tristate;
    std::cout << str;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("Test : U");
}

Test(Tristate, testTristateStringConcatenationOp2)
{
    nts::Tristate tristate = nts::Tristate::True;
    std::string str = "Test : ";

    cr_redirect_stdout();
    str = str + tristate;
    std::cout << str;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("Test : 1");
}

Test(Tristate, testTristateStringConcatenationOp3)
{
    nts::Tristate tristate = nts::Tristate::False;
    std::string str = "Test : ";

    cr_redirect_stdout();
    str = str + tristate;
    std::cout << str;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("Test : 0");
}
